
#include "stdafx.h"
#include <iostream>
#include <vector>
//#include "MyList.h"
//#incldue <>
using namespace std;

int size  = 10;
int left(int i){return i*2+1;}  
int right(int i){return i*2+2;}  
int parent(int i){return (i-1)/2;}  

void MaxHeap(int *a,int i)
{
	int l = left(i);
	int r = right(i);
	int largest = i;
	if(l<size && a[l]>a[i])
		largest = l;
	if(r<size && a[r]>a[largest])
		largest = r;
	if(largest != i)
	{
		int tmp = a[i];
		a[i] = a[largest];
		a[largest] = tmp;
		MaxHeap(a,largest);
	}
}

void BuildMaxHeap(int *a)
{
	for(int i = (size-1)/2;i>=0;i--)
		MaxHeap(a,i);
}

void Sort(int *a)
{
	BuildMaxHeap(a);
	for(int i = size-1;i>=1;i--)
	{
		int tmp = a[i];
		a[i] = a[0];
		a[0] = tmp;
		size--;
		MaxHeap(a,0);
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int a[10] = {4,1,3,2,16,9,10,14,8,7};
	for(int i = 0;i<size;i++)
		cout<<a[i]<<" ";
	Sort(a);

	cout<<endl;
	for(int i = 0;i<10;i++)
		cout<<a[i]<<" ";
	return 0;
}

