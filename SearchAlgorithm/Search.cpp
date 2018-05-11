#include "Search.h"
#include <stdio.h>
#include <iostream>

/**************�������򣨵�����***************/
void SearchAlg::SearchSort(int a[], int Sorted_a[], int len)
{
	for (int i = 0; i < len; i++)
	{
		Sorted_a[i] = a[i];
	}
	sort(Sorted_a, Sorted_a + len);
	
}


/*************���ַ�����*****************/
/*Ҫ����������������*/
/*�������������λ��*/

int SearchAlg::BinarySearch(int a[], int len, int value)
{
	int low = 0;
	int mid;
	int high = len;

	
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (a[mid] == value)
			return mid;
		if (a[mid] <= value)
			low = mid + 1;
		if (a[mid] >= value)
			high = mid - 1;
	}
	return -1;
}

/*************���ַ����ң��ݹ鷨��*****************/
/*Ҫ����������������*/
/*�������������λ��*/
int SearchAlg::BinarySearch2(int a[], int low, int high, int value)
{
	int mid = (low + high) / 2;
	if (a[mid] == value)
	{
		return mid;
	}
	else if (a[mid] < value)
	{
		low = mid + 1;
		return SearchAlg::BinarySearch2(a, low, high, value);
	}
	else
	{
		high = mid - 1;
		return SearchAlg::BinarySearch2(a, low, high, value);
	}
	return -1;
}

/*********************��ֵ����********************/
/*����ֲ��ҵ�˼��һ�£���������ȷ���Ƚ�λ��ʱ��ϣ�������ܽӽ���ʵֵ*/
/*ͬ����Ҳ���������*/
/*����������ֵ�ֲ��ȽϾ��ȵ����*/
int SearchAlg::InsertSearch(int a[], int low, int high, int value)
{
	int mid = low + ((value - a[low]) / (a[high] - a[low]))*(high - low);
	if (a[mid] == value)
	{
		return mid;
	}
	else if (a[mid] < value)
	{
		low = mid + 1;
		return BinarySearch2(a, low, high, value);
	}
	else
	{
		high = mid - 1;
		return BinarySearch2(a, low, high, value);
	}
	return -1;
}

/**********************쳲���������*********************/
int SearchAlg::FibonacciSearch(int a[], int len, int value)
{
	// Step1���ȹ���һ������ΪMaxNum��쳲���������
	int f[MaxNum];
	Fibonacci(f, MaxNum);
	
	// Step2:�ҵ�len��f��k���е�λ��
	int k = 0;
	while (len > f[k] - 1)
	{
		k++;
	}

	// Step3:��������չ��f[k]-1
	int temp_a[MaxLen];
	for (int i = 0; i < f[k] - 1; i++)
	{
		if (i < len)
		{
			temp_a[i] = a[i];
		}
		else
		{
			temp_a[i] = a[len - 1];
		}
	}
	
	// Step4�����ҹ���
	int low = 0;
	int high = len - 1;
	while (low < high)
	{
		int mid = low + f[k - 1] - 1;
		// ���ʱ���������
		if (temp_a[mid] == value)
		{
			if (mid <= len - 1)
				return mid;
			else if (mid>len - 1)
				return len - 1;
		}
		// �����߼�������
		else if (temp_a[mid] > value)
		{
			high = mid - 1;
			k = k - 1;
		}
		// ���Ұ�߼�������
		else if (temp_a[mid] < value)
		{
			low = mid + 1;
			k = k - 2;
		}
	}
	delete[]temp_a;
	return -1;
}

// ������ʾ
void SearchAlg::SearchShow(int a[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}
void Fibonacci(int f[], int k)
{
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i < k; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
}

