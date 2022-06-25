#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QSslConfiguration>
#include <QObject>
#include <QString>
#include <QFile>


class VkManager: public QObject 
{
Q_OBJECT
public:
	VkManager(QObject *parent = nullptr);
	~VkManager();

	void getData();
	void dataParse();

public slots:
	void replyFinished(QNetworkReply* reply);

private:
	QNetworkAccessManager* m_manager;
	QNetworkRequest m_request;
	QSslConfiguration m_sslConfig;
};