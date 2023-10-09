
#include<iostream>
#include<conio.h>
#include<vector>
#include<string>
#include<ctime>
#include <chrono>
#include <iomanip>
using namespace std;

struct transaction
{	
	int id;
	string type;
	string when;
	float amount;

};
class Bank
{
	char name[30];
	char accname[20];
	char acctype[20];
	float ibalance ;
	float depos;
	float with;
	int pass;
	float current_balance =0;
	vector<transaction> newTransaction;
	time_t now;
	int id_value = 0;
public:
	void menu(void);
	void getdata(void);
	void deposite(void);
	void checkbal(void);
	void withdraw(void);
	void info(void);
	void verifyUser(void);
	void addDepositsToTrs(void);
	void addWithdrawsToTrs(void);
	void transactionDetails(void);
};
void Bank::menu()
{	
	
	int i =0;
	int num;
	cout << "\n\n\n\t********************************";
	cout << "\n\t   Choose your Option:(1-to-6)\n" << endl;
	cout << "\t     1.Create An Account\n";
	cout << "\t     2.Deposite the Balance\n";
	cout << "\t     3.Check the Balance\n";
	cout << "\t     4.Withdraw the Balance\n";
	cout << "\t     5.See all account information\n";
	cout << "\t     6.See Transaction History";
	cout << "\n\t********************************";
	cout << "\t\n\t"; cin >> num;
	switch (num)
	{
	case 1:
		getdata();
		break;

	case 2:
		
		verifyUser();
		deposite();
		
		break;

	case 3:
		verifyUser();
		checkbal();
		break;

	case 4:
		verifyUser();
		withdraw();
		break;

	case 5:
		verifyUser();
		info();
		break;

	case 6:
		transactionDetails();
		break;
	default:
		cout << "\n\t\tInvalid option\n";
		break;
	}
	
	
	
}

void Bank::getdata()
{
	int go;
	cout << "\n\t\tEnter the Name of Depositer:";
	cin >> name;
	cout << "\n\t\tChoose The Account Name:";
	cin >> accname;
	cout << "\n\t\tWhich types of Account You wanna Create?\n";
	cout << "\t\t\t\t*Saving\n";
	cout << "\t\t\t\t*\n";
	cout << "\t\t\t\t*\n";
	cout << "\t\n\t"; cin >> acctype;
	cout << "\n\t\tDeposite the Initial Balance:";
	cin >> ibalance;
	Bank  ::current_balance = ibalance;
	cout << "\n\t\tChoose your password[0-9] for secure (only 4 nos.):";
	cin >> pass;
	cout << "\n\n\t\tAccount Has Been Successfully Created!!!\n\n";
	cout << "\n\t\tHit \'0\' for Go to MainMenu:";
	cin >> go;
	if (go == 0)
	{
		menu();
	}
}

void Bank::deposite()
{	
	int go; 
	
	cout << "\n\t\tHow Much Money You wanna Deposite:\t";
	cin >> depos;
	Bank ::current_balance = current_balance + depos;
	cout << "\n\n\t\tYour Balance Has Been Successfully Deposite!!!\n\n";	
	cout << "\n\t\tHit \'0\' for Go to MainMenu:";
	now = time(0);
	id_value++;
	addDepositsToTrs();
	cin >> go;
	if (go == 0)
	{
		menu();
	}
}

void Bank::checkbal()
{	
	
	int go;
	cout << "\n\t\tYour Current Balance:" << " RF." << current_balance << "\n";
	cout << "\n\t\tHit \'0\' for Go to MainMenu:";
	cin >> go;
	if (go == 0)
	{
		menu();
	}
}

void Bank::withdraw()
{
		int go;
		cout << "\n\t\tHow Much Money You wanna Withdraw:";
		cin >> with;
		now = time(0);
		id_value++;
		Bank  ::current_balance = current_balance - with;
		addWithdrawsToTrs();
		cout << "\n\t\tAfter Withdraw Your Balance:" << " Rs." << current_balance << "\n";
		cout << "\n\t\tHit \'0\' for Go to MainMenu:";
		cin >> go;
		if (go == 0)
		{
			menu();
		}
	}


void Bank::addDepositsToTrs() {
	transaction deposit;
	deposit.amount = depos;
	deposit.type = "Deposited";
	deposit.when = ctime(&now);
	deposit.id = id_value;
	newTransaction.push_back(deposit);
}

void Bank::addWithdrawsToTrs() {
	transaction withdraw;
	withdraw.amount = with;
	withdraw.type = "Withdrawn";
	withdraw.when = ctime(&now);
	withdraw.id = id_value;
	newTransaction.push_back(withdraw);
}
	

void Bank::info()
{	
		int go;
		cout << "\n\t\tAll Information is Listed Below:\n";
		cout << "\t\t\tName of the Depositer:" << name << "\n";
		cout << "\t\t\tName of the Account:" << accname << "\n";
		cout << "\t\t\tType of the Account:" << acctype << "\n";
		cout << "\t\t\tYour Current Amount:" << current_balance << "\n";
		cout << "\n\t\tHit \'0\' for Go to MainMenu:";
		cin >> go;
		if (go == 0)
		{
			menu();
		}
	}
	

void Bank :: verifyUser() {
	int tempPin;
	cout << "\n\t\tEnter your accounts pin :";
	cin >> tempPin;
	
	if (tempPin == pass) {
		cout << "\n\t\tEnjoy your our service\n";	
	}
	else {
		do{
			cout << "\n\t\tInvalid Pind : Enter your accounts pin again : ";
			cin >> tempPin;
			if (tempPin == pass) {
				cout << "\n\t\tEnjoy your our service\n";
			}
			else {
				cout << "\n\t\tIncorrect Pin\n";
				menu();
			}
		} while (tempPin != pass);
		{
			cout << "\n\t\tEnjoy your our service\n";
		}
	}

}


void Bank::transactionDetails() {
	cout << "\n\t\tYour Transaction History \n";
	for (vector<transaction>::iterator p = newTransaction.begin(); p != newTransaction.end(); ++p)
		cout << " Transaction ID : #" << p->id <<"\n"<<
		"\n\t\tYou have " << p->type << " RF : " << p->amount << " on : " << p->when ;
	menu();
}
int main()
{
	Bank Obj;
	Obj.menu();
	
	_getch();
	return 0; 
}
