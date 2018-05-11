#include "Search.h"
#include <stdio.h>
#include <iostream>

/**************数组排序（递增）***************/
void SearchAlg::SearchSort(int a[], int Sorted_a[], int len)
{
	for (int i = 0; i < len; i++)
	{
		Sorted_a[i] = a[i];
	}
	sort(Sorted_a, Sorted_a + len);
	
}


/*************二分法查找*****************/
/*要求：数组必须是有序的*/
/*输出的是排序后的位置*/

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

/*************二分法查找（递归法）*****************/
/*要求：数组必须是有序的*/
/*输出的是排序后的位置*/
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

/*********************插值查找********************/
/*与二分查找的思想一致，不过是在确定比较位置时，希望尽可能接近真实值*/
/*同样的也是有序查找*/
/*适用于数组值分布比较均匀的情况*/
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

/**********************斐波那契查找*********************/
int SearchAlg::FibonacciSearch(int a[], int len, int value)
{
	// Step1：先构造一个长度为MaxNum的斐波那契数列
	int f[MaxNum];
	Fibonacci(f, MaxNum);
	
	// Step2:找到len在f（k）中的位置
	int k = 0;
	while (len > f[k] - 1)
	{
		k++;
	}

	// Step3:将数组扩展到f[k]-1
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
	
	// Step4：查找过程
	int low = 0;
	int high = len - 1;
	while (low < high)
	{
		int mid = low + f[k - 1] - 1;
		// 相等时有两种情况
		if (temp_a[mid] == value)
		{
			if (mid <= len - 1)
				return mid;
			else if (mid>len - 1)
				return len - 1;
		}
		// 在左半边继续查找
		else if (temp_a[mid] > value)
		{
			high = mid - 1;
			k = k - 1;
		}
		// 在右半边继续查找
		else if (temp_a[mid] < value)
		{
			low = mid + 1;
			k = k - 2;
		}
	}
	delete[]temp_a;
	return -1;
}

// 数组显示
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

