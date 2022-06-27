#include "logmanager.h"

#include <iostream>
#include <QDateTime>
#include <QString>
#include <QFile>
#include <QDir>
#include <QTextCodec>

using namespace std;

QString m_logPath;

LogManager::LogManager(QString appName, QString logPath, QObject* parent): QObject(parent)
{
    // Формирование названия файла
    QDateTime dateTime = QDateTime::currentDateTime();
    QString fileName = QString("log_%1_%2.txt").arg(appName).arg(dateTime.toString("dd-MM-yyyy-hh-mm-ss"));

    // Полный путь до файла
    QString filePath = QString("%1/%2").arg(logPath).arg(fileName);

    QDir dir;
    if (!dir.mkpath(logPath))
    {
        qWarning() << "Не удалось создать директорию для записи логов. Логгирования не происходит";
        return;
    }

    // Проверка на валидность
    QFile logFile(filePath);
    if (!logFile.open(QIODevice::WriteOnly | QIODevice::Append))
        qWarning() << "Не удалось создать файл для записи логов. Логгирования не происходит";
    else
    {
        m_logPath = filePath;
        qInstallMessageHandler(messageHandler);
        logFile.close();
        cout << QString("Файл с логом: %1").arg(QFileInfo(logFile).absoluteFilePath()).toLocal8Bit().data() << endl;
    }
}

LogManager::~LogManager()
{
}

void LogManager::messageHandler(const QtMsgType type, const QMessageLogContext& context, const QString& message)
{
    QString txt;
    // Название функции с классом, берём только класс и саму функцию
    QRegExp rx("([\\w-]+::[\\w-]+)");
    //if (rx.indexIn(context.function) == -1) return;
    QString function = rx.cap(1);
    QString msgSep = (message.length() > 0) ? ">> " : "";

    switch (type) {
    case QtInfoMsg:
        txt = QString("Info: %1%2%3").arg(function).arg(msgSep).arg(message);
        break;
    case QtDebugMsg:
        txt = QString("Debug: %1%2%3").arg(function).arg(msgSep).arg(message);
        break;
    case QtWarningMsg:
        txt = QString("Warning: %1%2%3").arg(function).arg(msgSep).arg(message);
        break;
    case QtCriticalMsg:
        txt = QString("Critical: %1%2%3").arg(function).arg(msgSep).arg(message);
        break;
    case QtFatalMsg:
        txt = QString("Fatal: %1%2%3").arg(function).arg(msgSep).arg(message);
        abort();
        break;
    }

    // Конечное сообщение
    QDateTime dateTime = QDateTime::currentDateTime();
    txt = QString("%1: %3").arg(dateTime.toString(Qt::ISODate)).arg(txt);

    // Вывод в консоль
    cout << txt.toLocal8Bit().data() << endl;

    // Вывод в файл
    if(m_logPath.isEmpty())
        return;
    QFile outFile(m_logPath);
    if (outFile.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        QTextStream ts(&outFile);
            ts.setCodec(QTextCodec::codecForName("UTF-8"));
            ts << txt << endl;
            outFile.close();
    }
}