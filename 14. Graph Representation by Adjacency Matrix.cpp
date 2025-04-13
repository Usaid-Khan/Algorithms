#include <iostream>
using namespace std;

main()
{
	int v, e;
	char type;
	
	cout<<"Please tell that graph is directed or undirected? Tell by the letter d or u: ";
	cin>>type;	
	cout<<"Please enter the number of vertices: ";
	cin>>v;
	cout<<"Please enter the number of edges: ";
	cin>>e;
	
	int adjMatrix[v+1][v+1]={0};
	cout<<"Please enter the vertices which have edges between them:\n";

	for(int i=1; i<=e; i++)
	{
		int j, k;
		cout<<"node: ";
		cin>>j;
		cout<<"with ";
		cin>>k;
		adjMatrix[j][k]=1;
		if(type=='u')
		{
			adjMatrix[k][j]=1;
		}
	}
	
	cout<<"Adjacency Matrix is: \n\n";
	for(int i=1; i<=v; i++)
	{
		for(int j=1; j<=v; j++)
		{
			cout<<adjMatrix[i][j]<<"\t";
		}
		cout<<"\n";
	}
}