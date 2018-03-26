#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int Lab2_2() {
	double alpha = 0.0;
	int width = 0, height = 0;
	string imageName1("C:/Users/yge30/Desktop/aa.jpg");
	string imageName2("C:/Users/yge30/Desktop/bb.jpg");

	Mat src1;
	Mat src2;
	Mat dst;

	src1 = imread(imageName1.c_str(), IMREAD_COLOR);
	if (src1.empty()) {
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	src2 = imread(imageName2.c_str(), IMREAD_COLOR);
	if (src2.empty()) {
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	width = src1.cols;
	height = src1.rows;

	dst = Mat::zeros(src1.size(), src1.type());
	cin >> alpha;

	//addWeighted(src1, alpha, src2, 1 - alpha, 0.0, dst);


	for (int h = 0; h < height; h++) {
		for(int w=0; w<width; w++){
			for (int rgb = 0; rgb < 3; rgb++) {
				dst.at<Vec3b>(h,w)[rgb] = saturate_cast<uchar>(alpha * src1.at<Vec3b>(h,w)[rgb] + (1 - alpha)*src2.at<Vec3b>(h,w)[rgb]);
			}
		}
	}


	namedWindow("Display window", WINDOW_AUTOSIZE);
	imshow("Display window", dst);
	waitKey(0);
	return 0;

}
