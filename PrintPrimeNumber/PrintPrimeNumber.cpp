// Parallel_for_temp.cpp : 定义控制台应用程序的入口点。
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
	//自定义类，继承自ParallelLoopBody
	class myParallel : public ParallelLoopBody
	{
	private:
		Mat& src;
	public:
		//构造函数 初始化列表
		myParallel(Mat& image) :src(image)
		{
		}
		//重载函数调用运算符()；后面的const是对类成员的限制，不允许更改类的成员变量
		void operator()(const Range& range) const
		{
			int height = src.rows;
			for (int i = range.start; i < range.end; i++)
			{
				uchar *data = src.ptr<uchar>(i);
				for (int j = 0; j < height; ++j)
				{
					data[j] = std::pow(data[j], 3);	//逐元素求3次方  
				}
			}
		}
	};
	//调用parallel_for_函数实现并行计算
	void testParallelFor(Mat& src)
	{
		int width = src.cols;
		parallel_for_(Range(0, width), myParallel(src));
	}
}

//使用普通for循环函数，遍历图像元素进行立方操作
void cube(Mat& src)
{
	int width = src.cols;
	int height = src.rows;
	for (int i = 0; i < width; i++)
	{
		//ptr方式访问像素，返回行的首地址
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

	//测试耗时对比
	//t1;t2计时parallel_for_、Sequential for
	double t1 = (double)getTickCount();
	myspace::testParallelFor(testForParallel);
	t1 = ((double)getTickCount() - t1) / getTickFrequency();
	cout << " parallel  for  耗时:" << t1 * 1000 << "ms" << endl;

	double t2 = (double)getTickCount();
	cube(testForSequential);
	t2 = ((double)getTickCount() - t2) / getTickFrequency();
	cout << "Sequential for  耗时:" << t2 * 1000 << "ms" << endl;
	cout << "   加速倍数         :" << t2 / t1 << endl;

	system("pause");
	return 0;
}

