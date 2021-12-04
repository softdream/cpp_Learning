#include<opencv2/opencv.hpp>
#include<iostream>
#include <vector>
#include <cmath>

cv::Mat img1 = cv::Mat::zeros(600, 600, CV_8UC3);

void operate(int x, int y, cv::Mat &img)
{
	std::cout << "(x, y) = ( " << x << ", " << y << " )" << std::endl;
	cv::circle(img, cv::Point( x, y ), 1, cv::Scalar(0, 0, 255), 1);
}

void bresenHam(int x0, int y0, int x1, int y1)
{
	int dx = ::abs( x1 - x0 );
	int dy = ::abs( y1 - y0 );

	bool interChange = false;

	int e = -dx;

	int signX = x1 > x0 ? 1 : ( ( x1 < x0 ) ? -1 : 0 );
	int signY = y1 > y0 ? 1 : ( ( y1 < y0 ) ? -1 : 0 );

	if (dy > dx) {
		int temp = dx;
		dx = dy;
		dy = temp;
		interChange = true;
	}

	int x = x0, y = y0;
	for (int i = 0; i < dx; i++) {
		operate( x, y, img1 );
		if (!interChange)
			x += signX;
		else
			y += signY;

		e += 2 * dy;

		if (e >= 0) {
			if (!interChange)
				y += signY;
			else
				x += signX;

			e -= 2 * dx;
		}
	}
}

int main(int agrc, char** agrv)
{
	bresenHam(200, 200, 350, 244);
	
	cv::imshow("»­²¼", img1);

	cv::waitKey(0);
	return 1;
}