// PrintPrimeNumber.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
#include<opencv2/opencv.hpp>
#include "function.h"
using namespace cv;
using namespace std;

int main()
{
	double start = static_cast<double>(cvGetTickCount());

	//��ȡͼƬ
	readImage();

	//��ȡ��Ƶ,�Լ�������ͷ
	readVideo();

	//��ȡͼ������	
	readSequence();

	//Mat�Ĵ���
	createMat();

	//Mat�ĸ��Ʒ���
	copyMat();

	//Mat�Ļ�������
	calcMat();

	//���������Դ�������
	calcLinearAlg();

	//����Mat������Է���
	solveLinearEquations();

	//������ʱ
	double time = ((double)cvGetTickCount() - start) / cvGetTickFrequency();
	//��ʾʱ��
	cout << "processing time:" << time / 1000 << "ms" << endl;

	//�ȴ�������Ӧ�����������������
	system("pause");
    return 0;
}

