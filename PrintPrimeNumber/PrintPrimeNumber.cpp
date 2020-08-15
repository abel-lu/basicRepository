// AlignmentCorrection.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	cv::Mat srcImage = cv::imread("E:\\素材\\形态学图片\\lena_rot.jpg");
	cv::Mat result, result1;
	if (srcImage.empty()) {
		return -1;
	}
	cv::imshow("src", srcImage);			//打印原图
	int height = srcImage.rows;		//行数，即图片的高
	int width = srcImage.cols;		//列数，即图片的宽
	int temp = 255;
	int point[4] = { 0 };

	for (int i = 0; i < width; i++)
	{
		if (int(srcImage.at<Vec3b>(i, 0)[0]) <= temp)
		{
			temp = int(srcImage.at<Vec3b>(i, 0)[0]);
			point[0] = i;
		}
	}
	temp = 255;
	for (int i = 0; i < height; i++)
	{
		if (int(srcImage.at<Vec3b>(width - 1, i)[0]) <= temp)
		{
			temp = int(srcImage.at<Vec3b>(width - 1, i)[0]);
			point[1] = i;
		}
	}
	temp = 255;
	for (int i = 0; i <width; i++)
	{
		if (int(srcImage.at<Vec3b>(i, height - 1)[0]) <= temp)
		{
			temp = int(srcImage.at<Vec3b>(i, height - 1)[0]);
			point[2] = i;
		}
	}
	temp = 255;
	for (int i = 0; i < height; i++)
	{
		if (int(srcImage.at<Vec3b>(0, i)[0]) <= temp)
		{
			temp = int(srcImage.at<Vec3b>(0, i)[0]);
			point[3] = i;
		}
	}
	//变换前的四点坐标
	cv::Point2f src4coord[] = { cv::Point2f(point[3],0),
		cv::Point2f(width,point[2]),
		cv::Point2f(point[1],height),
		cv::Point2f(0,point[0]) };
	//变换后的四点坐标
	cv::Point2f res4coord[] = { cv::Point2f(0,0),
		cv::Point2f(width,0),
		cv::Point2f(width,height),
		cv::Point2f(0,height) };
	cv::Mat perspective_matrix = cv::getPerspectiveTransform(src4coord, res4coord);
	cv::warpPerspective(srcImage, result, perspective_matrix, srcImage.size());
	cv::imshow("result", result);
	cv::waitKey(0);
	return 0;
}

