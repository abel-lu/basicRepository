// calcaPixelAverage.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;

//����ɫͼ��ת��Ϊ�Ҷ�ͼ
//void grayimage(cv::Mat srcMat)
//{
//	int height = srcMat.rows;		//��������ͼƬ�ĸ�
//	int width = srcMat.cols;		//��������ͼƬ�Ŀ�
//	//�������ص㣻
//	for (int j = 0; j < height; j++)
//	{
//		for (int i = 0; i < width; i++)
//		{
//			//��Ȩƽ������Ҷ�ֵ�����۶���ɫ�����У�����ɫ�������
//			uchar gray = srcMat.at<Vec3b>(j, i)[0]*0.114 + srcMat.at<Vec3b>(j, i)[1]*0.587 + srcMat.at<Vec3b>(j, i)[2]*0.299;
//			srcMat.at<Vec3b>(j, i)[0] = gray;
//			srcMat.at<Vec3b>(j, i)[1] = gray; 
//			srcMat.at<Vec3b>(j, i)[2] = gray;
//		}
//	}
//}

int OTSU(cv::Mat &srcMat)
{
	int height = srcMat.rows;			//��������ͼƬ�ĸ�
	int width = srcMat.cols;			//��������ͼƬ�Ŀ�	
	int threshold1 = 0;					//��ֵ
	double w1 = 0;						//ǰ�����������Լ��ܵ�������
	double w2 = 0;
	double W = 0;
	double PgraySum = 0;				//ǰ���ͱ����ĻҶ���ֵ	
	double QgraySum = 0;
	double u1 = 0;
	double u2 = 0;
	double U = 0;
	double m = 0;
	double mmax = 0;			//ǰ�����������Լ��ܵ����ؾ�ֵ;��䷽�����

	for (int t = 0; t <= 255; t++)		//����0~255�Ҷȼ����������ֵ
	{
		for (int j = 0; j < height; j++)
		{
			for (int i = 0; i < width; i++)
			{
				if (int(srcMat.at<uchar>(j, i)) >= t)
				{
					w1 += 1;
					PgraySum += srcMat.at<uchar>(j, i);	//pǰ���ֲ����ܻҶ�ֵ
				}
				else
				{
					w2 += 1;
					QgraySum += srcMat.at<uchar>(j, i);	//q�����ֲ����ܻҶ�ֵ
				}
			}
		}
		if (w1*w2 != 0)     //��ֹ����ʱ��ĸΪ0��ǰ���򱳾�������Ϊ0ʱ��
		{
			//p,q��ֵ����䷽�����
			u1 = PgraySum / w1;
			u2 = QgraySum / w2;
			m = w1*w2*(u1 - u2)*(u1 - u2);
			//ÿ��ѭ��������
			PgraySum = 0;
			QgraySum = 0;
			w1 = 0;
			w2 = 0;
		}
		if (m >= mmax)				//�ж�������䷽�
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
	int height = srcMat.rows;			//��������ͼƬ�ĸ�
	int width = srcMat.cols;			//��������ͼƬ�Ŀ�	
	int threshold1 = 0;					//��ֵ
	double w1 = 0, w2 = 0, W = 0;		//ǰ�����������Լ��ܵ�������
	double PgraySum = 0, QgraySum = 0, graySum = 0;	//ǰ���ͱ����ĻҶ���ֵ	
	double u1 = 0, u2 = 0, U = 0, m = 0, mmax = 0;			//ǰ�����������Լ��ܵ����ؾ�ֵ;��䷽�����
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
		if (w1*w2 != 0)     //��ֹ����ʱ��ĸΪ0��ǰ���򱳾�������Ϊ0ʱ��
		{
			//p,q��ֵ����䷽�����
			u1 = PgraySum / w1;
			u2 = QgraySum / w2;
			m = w1*w2*(u1 - u2)*(u1 - u2);
			//ÿ��ѭ��������
			PgraySum = 0;
			QgraySum = 0;
			w1 = 0;
			w2 = 0;
		}
		if (m >= mmax)				//�ж�������䷽�
		{
			mmax = m;
			threshold1 = t;
		}
	}
	return threshold1;
}

int main()
{
	cv::Mat srcMat = cv::imread("E:\\�ز�\\����.jpg");
	cv::Mat OSTU1, gray;
	if (srcMat.empty())
	{
		return -1;
	}
	cv::imshow("ԭͼ", srcMat);			//��ӡԭͼ
	int height = srcMat.rows;			//��������ͼƬ�ĸ�
	int width = srcMat.cols;			//��������ͼƬ�Ŀ�
	int threshold1 = 0;					//��ֵ

	cvtColor(srcMat, gray, COLOR_BGR2GRAY);
	cv::imshow("gray", gray);
	threshold(gray, OSTU1, 0, 255, CV_THRESH_OTSU);	//�Դ�OTSU����
	cv::imshow("OTSU1", OSTU1);
	threshold1 = OTSU1(gray);

	//��ֵ��
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
