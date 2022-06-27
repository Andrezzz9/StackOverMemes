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


// Функция, ответственная за отправку запроса к ВКонтакте
void VkManager::getData()
{
	// Конфигурация протокола SSL
	m_sslConfig.setDefaultConfiguration(QSslConfiguration::defaultConfiguration());
	m_sslConfig.setProtocol(QSsl::TlsV1_2);
	
	// Настройка параметров запроса
	m_request.setSslConfiguration(m_sslConfig);
	m_request.setAttribute(QNetworkRequest::FollowRedirectsAttribute, true);
	m_request.setUrl(QUrl(
		"https://api.vk.com/method/wall.get?access_token=2b76a3112b76a3112b76a311072b0ba17722b762b76a31149d18e477ded495e50a50d74&v=5.131&domain=baboon228"));
	
	// Запрос
	m_manager->get(m_request);
	
	qDebug() << "Запрос отправлен";
}


// Функция, ответственная за сохранение ответа на запрос в файл
void VkManager::replyFinished(QNetworkReply* response)
{
	// Создание файла и запись в него ответа
	QFile replyFile("../../Response.txt");
	replyFile.open(QIODevice::WriteOnly);
	replyFile.write(response->readAll());
	replyFile.close();
	
	qDebug() << "Created a file with response:" << replyFile.fileName();
	
	response->deleteLater();
}


// Функция, ответственная за парсинг полученных данных
void VkManager::dataParse()
{
	
}