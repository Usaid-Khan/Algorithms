/*Time complexity of this algorithm is O(n)*/

#include <iostream>
using namespace std;

int arr[50];

void initializeArray()
{
    for(int i=0; i<50; i++)
    {
	    arr[i]=-1;
    }
}

int memoFib(int n)
{
	if(n<=1)
    {
        arr[n]=0;
    	return 0;
	}
	if(n==2)
	{
	    arr[n]=1;
		return 1;
	}
	if(arr[n-1]==-1)
	{
		arr[n-1]=memoFib(n-1);
	}
	if(arr[n-2]==-1)
	{
	    arr[n-2]=memoFib(n-2);
	}
	
	return memoFib(n-1)+memoFib(n-2);
}

int main()
{
	int num = 0;

    cout << "Please tell for which number you want the Fibonacci sequence: ";
    cin >> num;

    int fibNum = memoFib(num);
    cout << "\nFibonacci Number for " << num << " is " << fibNum << "\n";
}