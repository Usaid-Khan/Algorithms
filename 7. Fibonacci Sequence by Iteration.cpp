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

int iterFib(int n)
{
	arr[0]=0;
	arr[1]=0;
	arr[2]=1;
	
	for(int i=3; i<=n; i++)
	{
		arr[i]=arr[i-1]+arr[i-2];
	}
	
	return arr[n];
}

int main()
{
	int num = 0;

    cout << "Please tell for which number you want the Fibonacci sequence: ";
    cin >> num;

    int fibNum = iterFib(num);
    cout << "\nFibonacci Number for " << num << " is " << fibNum << "\n";
}