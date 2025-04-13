/*Time Complexity of this algorithm is O(nlogn).*/

#include <iostream>
using namespace std;

class Events{
	private:
		float start;
		float finish;
		
	public:
		Events()
		{
			this->start=0.0;
			this->finish=0.0;
		}
		
		void setStart(float start)
		{
			this->start=start;
		}
		float getStart()
		{
			return start;
		}
		void setFinish(float finish)
		{
			this->finish=finish;
		}
		float getFinish()
		{
			return finish;
		}
};

void swap(Events Arr[], int firstIndex, int secIndex)
{
    Events temp=Arr[firstIndex];
    Arr[firstIndex]=Arr[secIndex];
    Arr[secIndex]=temp;
}

int partition(Events A[], int sIndex, int eIndex)
{
	float pivot=A[sIndex].getFinish();
	int q=sIndex;
	
	for(int s=sIndex+1; s<=eIndex; s++)
	{
		if(A[s].getFinish() < pivot)
		{
			++q;
			swap(A, q, s);
		}
	}
	swap(A, sIndex, q);
	
	return q;
}

void quickSort(Events A[], int start, int end)
{
	int random, pivot;
	
	if(end>start)
	{
		pivot=partition(A, start, end);
		quickSort(A, start, pivot-1);
		quickSort(A, pivot+1, end);
	}
}

void schedule(Events events[], int n)
{
	quickSort(events, 0, n-1);
	Events A[n];
	A[0]=events[0];
	int prev=0, count=0;
	
	for(int i=1; i<n; i++)
	{
		if(events[i].getStart() > events[prev].getFinish())
		{
			A[++count]=events[i];
			prev=i;
		}
	}
	
	cout<<"Following "<<count+1<<" activities will perform:\n\n";
	for(int i=0; i<=count; i++)
	{
		cout<<A[i].getStart()<<" to ";
		cout<<A[i].getFinish()<<"\n";
	}
}

main()
{
	Events ev[8];
	
	ev[0].setStart(12.9);
	ev[0].setFinish(14.5);
	
	ev[1].setStart(7.4);
	ev[1].setFinish(9.9);
	
	ev[2].setStart(3.2);
	ev[2].setFinish(5.5);
	
	ev[3].setStart(13.2);
	ev[3].setFinish(14.8);
	
	ev[4].setStart(13.1);
	ev[4].setFinish(13.7);
	
	ev[5].setStart(1.2);
	ev[5].setFinish(4.4);
	
	ev[6].setStart(0.8);
	ev[6].setFinish(5.6);
	
	ev[7].setStart(16.7);
	ev[7].setFinish(18.9);
	
	schedule(ev, 8);
}