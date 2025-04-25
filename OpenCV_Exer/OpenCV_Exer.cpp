#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void colorinvert(Mat& image);

void grayScaleInvert(Mat& image);

void printMat(InputArray _mat) {
	Mat mat = _mat.getMat();
	cout << mat << endl;
}

int main()
{

	uchar _data[] = { 1,2,3,4,5,6 };
	Mat mat1(2, 3, CV_8U, _data);
	printMat(mat1);

	vector<float> vec1 = { 1.2f,3.4f,-2.1f };
	printMat(vec1);
	/*
	VideoCapture video("car.avi");
	
	if (!video.isOpened()) {
		cout << "비디오 안열림";
		return -1;
	}
	
	Mat frame;

	while (true) {
		video >> frame;
		if (frame.empty())
			break;
		imshow("Video Player", frame);

		if (waitKey(20) >= 0) break;
	}

	video.release();
	destroyAllWindows();
	//여까지 하고 아래 주석
	
	Mat src = imread("koksi9972.jpg", IMREAD_UNCHANGED);
	Mat dst;
	Mat onemore;
	Mat sub;
	cvtColor(src, dst, COLOR_BGR2GRAY);
	cvtColor(src, onemore, COLOR_BGR2HSV);
	subtract(onemore, src, sub);
	imshow("koksi9972_origin", src);
	imshow("koksi9972_dest", dst);
	imshow("koksi9972_winter", onemore);
	imshow("subtract", sub);
	//imshow("koksi9972", dst);
	waitKey();
	
	*/
}

void colorinvert(Mat& image)
{
	int numOfLines = image.rows;
	int numOfPixels = image.cols;

	for (int r = 0; r < numOfLines; r++) {
		for (int c = 0; c < numOfPixels; c++) {
			Vec3b& vec = image.at<Vec3b>(r, c);
			vec[0] = 255 - vec[0];
			vec[1] = 255 - vec[1];
			vec[2] = 255 - vec[2];
		}
	}
}

void grayScaleInvert(Mat& image)
{
	int numOfLines = image.rows;
	int numOfPixels = image.cols;

	for (int r = 0; r < numOfLines; r++) {
		for (int c = 0; c < numOfPixels; c++) {
			uchar& value = image.at<uchar>(r, c);
			value = 255 - value;
		}
	}
}


