
//Write a menu driven program to calculate volume of the box.Provide neceesary
//constructors.

#include<iostream>

using namespace std;

typedef enum {EXIT,ACCEPT_BOX_PARAMETER,PRINT_BOX_VOLUME}MENUOP;


class Box_Volume
{
private:
	int length;
	int width;
	int height;
public:
	Box_Volume()
	{
		this->length=0;
		this->width=0;
		this->height=0;
	}

	Box_Volume(int l,int w,int h)
	{
		this->length=l;
		this->width=w;
		this->height=h;
	}

void Accept_box_parameters()
{
	cout<<"\nENTER LENGTH WIDTH AND HEIGHT IN (L W H) FORMAT :";
	cin>>this->length>>this->width>>this->height;
}

void Print_box_volume()
{
	cout<<"\nBOX_VOLUME_IS :"<<this->length * this->width * this->height<<endl<<endl ;
}

};

int menuChoice()
{
	int choice;
	cout<<"ENTER ANY CHOICE : \n";
	cout<<"0.EXIT \n1.ACCEPT_BOX_PARAMETER  \n2.PRINT_BOX_VOLUME"<<endl;
	cout<<"ENTER YOUR CHOICE :";
	cin>>choice;
	return choice;
}

int main()
{
	Box_Volume b;
	int choice;

		while((choice = menuChoice())!=EXIT)
		{
			switch(choice)
			{
			case ACCEPT_BOX_PARAMETER:
				b.Accept_box_parameters();
				break;
			case PRINT_BOX_VOLUME:
				b.Print_box_volume();
				break;
			default :
				cout<<"\nENTER VALID INPUT\n";
			}
		}

	return 0;
}
