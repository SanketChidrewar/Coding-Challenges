
/*Create a user defined class “PasswordMismatch” , throw exception
if user enters wrong password.*/

#include<iostream>

using namespace std;

class PasswordMismatch
{

};

void check_pass(string pass)throw(PasswordMismatch);


class Password
{
private:
	string pass;
public:
	Password()
{
}
	const string& getPass() const {
		return pass;
	}

	void setPass(const string& pass) {
		this->pass = pass;
	}

};

void check_pass(string pass)throw(PasswordMismatch)
{
	string pas;
	cout<<"ENTER PASS TO CHECK :";
	cin>>pas;

	if(pass != pas )
	{
		throw PasswordMismatch();
	}
	else
		cout<<"\n PASSWORD IS MATCHED \n";
}

int main()
{
	Password();
	string pass;
	Password p;
	cout<<"ENTER PASSWORD WHICH U WANT TO SET :";
	cin>>pass;
	p.setPass(pass);

	try
	{
		check_pass(p.getPass());
	}
	catch(PasswordMismatch pm)
	{
		cerr<<"PasswordMismatch";
	}
	catch(...)
	{
		cout<<"\nWITHIN GENERALISE CATCH BLOCK\n";
	}

	return 0;
}
