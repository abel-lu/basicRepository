#include "stdafx.h"
#include "function.h"


//����ֱ��
int drawLines()
{
	cv::Mat displayMat = cv::Mat::zeros(500, 500, CV_8UC3);

	//0.���Ƶ�Matͼ��
	//1.�߶����
	//2.�߶��յ�
	//3.�߶���ɫ
	//4.�߶δ�ϸ
	//5.�߶ε����ӷ�����4�ڽӣ�8�ڽӣ�antialiased���� 
	//6.������С����λ����

	// ��ɫ �����Ϊ3��4���ھ�����
	cv::line(displayMat, cv::Point(100, 100), cv::Point(400, 105), cv::Scalar(0, 0, 200), 3, 4);
	// ��ɫ�����Ϊ5��8���ھ�����
	cv::line(displayMat, cv::Point(100, 200), cv::Point(400, 205), cv::Scalar(0, 200, 0), 5, 8);
	// ��ɫ�����Ϊ10��antialiased�߶����ӷ�
	cv::line(displayMat, cv::Point(100, 300), cv::Point(400, 305), cv::Scalar(200, 0, 0), 10, CV_AA);

	cv::namedWindow("lines", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	cv::imshow("lines", displayMat);
	cv::waitKey(0);

	destroyAllWindows();

	return 0;
}

int drawRectangles()
{
	cv::Mat displayMat = cv::Mat::zeros(500, 500, CV_8UC3);

	//0.���Ƶ�Matͼ��
	//1.�����ϵĶ���1
	//2.����1�ĶԽǵ�
	//3.�߶���ɫ
	//4.�߶δ�ϸ������ò�����-1�Ļ��������ʵ�ĵľ���
	//5.�߶ε����ӷ�����4�ڽӣ�8�ڽӣ�antialiased���� 
	//6.������С����λ����

	// ��ɫ �����Ϊ3��4���ھ�����
	cv::rectangle(displayMat, cv::Point(200, 50), cv::Point(300, 150), cv::Scalar(0, 0, 200), 3, 4);
	// ��ɫ�����Ϊ5��8���ھ�����
	cv::rectangle(displayMat, cv::Point(200, 200), cv::Point(300, 300), cv::Scalar(0, 200, 0), 5, 8);

	//��һ�ֻ��Ʒ�ʽ�ǣ��������ʹ��cv::Rect����������������
	//0.���Ƶ�Matͼ��
	//1.�����Ƶľ���
	//2.�߶���ɫ
	//3.�߶δ�ϸ������ò�����-1�Ļ��������ʵ�ĵľ���
	//4.�߶ε����ӷ�����4�ڽӣ�8�ڽӣ�antialiased���� 
	//5.������С����λ����

	// ��ɫ�������ڲ���ɫ��antialiased�߶����ӷ�
	cv::Rect rect;
	rect.x = 200;
	rect.y = 350;
	rect.width = 50;
	rect.height = 100;

	cv::rectangle(displayMat, rect, cv::Scalar(200, 0, 0), -1, CV_AA);

	cv::namedWindow("drawing", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	cv::imshow("drawing", displayMat);
	cv::waitKey(0);

	destroyAllWindows();

	return 0;
}

int drawCircles()
{
	cv::Mat displayMat = cv::Mat::zeros(500, 500, CV_8UC3);

	//0.���Ƶ�Matͼ��
	//1.Բ������
	//2.Բ�뾶
	//3.Բ����ɫ
	//4.�߶δ�ϸ������ò�����-1�Ļ��������ʵ��Բ
	//5.�߶ε����ӷ�����4�ڽӣ�8�ڽӣ�antialiased���� 
	//6.������С����λ����

	//��ɫ
	cv::circle(displayMat, cv::Point(300, 100), 100, cv::Scalar(0, 0, 200), 3, 4);
	//��ɫ 
	cv::circle(displayMat, cv::Point(200, 250), 120, cv::Scalar(0, 200, 0), 8, 8);
	//��ɫ
	cv::circle(displayMat, cv::Point(300, 400), 80, cv::Scalar(200, 0, 0), -1, CV_AA);

	cv::namedWindow("drawing", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	cv::imshow("drawing", displayMat);
	cv::waitKey(0);
	destroyAllWindows();

	return 0;
}

int drawEllipse()
{
	cv::Mat displayMat = cv::Mat::zeros(800, 600, CV_8UC3);
	double angle;

	//0.���Ƶ�Matͼ��
	//1.��������
	//2.���ᣬ����
	//3.��ת�Ƕ�, ˮƽΪ0�ȣ�˳ʱ��Ϊ��ֵ
	//4.Բ����ʼ�Ƕȣ�ˮƽ����Ϊ0�ȣ�˳ʱ��Ϊ��ֵ
	//5.Բ�������Ƕ�
	//6.��ɫ
	//7.�߶δ�ϸ������ò�����-1�Ļ��������ʵ��Բ
	//8.�߶ε����ӷ�����4�ڽӣ�8�ڽӣ�antialiased���� 
	//9.������С����λ����

	cv::ellipse(displayMat, cv::Point(150, 150), cv::Size(50, 10), 0, 30, 360, cv::Scalar(0, 0, 200), 1, 4);

	angle = 30;
	cv::ellipse(displayMat, cv::Point(400, 150), cv::Size(200, 100), angle, angle - 100, angle + 200, cv::Scalar(0, 0, 200), 3, 4);

	angle = 0;
	//�൱�ڻ�һ��Բ
	cv::ellipse(displayMat, cv::Point(200, 200), cv::Size(100, 100), angle, angle, angle + 360, cv::Scalar(0, 200, 0), 5, 8);

	angle = 100;
	cv::ellipse(displayMat, cv::Point(200, 400), cv::Size(100, 200), angle, angle - 200, angle + 100, cv::Scalar(200, 0, 0), -1, CV_AA);

	cv::namedWindow("drawing", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	cv::imshow("drawing", displayMat);
	cv::waitKey(0);

	destroyAllWindows();

	return 0;
}

int drawMarkers()
{
	cv::Mat displayMat = cv::Mat::zeros(800, 600, CV_8UC3);



	//0.���Ƶ�Matͼ��
	//1.��������
	//2.��ɫ
	//3.�������
	//4.��ǵĳߴ磬Ĭ��20pixesl
	//5.�߶δ�ϸ
	//6.�߶ε����ӷ�����4�ڽӣ�8�ڽӣ�antialiased���� 

	//�Ӻ�
	drawMarker(displayMat, Point(100, 50), cv::Scalar(0, 255, 255), 0, 20, 1, 8);
	//��
	drawMarker(displayMat, Point(100, 100), cv::Scalar(0, 255, 255), 1);
	//��
	drawMarker(displayMat, Point(100, 200), cv::Scalar(0, 255, 255), 2);
	//��Ƭ
	drawMarker(displayMat, Point(100, 250), cv::Scalar(0, 255, 255), 3);
	//����
	drawMarker(displayMat, Point(100, 300), cv::Scalar(0, 255, 255), 4);
	//����
	drawMarker(displayMat, Point(100, 350), cv::Scalar(0, 255, 255), 5);
	//������
	drawMarker(displayMat, Point(100, 400), cv::Scalar(0, 255, 255), 6);


	cv::namedWindow("drawing", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	cv::imshow("drawing", displayMat);
	cv::waitKey(0);

	destroyAllWindows();

	return 0;
}


//д��
int writeText()
{
	cv::Mat img = cv::Mat::zeros(500, 500, CV_8UC3);

	//���岻ͬ����
	int face[] = { cv::FONT_HERSHEY_SIMPLEX, cv::FONT_HERSHEY_PLAIN, cv::FONT_HERSHEY_DUPLEX, cv::FONT_HERSHEY_COMPLEX,
		cv::FONT_HERSHEY_TRIPLEX, cv::FONT_HERSHEY_COMPLEX_SMALL, cv::FONT_HERSHEY_SCRIPT_SIMPLEX,
		cv::FONT_HERSHEY_SCRIPT_COMPLEX, cv::FONT_ITALIC };

	cv::String ssss;

	//std::string  

	//0.���ֻ��Ƶ�Matͼ��
	//1.����д�����֣�String���� 
	//2.���ֵ����½ǵ�λ��
	//3.����
	//4.���ֵĳߴ����
	//5.���ֵ���ɫ
	//6.���ֵ�������ϸ
	//7.���ֵ���������

	for (int i = 0; i < 8; i++) {

		//int ת��Ϊ �ַ�
		stringstream ss1;
		string str1;
		ss1 << i;
		ss1 >> str1;

		cv::putText(img, str1, cv::Point(30, (i + 1) * 50), face[i], 1.2, cv::Scalar(255, 255, 255), 2, CV_AA);

		cv::putText(img, "OpenCV", cv::Point(100, (i + 1) * 50), face[i], 1.2, cv::Scalar(255, 255, 255), 2, CV_AA);
	}

	cv::namedWindow("drawing", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	cv::imshow("drawing", img);
	cv::waitKey(0);
	destroyAllWindows();

	return 0;
}
