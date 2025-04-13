/*Time complexity of this algorithm is O(n)*/
/*Counting Sort is not in-place algorithm but stable*/ 

#include <iostream>
using namespace std;

void countingSort(int arrA[], int arrB[], int s, int k)
{
	int arrC[k];
	
	/*Initializing arrC*/
	for(int i=0; i<k; i++)
	{
		arrC[i]=0;
	}
	/*Counting number of elements*/
	for(int j=0; j<s; j++)
	{
		arrC[arrA[j]]=arrC[arrA[j]]+1;
	}
	/*Finding positions*/
	for(int i=1; i<k; i++)
	{
		arrC[i]=arrC[i]+arrC[i-1];
	}
	/*Inserting sorted values in arrB*/
	for(int j=s-1; j>=0; j--)
	{
		arrB[arrC[arrA[j]]-1]=arrA[j];
		arrC[arrA[j]]=arrC[arrA[j]]-1;
	}
}

int main()
{
	int size;
	
	cout<<"How many elements do you want to sort: ";
	cin>>size;
	int arr[size];
	int sortedArr[size];
	
	cout<<"\nPlease enter the elements:\n\n";
	for(int i=0; i<size; i++)
	{
		cout<<"Insert an element: ";
		cin>>arr[i];
	}
	
	countingSort(arr, sortedArr, size, 8);
	cout<<"\nAfter sorting the elements: \n\n";
	for(int j=0; j<size; j++)
	{
		cout<<sortedArr[j]<<" ";
	}
	cout<<"\n";
}