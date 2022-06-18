#include "memevisor.h"
#include <QString>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

MemeVisor::MemeVisor()
{
}

MemeVisor::~MemeVisor()
{
}

void MemeVisor::test()
{
	std::string path = "C:/Qt/Projects/ImageViewer/Test Image.jpg";
	Mat img = imread(path);

	while (true) {
		imshow("test", img);
		waitKey(1);
	}
}
