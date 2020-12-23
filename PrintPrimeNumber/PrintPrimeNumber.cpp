// Parallel_for_temp.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

namespace myspace
{

	class myParallel : public ParallelLoopBody
	{
	private:
		Mat& src;
	public:
	
		myParallel(Mat& image) :src(image)
		{
		}
	
		void operator()(const Range& range) const
		{
			int height = src.rows;
			for (int i = range.start; i < range.end; i++)
			{
				uchar *data = src.ptr<uchar>(i);
				for (int j = 0; j < height; ++j)
				{
					data[j] = std::pow(data[j], 3);	
				}
			}
		}
	};

	void testParallelFor(Mat& src)
	{
		int width = src.cols;
		parallel_for_(Range(0, width), myParallel(src));
	}
}


void cube(Mat& src)
{
	int width = src.cols;
	int height = src.rows;
	for (int i = 0; i < width; i++)
	{
		uchar *data = src.ptr<uchar>(i);
		for (int j = 0; j < height; ++j)
		{
			data[j] = std::pow(data[j], 3);
		}
	}
}

int main()
{
	Mat testForParallel(6400, 4800, CV_16U);
	Mat testForSequential(6400, 4800, CV_16U);


	double t1 = (double)getTickCount();
	myspace::testParallelFor(testForParallel);
	t1 = ((double)getTickCount() - t1) / getTickFrequency();
	cout << " parallel  for  ��ʱ:" << t1 * 1000 << "ms" << endl;

	double t2 = (double)getTickCount();
	cube(testForSequential);
	t2 = ((double)getTickCount() - t2) / getTickFrequency();
	cout << "Sequential for  :" << t2 * 1000 << "ms" << endl;
	cout << "  for        :" << t2 / t1 << endl;

	system("pause");
	return 0;
}

