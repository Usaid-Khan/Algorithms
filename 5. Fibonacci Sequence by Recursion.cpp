/*Time Complexity of this algorithm is O(2^n)*/

#include <iostream>
using namespace std;

int Fib(int n)
{
    if(n<=1)
    {
    	return 0;
	}
	if(n==2)
	{
		return 1;
	}
	
    return Fib(n-1) + Fib(n-2);
}

int main()
{
    int num = 0;

    cout << "Please tell for which number you want the Fibonacci sequence: ";
    cin >> num;

    int fibNum = Fib(num);
    cout << "\nFibonacci Number for " << num << " is " << fibNum << "\n";
}
