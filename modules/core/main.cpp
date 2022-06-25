#include "logmanager.h"
#include "vkmanager.h"
#include "memevisor.h"
#include <QCoreApplication>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	QCoreApplication app(argc, argv);

	VkManager dataCollector;
	dataCollector.getData();
	
	return app.exec();
}