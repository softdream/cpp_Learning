#include<opencv2/opencv.hpp>
#include<iostream>
#include <vector>

#define RADIUS_BIAS 20
#define SHIFT_BIAS 10

std::vector<cv::Mat> roiVec;

// 1 初始化特征点和描述子,ORB
std::vector<cv::KeyPoint> keypoints1, keypoints2;
cv::Mat descriptors1, descriptors2;
cv::Ptr<cv::ORB> orb = cv::ORB::create();


void imageTemplateORB(cv::Mat &src)
{
	//灰度化
	cv::Mat gray_img_template;
	cvtColor(src, gray_img_template, cv::COLOR_BGR2GRAY);

	//阈值分割
	cv::Mat thresh_img_template;
	threshold(gray_img_template, thresh_img_template, 0, 255, cv::THRESH_OTSU);
	cv::imshow("threshold: ", thresh_img_template);

	orb->detect( src, keypoints1);

	orb->compute(src, keypoints1, descriptors1);
}


int main(int agrc, char** agrv)
{
	cv::Mat temp = cv::imread("1.jpg");
	//ImageTemplateContours( temp );
	imageTemplateORB( temp );

	cv::Mat src1, dst;
	src1 = cv::imread("3.jpg");
	cv::resize(src1, src1, cv::Size(600, 600));
	//cv::imshow("原图", src1);

	cv::cvtColor(src1, dst, cv::COLOR_BGR2HSV);
	//cv::imshow( "HSV", dst );

	//直方图均衡化
	std::vector<cv::Mat> hsvSplit;
	cv::split(dst, hsvSplit);
	cv::equalizeHist(hsvSplit[2], hsvSplit[2]);
	cv::merge(hsvSplit, dst);
	//cv::imshow("均衡化", dst);

	cv::Mat imgThresholded;
	cv::inRange(dst, cv::Scalar(160, 80, 50), cv::Scalar(180, 255, 220), imgThresholded); //Threshold the image
	//cv::imshow( "颜色提取1",imgThresholded );

	//开操作 (去除一些噪点)
	cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(2, 2));
	cv::morphologyEx(imgThresholded, imgThresholded, cv::MORPH_OPEN, element);

	//cv::imshow("颜色提取2", imgThresholded);
	//闭操作 (连接一些连通域)
	cv::morphologyEx(imgThresholded, imgThresholded, cv::MORPH_CLOSE, element);
	//cv::imshow("颜色提取3", imgThresholded);

	cv::Mat cannyImg;
	cv::Canny(imgThresholded, cannyImg, 10, 250, 5);
	//cv::imshow( "边缘提取", cannyImg);

	std::vector<cv::Vec3f> circles;

	cv::HoughCircles(cannyImg, circles, cv::HOUGH_GRADIENT, 1, 30, 100, 20, 80, 120);

	std::cout << "circels size = " << circles.size() << std::endl;

	for (size_t i = 0; i < circles.size(); i++)
	{
		cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		//绘制圆心  
		//cv::circle(src1, center, 3, cv::Scalar(0, 255, 0), -1, 8, 0);
		//绘制圆轮廓  
		//cv::circle(src1, center, radius, cv::Scalar(155, 50, 255), 3, 8, 0);

		//rect = Rect(center.x - radius, center.y - radius, 2 * radius, 2 * radius);
		cv::Mat imgROI = src1(cv::Rect(center.x - radius + SHIFT_BIAS, center.y - radius + SHIFT_BIAS, 2 * radius - RADIUS_BIAS, 2 * radius - RADIUS_BIAS));
		//cv::imshow(std::to_string(i + 10), imgROI);
		roiVec.push_back(imgROI);
	}

	//cv::imshow("提取圆", src1);

	for (size_t i = 0; i < roiVec.size(); i++) {
		cv::Mat grayImage;
		cv::cvtColor(roiVec[i], grayImage, cv::COLOR_BGR2GRAY);
		//cv::imshow( std::to_string(i), grayImage);

		cv::blur(grayImage, grayImage, cv::Size(3, 3));
		//cv::imshow(std::to_string(i), grayImage);

		cv::threshold(grayImage, grayImage, 0, 255, cv::THRESH_OTSU);//大津法进行图像二值化

		//cv::Canny(grayImage, grayImage, 3, 9, 3);
		//cv::imshow(std::to_string(i), grayImage);

		std::vector<std::vector<cv::Point>> contours;
		std::vector<cv::Vec4i> hierarchy;
		findContours(grayImage, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE, cv::Point(0, 0));
		std::cout << "contours size ===== " << contours.size() << std::endl;

		/*cv::RNG rng(0);
		for (int j = 0; j < contours.size(); j++){
			cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
			cv::drawContours(grayImage, contours, j, color, 4, 8, hierarchy, 0, cv::Point(0, 0));
		}*/
		cv::imshow(std::to_string(i), grayImage);
			
		orb->detect(grayImage, keypoints2);
		orb->compute(grayImage, keypoints2, descriptors2);

		std::vector<cv::DMatch> matches;
		cv::BFMatcher bfmatcher(cv::NORM_HAMMING);
		bfmatcher.match(descriptors1, descriptors2, matches);

		double min_dist = 1000, max_dist = 20;
		// 找出所有匹配之间的最大值和最小值
		for (int i = 0; i < descriptors1.rows; i++)
		{
			double dist = matches[i].distance;//汉明距离在matches中
			if (dist < min_dist) min_dist = dist;
			if (dist > max_dist) max_dist = dist;
		}
		// 当描述子之间的匹配大于2倍的最小距离时，即认为该匹配是一个错误的匹配。
		// 但有时描述子之间的最小距离非常小，可以设置一个经验值作为下限
		std::vector<cv::DMatch> good_matches;
		for (int i = 0; i < descriptors1.rows; i++)
		{
			if (matches[i].distance <= cv::max(2 * min_dist, 30.0))
				good_matches.push_back(matches[i]);
		}

		// 6 绘制匹配结果
		cv::Mat img_match;
		drawMatches(temp, keypoints1, roiVec[i], keypoints2, good_matches, img_match);

		cv::imshow("match"+std::to_string(i), img_match);

		std::cout << "------------------------------" << std::endl;
	}

	cv::waitKey(0);
	return 1;
}