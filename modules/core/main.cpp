#include "logmanager.h"
#include "vkmanager.h"
#include "memevisor.h"
#include <QCoreApplication>
#include <QScopedPointer>
#include <QTextCodec>
#include <iostream>


using namespace std;

int main(int argc, char** argv)
{
	QScopedPointer<QCoreApplication> app = QScopedPointer(new QCoreApplication(argc, argv));
	
	#ifdef Q_OS_WIN32
	//setlocale(LC_ALL, "rus");
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif
#ifdef Q_OS_LINUX
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
	// РРЅРёС†РёР°Р»РёР·Р°С†РёСЏ Р»РѕРіР°
	LogManager log;

	// Инициализация сборщика
	VkManager dataCollector;
	dataCollector.get;
	
	// Инициализация парсера данных
	VkManager dataParser;
	dataParser.dataParse();

	qDebug() << "РћР“Рћ! Р”РµР±Р°Рі!";
	qWarning() << " ~~ test РїСЂРµРґСѓРїСЂРµР¶РґРµРЅРёРµ";

	return app->exec();
}