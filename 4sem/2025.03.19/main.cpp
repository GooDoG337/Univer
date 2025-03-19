#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

int main() {
/*    cv::VideoCapture video("videoplayback.mp4");
    if (!video.isOpened()) {
        std::cerr << "Cannot open video\n";
        return -1;
    }
    cv::Mat frame;
    while (video.read(frame)) {
        cv::imshow("Baka Mitai", frame);
        if (cv::waitKey(1) == 'q') {
            break;
        }
    }
    video.release();
    cv::destroyAllWindows();
    return 0;*/

    //cv::Mat image(500, 500, CV_8UC3, cv::Scalar(255,255,255));
    cv::Mat image = imread("/home/stud-8/Petrov/Univer/4sem/2025.03.19/cmake-build-debug/picture.jpg", cv::IMREAD_GRAYSCALE);
    if (!image.data) {
        std::cerr << "Cannot create image\n";
        return -1;
    }
    cv::Point p1(30,30);
    cv::Point p2(255,255);
    int thickness = -1;
    cv::rectangle(image, p1, p2, cv::Scalar(0, 255,0), thickness, cv::LINE_8); //BGR?
    cv::circle(image, p1, 30, cv::LINE_8);
    cv::imshow("Output", image);
    cv::waitKey(0);
    return 0;
}