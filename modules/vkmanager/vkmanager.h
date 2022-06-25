#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QObject>
#include <QString>


class VkManager: public QObject 
{
Q_OBJECT
public:
	VkManager(QObject *parent = nullptr);
	~VkManager();

	void getData();

public slots:
	void replyFinished(QNetworkReply* reply);

private:
	QNetworkAccessManager* m_manager;
	QNetworkRequest m_request;
};