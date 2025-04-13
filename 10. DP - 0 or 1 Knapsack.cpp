/*Time complexity of this algorithm is O(n.W) means number of objects multiplied by knapsack weight limit*/

#include <iostream>
using namespace std;

int max(int a, int b)
{
	if(a==b)
	{
		return a;
	}
	else if(a<b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

int main()
{
	int objects, knapsack;
	cout<<"Please enter the number of objects: ";
	cin>>objects;
	cout<<"Please enter the weight of knapsack: ";
	cin>>knapsack;
	
	int k[objects+1][knapsack+1];
	int Profits[objects+1]={0};
	int Weights[objects+1]={0};
	cout<<"\nPlease enter the weights and profits of objects in increasing order.\n\n";
	for(int i=1; i<=objects; i++)
	{
		cout<<"Please enter the weight of an object "<<i<<": ";
		cin>>Weights[i];
		cout<<"Please enter the profit of an object "<<i<<": ";
		cin>>Profits[i];
	}
	
	for(int i=0; i<=objects; i++)
	{
		for(int w=0; w<=knapsack; w++)
		{
			if(i==0 || w==0)
			{
				k[i][w]=0;
			}
			else if(Weights[i]<=w)
			{
				k[i][w]=max(Profits[i]+k[i-1][w-Weights[i]], k[i-1][w]);
			}
			else
			{
				k[i][w]=k[i-1][w];
			}
		}
	}
	cout<<"\n\nOptimal Cost: "<<k[objects][knapsack]<<"\n\n";
	
	int i=objects, j=knapsack;
	while(i>0 && j>=0)
	{
		if(k[i][j]==k[i-1][j])
		{
			cout<<"Object "<<i<<": 0\n";
			i--;
		}
		else
		{
			cout<<"Object "<<i<<": 1\n";
			j=j-Weights[i];
			i--;
		}
	}
}