#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
int main() {
	cv::Mat img = cv::imread("picture.png", cv::IMREAD_COLOR);
	cv::Mat resized;
	int new_width = 736;
	int new_height = 736;
	if(img.empty()) {
		std::cerr << "Cannot load image\n";
		return -1;
	}
	/*int x = 84, y = 84, width = 100, height = 100;
	cv::Mat cropper = img(cv::Rect(x,y,width,height));*/
	//cv::resize(img,resized, cv::Size(new_width, new_height));
	double angle = 45.0;
	cv::Point2f center(100, 50);
	cv::Mat rotation_matrix = cv::getRotationMatrix2D(center, angle, 1.0);
	cv::Mat rotated;
	cv::warpAffine(img, rotated, rotation_matrix, img.size());
	cv::imshow("Takumi Fujiwara from Initial D", rotated);
	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}
