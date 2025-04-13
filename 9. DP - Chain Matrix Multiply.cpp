#include <iostream>
#include <stdlib.h>
using namespace std;

int ***m = new int**[10]{};
int *r = new int[10]{};
int *c = new int[10]{};
int dimensions[10];
int matrix[10][10]={0};
int keys[10][10]={0};
int count=0;

/*
int ***result = new int**[10]{};
int *resR = new int[10]{};
int *resC = new int[10]{};
int countRes=0;
int resultDim[10];*/

/*
int** multiplyMatrices(int **mat1, int **mat2, int mat1Cols, int mat2Cols)
{
    cout<<"Matrix 1 is: "<<mat1Cols<<"\t And matrix 2 is: "<<mat2Cols<<"\n";
    
	resR[countRes]=dimensions[mat1Cols-1];
	resultDim[countRes]=resR[countRes];
	resC[countRes]=dimensions[mat2Cols];
	resultDim[countRes+1]=resC[countRes];
	result[countRes] = new int*[resR[countRes]]{};
	for(int j=0; j<resR[countRes]; j++)
	{
		result[countRes][j] = new int[resC[countRes]]{};
	}
	
	for(int i=0; i<dimensions[mat1Cols-1]; i++)
	{
		for(int j=0; j<dimensions[mat2Cols]; j++)
		{
			for(int k=0; k<dimensions[mat1Cols-1]; k++)
			{
				result[countRes][i][j]+=mat1[i][k]*mat2[k][j];
			}
		}
	}
	dimensions[mat1Cols]=dimensions[mat2Cols];
	
	cout<<"\nWe are multiplying matrix "<<mat1Cols<<" and matrix "<<mat2Cols<<": \n";
	for(int i=0; i<dimensions[mat1Cols-1]; i++)
	{
		for(int j=0; j<dimensions[mat2Cols]; j++)
		{
			cout<<result[countRes][i][j]<<"\t";
		}
		cout<<"\n";
	}
	
	count=dimensions[mat1Cols-1];
	return result[countRes++];
}*/

/*
// Function to free the dynamically allocated memory for the 2D array
void free2DArray(int** dynamicArray, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] dynamicArray[i];
    }
    delete[] dynamicArray;
}*/

/*
int** multiply(int i, int j)
{
	if(i==j)
	{
		return m[i];
	}
	else
	{
		int k=keys[i][j];
		int t=k+1;
		int **x=multiply(i, k);
		int **y=multiply(k+1, j);
		return multiplyMatrices(x, y, k, t);
	}
}*/

/*Time complexity of this algorithm is O(n^3)*/
void chainMatrixMultiply(int n, int dim[])
{
	int j, min, q;
	
	for(int diff=1; diff<n; diff++)
	{
		for(int i=1; i<=n-diff; i++)
		{
			j=i+diff;
			min=32767;
			for(int k=i; k<j; k++)
			{
				q=matrix[i][k]+matrix[k+1][j]+dim[i-1]*dim[k]*dim[j];
				if(q<min)
				{
					min=q;
					keys[i][j]=k;
				}
			}
			matrix[i][j]=min;
		}
	}
	
	cout<<"\n\nThe minimum number of operations required for multiplication is: "<<matrix[1][n]<<"\n";
}

int main()
{
	int n, l;
	cout<<"How many matrices do you want to multiply: ";
	cin>>n;
	cout<<"\n";

	for(l=0; l<n; l++)
	{
		cout<<"Please enter the number of rows of matrix "<<l+1<<": ";
		cin>>r[l];
		dimensions[l]=r[l];
		cout<<"Please enter the number of columns of matrix "<<l+1<<": ";
		cin>>c[l];
		m[l] = new int*[r[l]]{};
		for(int j=0; j<r[l]; ++j)
		{
			m[l][j] = new int[c[l]]{};
		}
	}
	dimensions[l]=c[l-1];
	
	
	/*Obtaining values from user*/
	for(int i=0; i<n; ++i)
	{
		cout<<"\nEnter elements of Matrix "<<i+1<<endl;
		for(int j=0; j<r[i]; ++j)
		{
			cout<<"For Row "<<j+1<<": "<<endl;
			for(int k=0; k<c[i]; ++k)
			{
				cin>>m[i][j][k];
			}
		}
	}

	/*Finding best way of multiplying*/
	chainMatrixMultiply(n, dimensions);

	/*Printing values of matrices*/
	for(int i=0; i<n; ++i)
	{
		cout<<endl<<"Matrix "<<i + 1<<endl;
		for(int j=0; j<r[i]; ++j)
		{
			for(int k=0; k<c[i]; ++k)
			{
				cout<<m[i][j][k]<<"\t";
			}
			cout<<endl;
		}
	}
	
	//int** array=multiply(1, n);e
	
	//free2DArray(array, count);
	
    /* Deallocating memory to heap */
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < r[i]; ++j)
        {
            delete[] m[i][j];
        }
        delete[] m[i];
    }
    delete[] m;
    delete[] r;
    delete[] c;

}