#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QSslConfiguration>
#include <QObject>
#include <QString>
#include <QFile>

/*
	\brief Класс, отвечающий за реализацию получения данных от ВКонтакте

	Данный класс реализует методы взаимодействия с API ВКонтакте, парсинг
	данных, полученных в ответе на запрос, а также сохранение этих данных
*/
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