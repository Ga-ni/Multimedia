#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int Lab2_1() {
	string imageName("C:/Users/yge30/Desktop/»õ Æú´õ/a.jpg");
	//if (argc > 1) {
	//	imageName = argv[1];
	//}

	Mat image;
	image = imread(imageName.c_str(), IMREAD_COLOR);
	if (image.empty()) {
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	Mat color_img = Mat::zeros(image.size(), image.type());
	int blue = 0, green = 0, red = 0;
	int cont = 1;
	int bright = 0;
	int w = image.cols;
	int h = image.rows;

	//scanf_s("%c %c", &cont, &bright);
	std::cin >> cont;
	std::cin >> bright;

	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			blue = image.at<Vec3b>(i, j)[0] * cont + bright;
			green = image.at<Vec3b>(i, j)[1] * cont + bright;
			red = image.at<Vec3b>(i, j)[2] * cont + bright;
			color_img.at<Vec3b>(i, j)[0] = saturate_cast<uchar>(blue);
			color_img.at<Vec3b>(i, j)[1] = saturate_cast<uchar>(green);
			color_img.at<Vec3b>(i, j)[2] = saturate_cast<uchar>(red);
		}
	}
	namedWindow("Display window", WINDOW_AUTOSIZE);
	imshow("Display window", color_img);
	waitKey(0);
	return 0;
}
