#include <QDebug>
#include <QStandardPaths>
#include <QObject>

class LogManager: public QObject
{
public:
	LogManager(QString appName = "stackovermemes", QString logPath = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation),
		QObject* parent = nullptr);
	~LogManager();

private:
	static void messageHandler(const QtMsgType type, const QMessageLogContext& context, const QString& message);

	//QString m_logPath;
};