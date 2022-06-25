#include "vkmanager.h"
#include <iostream>
#include <QtNetwork>
#include <QFile>
#include <QSslConfiguration>


VkManager::VkManager(QObject* parent): QObject(parent)
{
	m_manager = new QNetworkAccessManager();
	connect(m_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}

VkManager::~VkManager()
{
}


void VkManager::getData()
{
	QSslConfiguration SslConfig;
	QNetworkRequest request;
	
	SslConfig.setDefaultConfiguration(QSslConfiguration::defaultConfiguration());
	SslConfig.setProtocol(QSsl::TlsV1_2);
	
	request.setSslConfiguration(SslConfig);
	request.setAttribute(QNetworkRequest::FollowRedirectsAttribute, true);
	request.setUrl(QUrl(
		"https://api.vk.com/method/wall.get?access_token=2b76a3112b76a3112b76a311072b0ba17722b762b76a31149d18e477ded495e50a50d74&v=5.131&domain=baboon228"));
	//request.setUrl(QUrl("https://www.google.com/"));
	
	m_manager->get(request);
}

void VkManager::replyFinished(QNetworkReply* response)
{
	QFile replyFile("../../Reply.txt");
	replyFile.open(QIODevice::WriteOnly);
	replyFile.write(response->readAll());
	replyFile.close();
	response->deleteLater();
}