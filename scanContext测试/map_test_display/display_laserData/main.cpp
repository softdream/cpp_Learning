#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

#include<stdio.h>
#include<stdlib.h>

#include <Windows.h>

#define M_PI 3.141592653

#define NUM_RING 20
#define NUM_SECTOR 60

void drawABin(cv::Mat &image,  int ring_idx, const int sctor_idx)
{
	float angleStart1 = (sctor_idx ) * 6 * M_PI / 180;
	float radiusStart1 = (ring_idx ) * 30;
	float angleStart2 = (sctor_idx + 1) * 6 * M_PI / 180;
	float radiusStart2 = (ring_idx + 1) * 30;

	std::vector<std::vector<cv::Point>> ppPoints;
	std::vector<cv::Point> pPoints;

	for (int i = 0; i <= 6; i++) {
		cv::Point p( 600 - radiusStart1 * sin(angleStart1 + i * 0.017453293),
					   600 - radiusStart1 * cos(angleStart1 + i * 0.017453293));
		pPoints.push_back( p );
	}

	for (int i = 0; i <= 6; i++) {
		cv::Point p( 600 - radiusStart2 * sin( angleStart2 - i * 0.017453293),
					   600 - radiusStart2 * cos( angleStart2 - i * 0.017453293));
		pPoints.push_back( p );
	}

	ppPoints.push_back( pPoints );

	/*for (auto it : pPoints) {
		cv::circle(image, it, 3, cv::Scalar(0, 0, 255), -1);
		cv::imshow("scan distribution", image);
		cv::waitKey(2000);
	}*/

	cv::fillPoly( image, ppPoints, cv::Scalar( 0, 0, 255 ) );

}

void displayScanDistribution(  )
{
	cv::Mat image = cv::Mat::zeros(1200, 1200, CV_8UC3);

	for (int i = 0; i < NUM_RING; i++) {
		cv::circle(image, cv::Point(600, 600), 30 * (i + 1), cv::Scalar(0, 255, 0), 1);
	}

	for (int i = 0; i < NUM_SECTOR; i++) {
		float angle = (6 * i);

		cv::Point endPoint(600 - ::sin(angle * M_PI / 180) * 600,
			600 - ::cos(angle * M_PI / 180) * 600);
		cv::line(image, cv::Point(600, 600), endPoint, cv::Scalar(0, 255, 0), 1);
	}

	cv::arrowedLine(image, cv::Point(600, 1200), cv::Point(600, 0), cv::Scalar(255, 0, 0), 1);
	cv::arrowedLine(image, cv::Point(0, 600), cv::Point(1200, 600), cv::Scalar(255, 0, 0), 1);


	int ring_idx = 0, sctor_idx = 0;
	float radians = -3.14159f;

	drawABin( image, 0, 0 );

	cv::imshow("scan distribution", image);
}


int main()
{
	displayScanDistribution();

	cv::waitKey(0);
	return 0;
}