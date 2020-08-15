// calcaPixelAverage.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;

//将彩色图像转化为灰度图
//void grayimage(cv::Mat srcMat)
//{
//	int height = srcMat.rows;		//行数，即图片的高
//	int width = srcMat.cols;		//列数，即图片的宽
//	//遍历像素点；
//	for (int j = 0; j < height; j++)
//	{
//		for (int i = 0; i < width; i++)
//		{
//			//加权平均法求灰度值；人眼对绿色最敏感，对蓝色敏感最低
//			uchar gray = srcMat.at<Vec3b>(j, i)[0]*0.114 + srcMat.at<Vec3b>(j, i)[1]*0.587 + srcMat.at<Vec3b>(j, i)[2]*0.299;
//			srcMat.at<Vec3b>(j, i)[0] = gray;
//			srcMat.at<Vec3b>(j, i)[1] = gray; 
//			srcMat.at<Vec3b>(j, i)[2] = gray;
//		}
//	}
//}

int OTSU(cv::Mat &srcMat)
{
	int height = srcMat.rows;			//行数，即图片的高
	int width = srcMat.cols;			//列数，即图片的宽	
	int threshold1 = 0;					//阈值
	double w1 = 0;						//前景、背景、以及总的像素数
	double w2 = 0;
	double W = 0;
	double PgraySum = 0;				//前景和背景的灰度总值	
	double QgraySum = 0;
	double u1 = 0;
	double u2 = 0;
	double U = 0;
	double m = 0;
	double mmax = 0;			//前景、背景、以及总的像素均值;类间方差分子

	for (int t = 0; t <= 255; t++)		//遍历0~255灰度级，找最佳阈值
	{
		for (int j = 0; j < height; j++)
		{
			for (int i = 0; i < width; i++)
			{
				if (int(srcMat.at<uchar>(j, i)) >= t)
				{
					w1 += 1;
					PgraySum += srcMat.at<uchar>(j, i);	//p前景分布的总灰度值
				}
				else
				{
					w2 += 1;
					QgraySum += srcMat.at<uchar>(j, i);	//q背景分布的总灰度值
				}
			}
		}
		if (w1*w2 != 0)     //防止计算时分母为0（前景或背景像素数为0时）
		{
			//p,q均值；类间方差分子
			u1 = PgraySum / w1;
			u2 = QgraySum / w2;
			m = w1*w2*(u1 - u2)*(u1 - u2);
			//每次循环后清零
			PgraySum = 0;
			QgraySum = 0;
			w1 = 0;
			w2 = 0;
		}
		if (m >= mmax)				//判断最大的类间方差，
		{
			mmax = m;
			threshold1 = t;
		}
	}
	return threshold1;
}
int OTSU1(cv::Mat &srcMat)
{
	int hostogram[256] = { 0 };
	int height = srcMat.rows;			//行数，即图片的高
	int width = srcMat.cols;			//列数，即图片的宽	
	int threshold1 = 0;					//阈值
	double w1 = 0, w2 = 0, W = 0;		//前景、背景、以及总的像素数
	double PgraySum = 0, QgraySum = 0, graySum = 0;	//前景和背景的灰度总值	
	double u1 = 0, u2 = 0, U = 0, m = 0, mmax = 0;			//前景、背景、以及总的像素均值;类间方差分子
	W = height*width;
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			hostogram[int(srcMat.at<uchar>(j, i))]++;
			graySum += int(srcMat.at<uchar>(j, i));
		}
	}
	for (int t = 0; t < 256; t++)
	{
		for (int k = 0; k < t; k++)
		{
			w2 += hostogram[k];
			QgraySum += k*hostogram[k];
		}
		w1 = W - w2;
		PgraySum = graySum - QgraySum;
		if (w1*w2 != 0)     //防止计算时分母为0（前景或背景像素数为0时）
		{
			//p,q均值；类间方差分子
			u1 = PgraySum / w1;
			u2 = QgraySum / w2;
			m = w1*w2*(u1 - u2)*(u1 - u2);
			//每次循环后清零
			PgraySum = 0;
			QgraySum = 0;
			w1 = 0;
			w2 = 0;
		}
		if (m >= mmax)				//判断最大的类间方差，
		{
			mmax = m;
			threshold1 = t;
		}
	}
	return threshold1;
}

int main()
{
	cv::Mat srcMat = cv::imread("E:\\素材\\动漫.jpg");
	cv::Mat OSTU1, gray;
	if (srcMat.empty())
	{
		return -1;
	}
	cv::imshow("原图", srcMat);			//打印原图
	int height = srcMat.rows;			//行数，即图片的高
	int width = srcMat.cols;			//列数，即图片的宽
	int threshold1 = 0;					//阈值

	cvtColor(srcMat, gray, COLOR_BGR2GRAY);
	cv::imshow("gray", gray);
	threshold(gray, OSTU1, 0, 255, CV_THRESH_OTSU);	//自带OTSU函数
	cv::imshow("OTSU1", OSTU1);
	threshold1 = OTSU1(gray);

	//二值化
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			if (gray.at<uchar>(j, i) >= threshold1)
				gray.at<uchar>(j, i) = 255;
			else
				gray.at<uchar>(j, i) = 0;
		}
	}
	imshow("OTSU2", gray);
	waitKey(0);
	return 0;
}
