#pragma once
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//OpenCV�е�mat�Ļ�������demo

//��ȡͼƬ
int readImage();
int readVideo();
int readSequence();

//Mat�Ĵ��������Ƽ����㡣����Mat�ĸ��ֲ�������
int createMat();
int copyMat();
int calcMat();
int calcLinearAlg();
int solveLinearEquations();