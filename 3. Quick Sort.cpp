/*Average and best case time complexity of this algorithm is nlogn and wrost case time complexity is n^2*/
/*This is in-place and not stable algorithm*/

#include <iostream>
using namespace std;

void swap(int Arr[], int firstIndex, int secIndex)
{
	int temp=Arr[firstIndex];
	Arr[firstIndex]=Arr[secIndex];
	Arr[secIndex]=temp;
}

int partition(int A[], int sIndex, int eIndex)
{
	int pivot=A[sIndex];
	int q=sIndex;
	
	for(int s=sIndex+1; s<=eIndex; s++)
	{
		if(A[s]<pivot)
		{
			++q;
			swap(A, q, s);
		}
	}
	swap(A, sIndex, q);
	
	return q;
}

void quickSort(int A[], int start, int end)
{
	int random, pivot;
	
	if(end>start)
	{
		pivot=partition(A, start, end);
		quickSort(A, start, pivot-1);
		quickSort(A, pivot+1, end);
	}
}

int main()
{
	int size;
	
	cout<<"How many elements you want to sort: ";
	cin>>size;
	int arr[size];
	
	cout<<"\nPlease insert the elements to sort.\n\n";
	for(int i=0; i<size; i++)
	{
		cout<<"Insert an element: ";
		cin>>arr[i];
	}
	
	quickSort(arr, 0, size-1);
	cout<<"\nAfter sorting, your array is: \n\n";
	for(int j=0; j<size; j++)
	{
		cout<<arr[j]<<" ";
	}
	cout<<"\n";
}