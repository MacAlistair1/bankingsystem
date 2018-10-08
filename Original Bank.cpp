#include<iostream>
#include<fstream>
#include<conio.h>

using namespace std;

class Bank
{
		char name[30];
		char accname[20];
		char acctype[20];
		float ibalance;
		float depos;
		float with;
		int pass;
		
	public:
		void menu(void);
		void getdata(void);
		void deposite(void);
		void checkbal(void);
		void withdraw(void);
		void info(void);
};
	void Bank::menu()
	{
		int num;
	cout<<"\n\n\n\t********************************";
	cout<<"\n\t   Choose your Option:(1-to-6)\n"<<endl;
	cout<<"\t     1.Create An Account\n";
	cout<<"\t     2.Deposite the Balance\n";
	cout<<"\t     3.Check the Balance\n";
	cout<<"\t     4.Withdraw the Balance\n";
	cout<<"\t     5.See All Information\n";
	cout<<"\t     6.Quit";
	cout<<"\n\t********************************";
	cout<<"\t\n\t";cin>>num;
	switch(num)
	{
		case 1:
			getdata();
			break;
			
		case 2:
			deposite();
			break;
		
		case 3:
			checkbal();
			break;
			
		case 4:
			withdraw();
			break;
		
		case 5:
			info();
			break;
			
		default:
			break;
	}
	
	}
	
	void Bank::getdata()
	{
		int go;
		cout<<"\n\t\tEnter the Name of Depositer:";
		cin>>name;
		cout<<"\n\t\tChoose The Account Name:";
		cin>>accname;
		cout<<"\n\t\tWhich types of Account You wanna Create?\n";
		cout<<"\t\t\t\t*Saving\n";
		cout<<"\t\t\t\t*\n";
		cout<<"\t\t\t\t*\n";
		cout<<"\t\n\t";cin>>acctype;	
			cout<<"\n\t\tDeposite the Initial Balance:";
			cin>>ibalance;
			cout<<"\n\t\tChoose your password[0-9] for secure (only 4 nos.):";
			cin>>pass;
			cout<<"\n\n\t\tAccount Has Been Successfully Created!!!\n\n";
		cout<<"\n\t\tHit \'0\' for Go to MainMenu:";
			cin>>go;
			if(go==0)
			{
				menu();
			}
	}
	
	void Bank::deposite()
	{
		int go;
		cout<<"\n\t\tHow Much Money You wanna Deposite:\t";
		cin>>depos;
		depos+=ibalance;
		cout<<"\n\n\t\tYour Balance Has Been Successfully Deposite!!!\n\n";
	
	cout<<"\n\t\tHit \'0\' for Go to MainMenu:";
			cin>>go;
			if(go==0)
			{
				menu();
			}
	}
	
	void Bank::checkbal()
	{
		int passcode;
		cout<<"\n\t\tEnter your Account's Password: ";
		cin>>passcode;
		if(pass==passcode)
		{
		int go;
		cout<<"\n\t\tYour Current Balance:"<<" Rs."<<depos<<"\n";
		cout<<"\n\t\tHit \'0\' for Go to MainMenu:";
			cin>>go;
			if(go==0)
			{
				menu();
			}
		}
		else
			cout<<"\n\t\tSorry You Entered Wrong Password!!TRY AGAIN@";
	}
	
	void Bank::withdraw()
	{
			int passcode;
		cout<<"\n\t\tEnter your Account's Password: ";
		cin>>passcode;
		if(pass==passcode)
		{
		int go;
		cout<<"\n\t\tHow Much Money You wanna Withdraw:";
		cin>>with;
		depos-=with;
		cout<<"\n\t\tAfter Withdraw Your Balance:"<<" Rs."<<depos<<"\n";
		cout<<"\n\t\tHit \'0\' for Go to MainMenu:";
			cin>>go;
			if(go==0)
			{
				menu();
			}
		}
		else
			cout<<"\n\t\tSorry You Entered Wrong Password!!TRY AGAIN@";
	}
	
	void Bank::info()
	{
		int passcode;
		cout<<"\n\t\tEnter your Account's Password: ";
		cin>>passcode;
		if(pass==passcode)
		{
		int go;
		cout<<"\n\t\tAll Information is Listed Below:\n";
		cout<<"\t\t\tName of the Depositer:"<<name<<"\n";
		cout<<"\t\t\tName of the Account:"<<accname<<"\n";
		cout<<"\t\t\tType of the Account:"<<acctype<<"\n";
		cout<<"\t\t\tYour Current Amount:"<<depos<<"\n";
		cout<<"\n\t\tHit \'0\' for Go to MainMenu:";
			cin>>go;
			if(go==0)
			{
				menu();
			}
		}
		else
			cout<<"\n\t\tSorry You Entered Wrong Password!!TRY AGAIN@";
	}
	

int main()
{
	Bank Obj,ob1;
	fstream inout("Bank.txt",ios::in|ios::out);
    Obj.menu();
    inout.write((char *)&Obj,sizeof(Obj));
    inout.seekg(0,ios::beg);
    inout.read((char *)&ob1,sizeof(ob1));
    ob1.menu();
	getch();
	return 0;
}
