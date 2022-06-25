#include "logmanager.h"
#include "vkmanager.h"
#include "memevisor.h"
#include <QCoreApplication>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	QCoreApplication app(argc, argv);

	// Инициализация сборщика данных
	VkManager dataCollector;
	dataCollector.getData();
	
	// Инициализация парсера данных
	VkManager dataParser;
	dataParser.dataParse();

	return app.exec();
}