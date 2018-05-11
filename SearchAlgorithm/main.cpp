#include "Search.h"


void main()
{
	int input[] = { 2, 9, 6, 18, 19, 42, 25, 13, 33, 5 };

	// 数组作为形参，传入的是地址，因此，如果在函数内部对a进行排序等操作，a数组的值就会变化
	// 并且，a作为形参传入时，sizeof(a)取的只是第一个元素的大小，因此要在函数外部求length
	int len = sizeof(input) / sizeof(input[0]);

	SearchAlg searchalg;

	cout << "输入数组：";
	searchalg.SearchShow(input, len);

	cout << "排序后数组：";
	int SortedInput[MaxLen];
	searchalg.SearchSort(input, SortedInput, len);
	searchalg.SearchShow(SortedInput, len);
	
	cout << "二分法查找结果：";
	cout << searchalg.BinarySearch(SortedInput, len, 19) << endl;

	cout << "二分法（递归法）查找结果：";
	cout << searchalg.BinarySearch2(SortedInput, 0, len - 1, 19) << endl;

	cout << "插值查找：";
	cout << searchalg.InsertSearch(SortedInput, 0, len - 1, 19) << endl;

	cout << "斐波那契查找：";
	cout << searchalg.FibonacciSearch(SortedInput, len, 19) << endl;
}