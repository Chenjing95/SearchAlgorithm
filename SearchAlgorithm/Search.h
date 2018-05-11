#ifndef SEARCH_H
#define SEARCH_H


#include <stdio.h>
#include <array>
#include <iostream>
#define MaxNum 32
#define MaxLen 1024

using namespace std;

void Fibonacci(int f[], int k);
class SearchAlg
{
public:
	void SearchSort(int a[], int Sorted_a[], int len);                    // 数列排序，递增
	int BinarySearch(int a[], int len, int value);                        // 二分法查找
	int BinarySearch2(int a[], int low, int high, int value);             // 二分法查找（递归版本）
	int InsertSearch(int a[], int low, int high, int value);              // 插值查找
	int FibonacciSearch(int a[], int len, int value);           // 斐波那契查找
	void SearchShow(int a[], int len);

private:

};








#endif