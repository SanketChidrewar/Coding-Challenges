
#include<iostream>

using namespace std;

void fun(int x=10,int y=20,int z=30);
//void fun(int, int);

int main()
{
        fun(1,2);
        return 0;
}

void fun(int x,int y,int z)
{
        cout<<endl<<x<<endl<<y<<endl<<z;
}

void fun(int x,int y)
{
        cout<<endl<<x<<endl<<y;
}
/*
class Point
{
private:
        int xPos;
        int yPos;
public:
        Point(void)
        {
                this->xPos=0;
                this->yPos=0;

        }
        Point(int value)
        {
                this->xPos=value;
                this->yPos=0;

        }

        Point(int x,int y)
        {
                this->xPos=x;
                this->yPos=y;

        }
        void print()
        {
        	cout<<"\nxpos : "<<this->xPos;
        	cout<<"ypos : "<<this->yPos<<endl;
        }
};

int main()
{
        Point pt1(10,20);
        pt1.print();
        Point pt2=30;
        pt2.print();

        return 0;
}
*/

/*namespace na
{
int num1 = 10;
}
int main( void )
{
	int num1 = 20;
	using namespace na;
	cout<<"Num1 : "<<num1<<endl;
	cout<<"Num1 : "<<na::num1<<endl;
	return 0;
}*/
/*
class date
{

        int day,month,year;

        date()
        {
                day=25;
                month=4;
                year=2020;

        }
public:
        void printDate()
        {
                cout<<this->day<<"-"<<this->month<<"-"<<this->year<<endl;
        }
};

int main()
{
        date today;
        today.printDate();
       return 0;
}
*/
