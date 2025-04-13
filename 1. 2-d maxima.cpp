#include <iostream>
using namespace std;

class P{
	private:
		int x;
		int y;
		
	public:
		P()
		{
			x=y=0;
		}
		P(int x, int y)
		{
			this->x=x;
			this->y=y;
		}
		
		void setX(int x)
		{
			this->x=x;
		}
		int getX()
		{
			return x;
		}
		void setY(int y)
		{
			this->y=y;
		}
		int getY()
		{
			return y;
		}
};

P Plane_Sweep_Maxima(int n, P p[])
{
	
}

int main()
{
	P* p[11];
	
	p[1].setX(5);
	p[1].setY(1);
	
	p[2].setX(13);
	p[2].setY(3);
	
	p[3].setX(2);
	p[3].setY(5);
	
	p[4].setX(10);
	p[4].setY(5);
	
	p[5].setX(15);
	p[5].setY(7);
	
	p[6].setX(7);
	p[6].setY(7);
	
	p[7].setX(9);
	p[7].setY(10);
	
	p[8].setX(14);
	p[8].setY(10);
	
	p[9].setX(4);
	p[9].setY(11);
	
	p[10].setX(12);
	p[10].setY(12);
	
	p[11].setX(3);
	p[11].setY(13);
	
	
}