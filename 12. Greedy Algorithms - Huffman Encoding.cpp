#include <iostream>
using namespace std;

class Element{
	private:
		char val;
		int freq;
	
	public:
		Element()
		{
			this->val=this->freq=0;
		}
		
		void setVal(char val)
		{
			this->val=val;
		}
		char getVal()
		{
			return val;
		}
		void setFreq(int freq)
		{
			this->freq=freq;
		}
		int getFreq()
		{
			return freq;
		}
};

int calculateFreq(char array[], int arrSize, Element elemForCopy[])
{
	int count=0;
	char c;
	Element elem[arrSize];

	c=array[0];
	
	for(int k=0; k<arrSize; k++)
	{
		if(array[k]==c)
		{
			elem[count].setVal(c);
			elem[count].setFreq(elem[count].getFreq()+1);
		}
		else
		{
			c=array[k];
			++count;
			elem[count].setVal(c);
			elem[count].setFreq(elem[count].getFreq()+1);
		}
	}

	
	for(int i=0; i<count; i++)
	{
		cout<<"Frequency of "<<elem[i].getVal()<<" is "<<elem[i].getFreq()<<"\n";
		elemForCopy[i]=elem[i];
	}
	
	return count;
}


void mergeArrays(char leftArr[], int leftArrSize, char rightArr[], int rightArrSize, char tempArr[])
{
	int i=0, j=0, k=0;
	
	while(i<leftArrSize && j<rightArrSize)
	{
		if(leftArr[i]<rightArr[j])
		{
			tempArr[k]=leftArr[i];
			i++;
			k++;
		}
		else
		{
			tempArr[k]=rightArr[j];
			j++;
			k++;
		}
	}
	while(i<leftArrSize)
	{
		tempArr[k]=leftArr[i];
		i++;
		k++;
	}
	while(j<rightArrSize)
	{
		tempArr[k]=rightArr[j];
		j++;
		k++;
	}
}

void mergeSortRec(char array[], int size, char tmp[])
{
	int i;
	int mid=size/2;
	
	if(size>1)
	{
		mergeSortRec(array, mid, tmp);
		mergeSortRec(array+mid, size-mid, tmp);
		
		mergeArrays(array, mid, array+mid, size-mid, tmp);
		for(i=0; i<size; i++)
		{
			array[i]=tmp[i];
		}
	}
}

void mergeSort(char array[], int size)
{
	char* tmpArrayPtr = new char[size];
	
	if(tmpArrayPtr!=NULL)
	{
		mergeSortRec(array, size, tmpArrayPtr);
	}
	else
	{
		cout<<"Not enough memory to sort list.\n";
		return;
	}
	
	delete[] tmpArrayPtr;
}

void Huffman(int n, Element elements[])
{
	for(int i=0; i<n; i++)
	{
		
	}
}

int main()
{
	char arr[20]={'i', 'e', 'e', 's', 'i', 'e', 'w', 'l', 'f', 't', 'r', 'e', 'x', 'm', 'n', 'f', 'o', 'q', 'a', 'f'};
	Element elem2[20];
	
	cout<<"Before Sorting:\t";
	for(int i=0; i<20; i++)
	{
		cout<<arr[i];
	}
	cout<<"\n\n";
	
	mergeSort(arr, 20);
	int ct=calculateFreq(arr, 20, elem2);
	
	Huffman(ct, elem2);	
		
	cout<<"\nAfter Sorting:\t";
	for(int i=0; i<20; i++)
	{
		cout<<arr[i];
	}
	cout<<"\n";
}