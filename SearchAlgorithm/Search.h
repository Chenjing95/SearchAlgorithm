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
	void SearchSort(int a[], int Sorted_a[], int len);                    // �������򣬵���
	int BinarySearch(int a[], int len, int value);                        // ���ַ�����
	int BinarySearch2(int a[], int low, int high, int value);             // ���ַ����ң��ݹ�汾��
	int InsertSearch(int a[], int low, int high, int value);              // ��ֵ����
	int FibonacciSearch(int a[], int len, int value);           // 쳲���������
	void SearchShow(int a[], int len);

private:

};








#endif