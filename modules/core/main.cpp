#include <QString>
#include <iostream>
#include "logmanager.h"
#include "vkmanager.h"
#include "memevisor.h"

using namespace std;

int main(int argc, char** argv)
{
	std::cout << "Hello, World!" << std::endl;

	MemeVisor visor;
	visor.test();

	return 0;
}