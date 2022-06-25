#include "vkmanager.h"
#include <iostream>
#include <QtNetwork>
#include <QFile>
#include <QJsonObject>
#include <QSslConfiguration>
#include <QDebug>


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
	m_sslConfig.setDefaultConfiguration(QSslConfiguration::defaultConfiguration());
	m_sslConfig.setProtocol(QSsl::TlsV1_2);
	
	m_request.setSslConfiguration(m_sslConfig);
	m_request.setAttribute(QNetworkRequest::FollowRedirectsAttribute, true);
	m_request.setUrl(QUrl(
		"https://api.vk.com/method/wall.get?access_token=2b76a3112b76a3112b76a311072b0ba17722b762b76a31149d18e477ded495e50a50d74&v=5.131&domain=baboon228"));
	
	m_manager->get(m_request);
	qDebug() << "Request sent";
}

void VkManager::replyFinished(QNetworkReply* response)
{
	QFile replyFile("../../Response.txt");
	replyFile.open(QIODevice::WriteOnly);
	replyFile.write(response->readAll());
	replyFile.close();
	qDebug() << "Created a file with response:" << replyFile.fileName();
	response->deleteLater();
}

void VkManager::dataParse()
{
	
}