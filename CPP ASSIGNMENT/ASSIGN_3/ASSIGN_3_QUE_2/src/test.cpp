
/*2] Write a Matrix class. Allocate memory dynamically in parameterized constructor.
Also write paramterless constructor. Write Accept () and Print () functions.
Also provide Add(), Subtract(), Multiply() and Transpose() function.*/


#include<iostream>

using namespace std;

class Matrix
{
	int row;
	int column;
	int *mat;

public:
	Matrix()
	{
		this->row=0;
		this->column=0;
		this->mat=NULL;
	}
	Matrix(int row,int column)
	{
		this->row=row;
		this->column=column;
		this->mat = new int[this->row * this->column];
	}

	void Get_Matrix_values()
	{
		int val;
		for(int i=0;i<this->row;i++)
		{
			for(int j=0;j<this->column;j++)
			{
				cin>>val;
				*(mat + i*this->column + j) = val;
			}
		}
	}

	void Print_Matrix_values()
	{
		int val;
		for(int i=0;i<this->row;i++)
		{
			for(int j=0;j<this->column;j++)
			{
				val =*(mat + i*this->column + j);
				cout<<val<<" ";
			}
			cout<<"\n";
		}
	}

	void Add(Matrix *p1,Matrix *p2)
	{
		int val;
		int *ptr1 = p1->mat;
		int *ptr2 = p2->mat;
		if((p1->row == p2->row) && (p1->column == p2->column))
		{
		//int *add_mat = new int[p1->row * p2->column];

		for(int i=0;i<this->row;i++)
		{
			for(int j=0;j<this->column;j++)
			{
				val = *(ptr1 + i*this->column + j) + *(ptr2 + i*this->column + j);
				//*(add_mat + i*this->column + j) = val;
				cout<<val<<" ";
			}
			cout<<"\n";
		}

		}
		else
		{
			cout<<"ADDITION IS NOT POSSIBLE DUE TO DIFF DIAMENSION"<<endl;
		}
	}

	void Sub(Matrix *p1,Matrix *p2)
	{
		int val;
		int *ptr1 = p1->mat;
		int *ptr2 = p2->mat;
		if((p1->row == p2->row) && (p1->column == p2->column))
		{
		//int *add_mat = new int[p1->row * p2->column];

		for(int i=0;i<this->row;i++)
		{
			for(int j=0;j<this->column;j++)
			{
				val = *(ptr1 + i*this->column + j) - *(ptr2 + i*this->column + j);
				//*(add_mat + i*this->column + j) = val;
				cout<<val<<" ";
			}
			cout<<"\n";
		}

		}
		else
		{
			cout<<"ADDITION IS NOT POSSIBLE DUE TO DIFF DIAMENSION"<<endl;
		}
	}

	void Mul(Matrix *p1,Matrix *p2)
	{
		int val;
		int *ptr1 = p1->mat;
		int *ptr2 = p2->mat;
		if(p1->column == p2->row)
		{
		//int *add_mat = new int[p1->row * p2->column];

		for(int i=0;i<this->column;i++)
		{
			for(int j=0;j<this->column;j++)
			{
				val =0;
				for(int k=0;k<this->column;k++)
				{
				val += *(ptr1 + i*this->column + k) * *(ptr2 + k*this->column + j);
				//*(add_mat + i*this->column + j) = val;
				}
				cout<<val<<" ";
			}
			cout<<"\n";
		}

		}
		else
		{
			cout<<"ADDITION IS NOT POSSIBLE DUE TO DIFF DIAMENSION"<<endl;
		}
	}


	void Transpose()
	{
		int val;
		for(int i=0;i<this->column;i++)
		{
			for(int j=0;j<this->row;j++)
			{
				val = *(this->mat + j*this->column + i);
				cout<<val<<" ";
			}
			cout<<"\n";
		}
	}
};

int main()
{
	int row,column;
	cout<<"ENTER ROW OF 1st Matrix :";
	cin>>row;
	cout<<"ENTER COLUMN OF 1st Matrix :";
	cin>>column;
	Matrix m1(row,column);
	m1.Get_Matrix_values();
	//m1.Print_Matrix_values();

	cout<<"ENTER ROW OF 2nd Matrix :";
	cin>>row;
	cout<<"ENTER COLUMN OF 2nd Matrix :";
	cin>>column;
	Matrix m2(row,column);
	m2.Get_Matrix_values();
	//m2.Print_Matrix_values();
	cout<<"ADDITION OF TWO MATRIX IS : \n";
	m1.Add(&m1,&m2);

	cout<<"SUBTRACTION OF TWO MATRIX IS :\n";
	m1.Sub(&m1,&m2);

	cout<<"MULTIPLICATION OF TWO MATRIX IS :\n";
	m1.Mul(&m1,&m2);

	cout<<"TRANSPOSE OF FIRST MATRIX IS :\n";
	m1.Transpose();

	cout<<"TRANSPOSE OF SECOND MATRIX IS :\n";
	m2.Transpose();

	return 0;
}
