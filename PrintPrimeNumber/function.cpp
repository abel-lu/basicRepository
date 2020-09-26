#include "stdafx.h"
#include "function.h"
#include <stdio.h>


int readImage()
{

	std::cout << "-----------start to read Image-------------" << std::endl;

	//���뵥��ͼƬ��·�����滻���Լ���ͼƬ��·��
	cv::Mat srcMat = imread("E:\\�ز�\\��̬ѧͼƬ\\opencv.jpg");

	//��ȡͼƬ��һЩ��Ϣ
	// Mat�Ƿ�Ϊ�գ������ж϶�ͼ�Ƿ�ɹ�
	std::cout << "empty:" << (srcMat.empty() ? "the Mat is empty,fail to read" : "not empty") << std::endl;
	if (srcMat.empty())return -1;

	//��Mat��
	//cols �� ���� �൱�� width  
	//rows �� ���� �൱�� height 
	//����
	std::cout << "rows:" << srcMat.rows << std::endl;
	//���� 
	std::cout << "cols:" << srcMat.cols << std::endl;
	//ά�ȣ���ͨͼƬΪ2ά
	std::cout << "dims:" << srcMat.dims << std::endl;

	// Size��OpenCV�ڲ��������������
	std::cout << "size[]:" << srcMat.size().width << "," << srcMat.size().height << std::endl;

	// ���id
	// ��������ÿһ�������С�ÿһ��ͨ�����ľ��ȣ�depth��ֵԽ�󣬾���Խ�ߡ��� ? ? ? ? ? ? ? ? 
	//Opencv�У�Mat.depth()�õ�����һ��0~6�����֣��ֱ����ͬ��λ������Ӧ��ϵ���£� ? ? ? ? ? ? ? ? ? ? ? ? ? ?
	//opencv�У�����ʹ��Mat.at��������ʱ��������ȷ��д��Ӧ���������ͣ�
	//Mat�����Ͷ��巽��
	//The definition is as follows:
	//CV_(λ�� + ���������ͣ� + ��ͨ��������
	//��, CV_32FC1 ��ʾ 32λ float�͵�ͨ��,
	//OpenCV�е�����������C���������͵Ķ�Ӧ��ϵ��
	/*
	uchar   CV_8U		0
	char    CV_8S		1
	ushort  CV_16U		2
	short   CV_16S		3
	int     CV_32S		4
	float   CV_32F		5
	double  CV_64F		6
	*/
	std::cout << "depth (ID):" << srcMat.depth() << std::endl;

	// channel������Ҷ�ͼΪ��ͨ����RGBͼΪ3ͨ��
	std::cout << "channels:" << srcMat.channels() << std::endl;

	// Mat��һ��Ԫ�ص�size(byte��),����һ��Ԫ��ռ�õ��ֽ�����
	//����������
	//CV_8UC1��				elemSize==1��1 byte��
	//CV_8UC3/CV_8SC3��		elemSize==3��3 byte
	//CV_16UC3/CV_16SC3��	elemSize==6��6 byte
	//��elemSize==�ֽ���xͨ����������һ��Ԫ��ռ�õ��ֽ�����
	std::cout << "elemSize:" << srcMat.elemSize() << "[byte]" << std::endl;
	// Mat��һ��Ԫ�ص�һ��ͨ����size(byte��)������Ԫ��һ��ͨ��ռ�õ��ֽ���,
	//eleSize1==elemSize/channels��
	std::cout << "elemSize1 (elemSize/channels):" << srcMat.elemSize1() << "[byte]" << std::endl;

	//Ԫ�ص������������ͼ�񣬼�Ϊ���ظ���
	std::cout << "total:" << srcMat.total() << std::endl;
	// step ��byte����  
	//Mat������ÿһ�еġ������������ֽ�Ϊ������λ��ÿһ��������Ԫ�ص��ֽ�����
	//cols*elemSize=cols*eleSize1*channels
	std::cout << "step:" << srcMat.step << "[byte]" << std::endl;
	// һ��step��channel������ÿ�е�channel��
	std::cout << "step1 (step/elemSize1):" << srcMat.step1() << std::endl;
	// ��Mat���ڴ����Ƿ�����
	std::cout << "isContinuous:" << (srcMat.isContinuous() ? "true" : "false") << std::endl;
	// �Ƿ�Ϊ�Ӿ���
	std::cout << "isSubmatrix:" << (srcMat.isSubmatrix() ? "true" : "false") << std::endl;


	//���뵥��ͼƬ���Ӳ���0����ʾ���룬��ת���ɻҶ�ͼ
	cv::Mat gryMat = imread("E:\\�ز�\\��̬ѧͼƬ\\opencv.jpg", 0);
	if (srcMat.empty())return -1;
	//����ͼƬ
	//imwrite("E:\\�ز�\\��̬ѧͼƬ\\opencv.jpg", gryMat);

	//��ʾͼƬ
	imshow("src", srcMat);
	imshow("gray", gryMat);

	//��ʾͼƬ������Ҫ��waitKey()�������޷���ʾͼ��
	//waitKey(0),���޵���ʾ���ڣ�ֱ���κΰ�������
	//������������֣���waitKey(25)��ʾ25���룬Ȼ��رա�
	waitKey(0);

	//�ر����д���
	destroyAllWindows();

	return 0;
}

//ͨ��OpenCV��ȡ��Ƶ
int readVideo()
{
	std::cout << "-----------start to read Video-------------" << std::endl;

	//��ȡ������Ƶ��OpenCV���Զ�ȡ������Ƶ�ļ�������ͷ����������ͼ���ļ�
	//VideCaptureΪopencv�������Ƶ���ݵ��࣬ʵ���ǵײ��ffmpeg�ķ�װʵ�ֵ�

	//----------------------��ȡ��Ƶ�ļ�--------------------------
	//ʵ����VideoCapture�࣬��Ϊcap�����򿪣����е���Ƶ
	//Ҳ����ͨ�� capVideo.open("../testImages\\vtest.avi"); ��
	//��� capVideo.open(0)���Ĭ������ͷ������0Ϊ����ͷ��id
	VideoCapture capVideo("../testImages\\vtest.avi");

	//�����Ƶ��ʧ��
	if (!capVideo.isOpened()) {
		std::cout << "Unable to open video!" << std::endl;
		return -1;
	}

	//��ȡ��Ƶ��һЩ���ԣ���������ɲο�videoio_c.h�еö���
	cout << "parameters" << endl;
	cout << "width��" << capVideo.get(CV_CAP_PROP_FRAME_WIDTH) << endl;
	cout << "heigth��" << capVideo.get(CV_CAP_PROP_FRAME_HEIGHT) << endl;
	cout << "frames��" << capVideo.get(CV_CAP_PROP_FRAME_COUNT) << endl;
	cout << "fps��" << capVideo.get(CV_CAP_PROP_FPS) << endl;

	//�����ļ���ʼ����VideoWriterΪOpenCV�ж������Ƶ������
	VideoWriter writer;
	//ѡ����뷽ʽ
	int codec = CV_FOURCC('M', 'J', 'P', 'G');
	// �������Ƶ��ַ������
	string filename = "../testImages\\saved.avi";
	//����֡��
	double fps = capVideo.get(CV_CAP_PROP_FPS);
	//�������Ƶ�ĳߴ�,�˴��ߴ���Сһ��
	cv::Size vSize;
	vSize.width = capVideo.get(CV_CAP_PROP_FRAME_WIDTH) / 2;
	vSize.height = capVideo.get(CV_CAP_PROP_FRAME_HEIGHT) / 2;

	//����Ƶ��
	writer.open(filename, codec, fps, vSize);

	Mat frame;
	Mat resizeFrame;
	Mat grayFrame;

	while (1) {
		//��Ƶ���ж�ȡͼ��
		capVideo >> frame;

		if (frame.empty()) {
			cout << "Unable to read frame!" << endl;
			destroyAllWindows();
			return -1;
		}

		//���浽��Ƶ����������Ƶ�ļ��ߴ罵Ϊ1/2��frame�ߴ�ҲҪ����
		resize(frame, resizeFrame, vSize);
		writer.write(resizeFrame);

		//���ԽӸ��ִ���
		cvtColor(frame, grayFrame, CV_RGB2GRAY);

		imshow("frame", frame);
		imshow("resizeFrame", resizeFrame);
		imshow("gray", grayFrame);

		//��ʾͼƬ����ʱ30ms������Ҫ��waitKey()�������޷���ʾͼ��
		//�ȴ�������Ӧ������ESC���˳�
		if (waitKey(30) == 27) {
			destroyAllWindows();
			break;
		}
	}

	destroyAllWindows();
	return 0;
}

//��ȡ����ͼƬ
int readSequence()
{
	//(eg. `img_%02d.jpg`, which will read samples like `img_00.jpg, img_01.jpg, img_02.jpg, ...`)
	VideoCapture capSequence("../testImages\\sequence\\left%02d.jpg");

	if (!capSequence.isOpened())
	{
		cerr << "Unable to open the image sequence!\n" << endl;
		return 1;
	}

	cv::Mat frame;
	while (1) {
		//��Ƶ���ж�ȡͼ��
		capSequence >> frame;

		if (frame.empty()) {
			cout << "Unable to read frame!" << endl;
			destroyAllWindows();
			return -1;
		}

		imshow("frame", frame);

		waitKey(200);

	}

	return 0;

}



//Mat��Ĵ�������������ʼ��ʾ��
int createMat()
{
	//---����Mat---
	//cols �� ���� �൱�� width  
	//rows �� ���� �൱�� height 
	int cols = 4;
	int rows = 3;
	int type = CV_32S;
	int dataArray[] = { 0,  1,  2,  3,
		10, 11, 12, 13,
		10, 11, 12, 13 };

	cv::Mat mat1_0;	//ʵ�������˲����������ڴ��Ͽ��ٿռ�
	cv::Mat mat2;	//ʵ�������˲����������ڴ��Ͽ��ٿռ�
	cv::Mat mat3;	//ʵ�������˲����������ڴ��Ͽ��ٿռ�


					//���ַ��������г�ʼ������ߴ�����ͣ������ٿռ�
	mat1_0.create(rows, cols, type);
	mat2.create(Size(cols, rows), type);
	mat3.create(mat1_0.size(), mat1_0.type());

	//ͨ��ָ���mat1��ʼ��
	cv::Mat mat1_1(rows, cols, CV_32S, &dataArray);

	//���mat1�ı���ռ��������򿽱���������ݸ�mat1
	//Mat������ʵ�ʱ����ڳ�Ա���� data ����
	if (mat1_0.isContinuous()) {
		memcpy(mat1_0.data, dataArray, sizeof(int)*cols*rows);
	}

	//���������
	//��һ�ֲ����������[0,256)
	cv::randu(mat2, cv::Scalar(0), cv::Scalar(256));
	// ��̫�ֲ����������mean=128, stddev=10
	cv::randn(mat3, cv::Scalar(128), cv::Scalar(10));

	std::cout << "m1_0:" << std::endl << mat1_0 << std::endl << std::endl;
	std::cout << "m1_1:" << std::endl << mat1_1 << std::endl << std::endl;
	std::cout << "m2:" << std::endl << mat2 << std::endl << std::endl;
	std::cout << "m3:" << std::endl << mat3 << std::endl << std::endl;

	//---����Mat---
	// ������������Ϊ64F, channels=10, 3x3 ��2ά����
	cv::Mat mat4(3, 3, CV_64FC(10));
	//Ҳ����ͨ��CV_MAKETYPE()��ø�ֵ�Ĳ�����������CV_MAKETYPE(CV_64F, 10)==78
	cv::Mat mat5(3, 3, CV_MAKETYPE(CV_64F, 10));

	//����channels=2��int�ͣ�2x2���󣬲���ֵ�������������Ϳɲ�matx.hpp�еĶ���
	cv::Mat mat6 = (cv::Mat_<cv::Vec2i>(2, 2) << cv::Vec2i(1, 1), cv::Vec2i(2, 4),
		cv::Vec2i(3, 9), cv::Vec2i(4, 16));

	std::cout << "m6:" << std::endl << mat6 << std::endl << std::endl;

	// 5��4���� 5�С�4�У�Ԫ�ؾ�Ϊ1
	cv::Mat mat7 = cv::Mat::ones(5, 4, CV_8U);
	// 5��4���� 5�С�4�У�Ԫ�ؾ�Ϊ3
	cv::Mat mat8 = cv::Mat::ones(5, 4, CV_8U) * 3;
	// 5��4���� 5�С�4�У�Ԫ�ؾ�Ϊ0
	cv::Mat mat9 = cv::Mat::zeros(5, 4, CV_8U);
	// 3��3���� 3�С�3�У���λ����
	cv::Mat mat10 = cv::Mat::eye(3, 3, CV_8U);

	std::cout << "m7:" << std::endl << mat7 << std::endl << std::endl;
	std::cout << "m8:" << std::endl << mat8 << std::endl << std::endl;
	std::cout << "m9:" << std::endl << mat9 << std::endl << std::endl;
	std::cout << "m10:" << std::endl << mat10 << std::endl << std::endl;


	return 0;

}

//Mat�ĸ��Ʒ���
//Mat�ĸ��ƣ�����Ƽ�ǳ���Ƶķֱ�
int copyMat()
{
	//����һ��3��3��Mat
	cv::Mat m1 = (cv::Mat_<double>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);

	//ǳ���ƣ�ʵ��ֻ�ǰ�m1���ڴ��ַ��ֵ��m_shallow
	//����Mat���ڴ�����ͬһ������
	cv::Mat m_shallow = m1;

	//��ƣ�clone��copyTo��Ϊm_deep1��m_deep2���ڴ��п��ٿռ䣬���Ҹ�������
	cv::Mat m_deep1 = m1.clone();
	cv::Mat m_deep2;
	m1.copyTo(m_deep2);

	std::cout << "m1=" << m1 << std::endl << std::endl;
	std::cout << "m_shallow=" << m_shallow << std::endl << std::endl;
	std::cout << "m_deep1=" << m_deep1 << std::endl << std::endl;
	std::cout << "m_deep2=" << m_deep2 << std::endl << std::endl;

	// �޸�m1��(0,0)λ�õ���ֵ��ע��۲��޸��Ժ���������Mat������
	m1.at<double>(0, 0) = 100;

	std::cout << "m1=" << m1 << std::endl << std::endl;
	std::cout << "m_shallow=" << m_shallow << std::endl << std::endl;
	std::cout << "m_deep1=" << m_deep1 << std::endl << std::endl;
	std::cout << "m_deep2=" << m_deep2 << std::endl << std::endl;


	//����ROI������
	//ROI(region of interest)����Ȥ���򣬼���Ҫ�����������
	//Rect��opencv�ж���ľ�����������
	//���뵥��ͼƬ��·�����滻���Լ���ͼƬ��·��
	cv::Mat srcMat = imread("../testImages\\butterfly.jpg");
	cv::Mat roiMat;
	cv::Rect roi;
	roi.x = 0;
	roi.y = 0;
	roi.width = srcMat.cols / 2;
	roi.height = srcMat.rows / 2;

	//����mask������
	//mask�����֣��������ε�ͼ���еĲ�������
	//mask�ĸ�ʽΪuchar��ʽ��mat����ɫ���ֱ�ʾ��Ҫ���εģ���ɫ��ʾ����Ҫ�ڱ�
	//����mask
	cv::Mat mask = cv::Mat::zeros(srcMat.size(), CV_8U);
	rectangle(mask, roi, Scalar(255), -1);

	cv::Mat maskedMat;

	//����ROI����
	srcMat(roi).copyTo(roiMat);

	//��mask����
	srcMat.copyTo(maskedMat, mask);

	imshow("src", srcMat);
	imshow("mask", mask);
	imshow("masked image", maskedMat);
	imshow("roi", roiMat);

	waitKey(0);

	return 0;
}


//����Mat����һЩ��������
int calcMat()
{
	//����Mat
	cv::Mat m1 = (cv::Mat_<double>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
	std::cout << "m1=" << m1 << std::endl << std::endl;

	//������������
	cv::Mat m2 = m1 + 3;
	cv::Mat m3 = m1 * 3;
	cv::Mat m4 = m1 / 3;

	std::cout << "m2=" << m2 << std::endl << std::endl;
	std::cout << "m3=" << m3 << std::endl << std::endl;
	std::cout << "m4=" << m4 << std::endl << std::endl;

	//mat��mat������
	cv::Mat m5 = m1 + m1;
	//m6��m2��ͬλ�õ���ֵ���
	cv::Mat m6 = m1.mul(m2);
	//��˺��ٳ���ϵ��
	cv::Mat m7 = m1.mul(m2, 2);

	std::cout << "m5=" << m5 << std::endl << std::endl;
	std::cout << "m6=" << m6 << std::endl << std::endl;
	std::cout << "m7=" << m7 << std::endl << std::endl;


	//Ҫȷ������Mat�����ͺͳߴ���ͬ�������ͬ�����׳��쳣
	//Mat���Ͳ�ͬ 
	cv::Mat m8 = (cv::Mat_<int>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
	try {
		std::cout << m1 / m8 << std::endl;
	}
	catch (cv::Exception e) {
		std::cout << std::endl;
	}

	//Mat�ĳߴ粻ͬ 
	cv::Mat m9 = (cv::Mat_<double>(2, 2) << 1, 2, 3, 4);
	try {
		std::cout << m9 / m1 << std::endl;
	}
	catch (cv::Exception e) {
		// ...
		std::cout << std::endl;
	}


	return 0;
}

//һЩ���������Դ�������
int calcLinearAlg()
{
	//�����ăȻ������
	cv::Vec3d v1(1, 2, 3);
	cv::Vec3d v2(3, 4, 5);

	//�Ȼ� 
	double v_dot = v1.dot(v2);
	//���
	cv::Vec3d v_cross = v1.cross(v2);
	std::cout << "v_dot=" << v_dot << std::endl;
	cv::Mat tmp(v_cross);
	std::cout << "v_cross=" << tmp << std::endl;

	//����
	// 6x1 
	cv::Mat m1 = (cv::Mat_<double>(6, 1) << 1, 5, 3, -1, -3, -5);
	// ����(3,4)
	cv::Point p1(3, 4);
	// 6ά�������� L-2����
	double norm_m1 = cv::norm(m1);
	// 2ά�������� L-2����
	double norm_p1 = cv::norm(p1);

	std::cout << std::endl;
	std::cout << "norm(m1)=" << norm_m1 << std::endl;
	std::cout << "norm(p1)=" << norm_p1 << std::endl << std::endl;

	// ͨ��2ά���꣬���㼫���꣬����С�ͽǶ�
	std::cout << "calc Polar" << std::endl;
	//����4��2ά����
	cv::Mat x = (cv::Mat_<double>(4, 1) << 0, 1, 4, 1);
	cv::Mat y = (cv::Mat_<double>(4, 1) << 1, 1, 3, 1.7320504);
	cv::Mat magnitude, angle;
	cv::cartToPolar(x, y, magnitude, angle, true);

	for (int i = 0; i<4; ++i) {
		std::cout << "(" << x.at<double>(i) << ", " << y.at<double>(i) << ") ";
		std::cout << "mag=" << magnitude.at<double>(i) << ", angle=" << angle.at<double>(i) << "[deg]" << std::endl;
	}

	std::cout << std::endl;
	// ͨ����С�ͽǶȣ�����2ά����
	std::cout << "calc Cartesian" << std::endl;
	cv::Mat mag2 = (cv::Mat_<double>(4, 1) << 1, 1.41421, 5, 2);
	cv::Mat ang2 = (cv::Mat_<double>(4, 1) << 90, 45, 36.8699, 60);

	cv::Mat x2, y2;
	cv::polarToCart(mag2, ang2, x2, y2, true); // in degrees

	for (int i = 0; i<4; ++i) {
		std::cout << "(" << x2.at<double>(i) << ", " << y2.at<double>(i) << ") ";
		std::cout << "mag=" << mag2.at<double>(i) << ", angle=" << ang2.at<double>(i) << "[deg]" << std::endl;
	}

	std::cout << std::endl;

	return 0;
}

//������Է���
int solveLinearEquations()
{
	//������������δ֪����ͬʱ
	//  x +  y +  z = 6
	// 3x + 2y - 2z = 1
	// 2x - y  + 3z = 9
	//��� 
	cv::Mat lhand = (cv::Mat_<double>(3, 3) << 1, 1, 1, 3, 2, -2, 2, -1, 3);
	//�ұ� 
	cv::Mat rhand = (cv::Mat_<double>(3, 1) << 6, 1, 9);

	//��˹��ȥ����� 
	cv::Mat ans;
	cv::solve(lhand, rhand, ans);

	std::cout << "Gaussian elimination" << std::endl;
	std::cout << "(x,y,z) = " << ans << std::endl << std::endl;
	//���������� ���� δ֪������ʱ
	//ͨ����С���˷����
	//  x +  y = 3  
	// 3x + 4y = 8 
	// -x - 2y = 2 
	std::cout << "the least square method" << std::endl;
	cv::Mat lhand2 = (cv::Mat_<double>(3, 2) << 1, 1, 3, 4, -1, -2);
	cv::Mat rhand2 = (cv::Mat_<double>(3, 1) << 3, 8, 2);

	cv::Mat x;
	//ͨ��SVD�����С���˷�
	//��������࣬�������Ҳ࣬�������ⷽ��
	cv::solve(lhand2, rhand2, x, cv::DECOMP_SVD);

	std::cout << "(x,y) = " << x << std::endl;
	std::cout << "norm(lhand2*x-rhand2)=" << norm(lhand2*x - rhand2) << std::endl << std::endl;

	return 0;
}
