#include "Search.h"


void main()
{
	int input[] = { 2, 9, 6, 18, 19, 42, 25, 13, 33, 5 };

	// ������Ϊ�βΣ�������ǵ�ַ����ˣ�����ں����ڲ���a��������Ȳ�����a�����ֵ�ͻ�仯
	// ���ң�a��Ϊ�βδ���ʱ��sizeof(a)ȡ��ֻ�ǵ�һ��Ԫ�صĴ�С�����Ҫ�ں����ⲿ��length
	int len = sizeof(input) / sizeof(input[0]);

	SearchAlg searchalg;

	cout << "�������飺";
	searchalg.SearchShow(input, len);

	cout << "��������飺";
	int SortedInput[MaxLen];
	searchalg.SearchSort(input, SortedInput, len);
	searchalg.SearchShow(SortedInput, len);
	
	cout << "���ַ����ҽ����";
	cout << searchalg.BinarySearch(SortedInput, len, 19) << endl;

	cout << "���ַ����ݹ鷨�����ҽ����";
	cout << searchalg.BinarySearch2(SortedInput, 0, len - 1, 19) << endl;

	cout << "��ֵ���ң�";
	cout << searchalg.InsertSearch(SortedInput, 0, len - 1, 19) << endl;

	cout << "쳲��������ң�";
	cout << searchalg.FibonacciSearch(SortedInput, len, 19) << endl;
}