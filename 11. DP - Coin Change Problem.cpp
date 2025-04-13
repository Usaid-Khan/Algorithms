/*Time complexity of this algorithm is O(n*a) means number of coins multiplied by the amount*/

#include <iostream>
using namespace std;

int min(int a, int b)
{
	if(a==b)
	{
		return a;
	}
	else if(a<b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

void coinChangeProblem(int amount, int coins[], int dom)
{
	int table[dom+1][amount+1];
	for(int i=0; i<=dom; i++)
	{
		for(int j=0; j<=amount; j++)
		{
			if(j==0)
			{
				table[0][j]=0;
			}
			if(i==0)
			{
				table[i][j]=j;
			}
			else if(coins[i-1]>j)
			{
				table[i][j]=table[i-1][j];
			}
			else
			{
				table[i][j]=min(table[i-1][j], 1+table[i][j-coins[i-1]]);
			}
		}
	}
	cout<<"\nNumber of dominations required to change this coin is: "<<table[dom][amount]<<"\n\n";
	
	int i=dom, j=amount;
	while(table[i][j]>0)
	{
    	while(table[i][j]==table[i-1][j])
    	{
        	i--;
    	}
	    cout<<"Number "<<coins[i-1]<<" is included\n";
	    j=j-coins[i-1];
	}
}
              
int main()
{
	int noOfDom, amount;
	cout<<"Please enter the amount which you want to transfer: ";
	cin>>amount;
	cout<<"Please enter the number of dominations: ";
	cin>>noOfDom;
	int coins[noOfDom];
	cout<<"\nInsert dominations one by one.\n";
	for(int i=0; i<noOfDom; i++)
	{
		cin>>coins[i];
	}
	
	coinChangeProblem(amount, coins, noOfDom);
}