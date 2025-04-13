/*Time complexity of this algorithm is nlogn*/
/*This algorithm is in-place but not stable*/

#include <iostream>
using namespace std;

void swap(int Array[], int first, int second)
{
	int temp=Array[first];
	Array[first]=Array[second];
	Array[second]=temp;
}

void maxHeapify(int Array[], int size, int tmp)
{
	int l=tmp*2;
	int r=(tmp*2)+1;
	int large=tmp;
	
	if(l<=size && Array[large]<Array[l])
	{
		large=l;
	}
	if(r<=size && Array[large]<Array[r])
	{
		large=r;
	}
	if(large!=tmp)
	{
		swap(Array, large, tmp);
		maxHeapify(Array, size, large);
	}
}

void heapSort(int A[], int n)
{
	/*For Inserting*/
	for(int i=n/2; i>0; i--)
	{
		maxHeapify(A, n, i);
	}
	/*For Deleting*/
	for(int i=n; i>1; i--)
	{
		swap(A, 1, i);
		maxHeapify(A, i-1, 1);
	}
}

int main()
{
	int arr[11];
	arr[1]=94;
	arr[2]=84;
	arr[3]=103;
	arr[4]=26;
	arr[5]=12;
	arr[6]=95;
	arr[7]=67;
	arr[8]=88;
	arr[9]=41;
	arr[10]=22;
	
	for(int i=1; i<11; i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<"\n\n";
	
	heapSort(arr, 10);
	cout<<"After applying heapsort:\n";
	for(int i=1; i<11; i++)
	{
		cout<<arr[i]<<"\t";
	}
}