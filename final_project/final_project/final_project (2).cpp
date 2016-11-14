#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp> 


int main(int argc, char **argv)
{

	// Create a container
	cv::Mat im;

	//Create a vector
	cv::Vec3b *vec;

	// Create an mat iterator
	cv::MatIterator_<cv::Vec3b> it;

	// Read the image in color format
	im = cv::imread("orig1.jpg", 1);

	// iterate through each pixel
	for (it = im.begin<cv::Vec3b>(); it != im.end<cv::Vec3b>(); ++it)
	{
		// Erase the green and red channels 
		(*it)[1] = 0;
		(*it)[2] = 0;
	}

	// Create a new window
	cv::namedWindow("Resulting Image");

	// Show the image
	cv::imshow("Resulting Image", im);

	// Wait for a key
	cv::waitKey(0);

	return 0;
}

	