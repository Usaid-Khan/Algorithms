/*Time complexity of this algorithm is O(n^2)*/

#include <iostream>
#include <string.h>
#include <cstring>
#include <stdlib.h>
using namespace std;

class String{
	private:
		string str;
		
	public:
		String(string str)
		{
			
			this->str=str;
		}
		
		int getLength()
		{
			return str.length();
		}
		char charAt(int index)
		{
			return str[index];
		}
};

class Minimum{
	public:
		int min(int a, int b, int c)
		{
			if(a<=b && a<=c)
			{
				return a;
			}
			else if(b<=a && b<=c)
			{
				return b;
			}
			else
			{
				return c;
			}
		}
};

class Solution{
	public:
		int editDistance(String, String);
};

int Solution::editDistance(String a, String b)
{
	int m=a.getLength();
	int n=b.getLength();
	int matrix[m+1][n+1];
	Minimum math;
	
	for(int i=0; i<=m; i++)
	{
		matrix[0][i]=i;
	}
	for(int j=0; j<=n; j++)
	{
		matrix[j][0]=j;
	}
	
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(a.charAt(i-1)==b.charAt(j-1))
			{
				matrix[i][j]=matrix[i-1][j-1];
			}
			else
			{
				matrix[i][j]=math.min(matrix[i][j-1], matrix[i-1][j], matrix[i-1][j-1])+1;
			}
		}
	}
	return matrix[m][n];
}

int main()
{
	String strA("algorithm");
	String strB("altruistic");
	Solution s;
	
	int minDistance=s.editDistance(strA, strB);
	
	cout<<"Minimum edit transcript between two strings is: "<<minDistance<<"\n";
}