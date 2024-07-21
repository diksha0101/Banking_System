#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <fstream>

using namespace std;

void changeColor(int desiredColor);

void introduction()
{

	changeColor(11);
	cout << endl << endl;
	cout << "\t\t\t\t\tBANK MANAGEMENT SYSTEM " << endl << endl;
	cout << "\n\n\t";
	system("pause");
	system("cls");

}

class Bank
{
protected:


	long long acc_bal = {};
	char pass[20] = {};
	char pin[20] = {};
	string acc_id, name, fath_name, ph_num, email, ho, st, se, city, acc_num;

public:

	void new_user();
	void already_user();
	void deposit();
	void withdraw();
	void search();
	void update();
	void del_record();
	void show_all_records();


};

class ATM :public Bank
{

public:
	void user_balance_atm();
	void withdraw();
	void check_details_atm();

};

class Management :public ATM
{
public:

	ATM a;
	Bank b;

	void menu();
	void bank_management();
	void atm_management();

};

void Management::menu()
{
A:

	system("cls");
	changeColor(10);
	int choice{};
	string email, pass, pin;
	char ch;
	cout << "\n\n\t\t\tControl Panel";
	cout << "\n\n\n\n\t1. Bank Management";
	cout << "\n\n\t2. ATM Management";
	cout << "\n\n\t3. Exit";
	cout << "\n\n\tEnter Your Choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	

		system("cls");
		changeColor(11);
		cout << "\n\n\t\t\tAccount Login";
		cout << "\n\n\n\n\tE-mail: ";
		cin >> email;
		cout << "\n\n\n\n\tPassword (5 Characters Only): ";
		for (int i = 0; i < 5; i++)
		{
			ch = _getch();
			pass += ch;
			cout << "*";
		}
		cout << "\n\n\n\n\tPin (5 Digits Only): ";
		for (int b = 0; b < 5; b++)
		{
			ch = _getch();
			pin += ch;
			cout << "*";
		}
		if (email == "user@gmail.com" && pass == "user" && pin == "1111")
		{
			bank_management();
		}
		else
		{
			changeColor(12);
			cout << "\n\n\n\n\tYour E-mail, Password & Pin is Wrong....";
			system("pause");
			goto A;
		}

		break;

	case 2:

		atm_management();
		break;

	case 3:

		exit(0);

	default:

		changeColor(12);
		cout << "\n\n\tInvalid Value...Please Try Again....";
	}
	_getch();
	goto A;
}

void Management::bank_management()
{
A:

	system("cls");
	int choice;
	changeColor(10);
	cout << "\n\n\t\t\tBank Management System";
	cout << "\n\n\n\n\t1. Add New User";
	cout << "\n\n\t2. Already User";
	cout << "\n\n\t3. Deposit Money";
	cout << "\n\n\t4. Withdraw Money";
	cout << "\n\n\t5. Search User Record";
	cout << "\n\n\t6. Update User Record";
	cout << "\n\n\t7. Delete User Record";
	cout << "\n\n\t8. Show All Records";
	cout << "\n\n\t9. Go Back";
	cout << "\n\n\tEnter Your Choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:

		new_user();
		break;

	case 2:

		already_user();
		break;

	case 3:

		deposit();
		break;

	case 4:

		b.withdraw();
		break;

	case 5:

		search();
		break;

	case 6:

		update();
		break;

	case 7:

		del_record();
		break;

	case 8:

		show_all_records();
		break;

	case 9:

		menu();

	default:

		changeColor(12);
		cout << "\n\n\tInvalid Value...Please Try Again....";

	}

	_getch();

	goto A;


}

void Management::atm_management()
{
A:

	system("cls");
	int choice;
	changeColor(10);
	cout << "\n\n\t\t\tATM Management System";
	cout << "\n\n\n\n\t1. User Login & Check Balance";
	cout << "\n\n\t2. Withdraw Amount";
	cout << "\n\n\t3. Account Details";
	cout << "\n\n\t4. Go Back";
	cout << "\n\n\tEnter Your Choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:

		user_balance_atm();
		break;

	case 2:

		a.withdraw();//
		break;

	case 3:

		check_details_atm();
		break;

	case 4:

		menu();


	default:

		changeColor(12);
		cout << "\n\n\tInvalid Value...Please Try Again....";

	}

	_getch();
	goto A;
}

void Bank::new_user()
{
A:
	Management c;
	system("cls");
	int option = {};
	changeColor(10);
	cout << "\n\n\n\n\tSelect Account Type";
	cout << "\n\n\t01. Current Account (Initial Amount > 1000) ";
	cout << "\n\n\t02. Go Back ";
	cout << "\n\n\tPlease Select the Option: ";
	cin >> option;

	if (option == 1)
	{
		int flag = 0;
		int flag1 = 0;
		int flag2 = 0;
		system("cls");
		fstream file;
		//string id = {};

		long long bal = {};

		char pa[20] = {};
		char pi[20] = {};

		string id, n, fn, cn, pn, em, h, s, so, cit, /*pa, pi,*/ an;

		changeColor(10);

		cout << "\n\n\n\n\tCurrent Account ";

		cout << "\n\n\tAccount ID: ";
		cin >> acc_id;
		cout << "\n\n\tName: ";
		cin >> name;
		cout << "\n\n\tFather Name: ";
		cin >> fath_name;
	
		cout << "\n\n\tPhone Number: ";
		cin >> ph_num;
		cout << "\n\n\tE-mail: ";
		cin >> email;
		cout << "\n\n\tAddress: ";
		cout << "\n\n\tHouse No: ";
		cin >> ho;
	
		cout << "\n\tSector: ";
		cin >> se;
		cout << "\n\tCity: ";
		cin >> city;
	B:
		changeColor(10);
		cout << "\n\n\tPassword (5 Characters Only): ";
		cin >> pass;
		if (strlen(pass) == 5)
		{
			flag = 1;
		}

		if (flag == 0)
		{
			changeColor(12);
			cout << "\n\n\tInvalid Password Length Try Again...";
			cout << endl;
			goto B;

		}
	C:
		changeColor(10);

		cout << "\n\n\tPin (5 Digits Only): ";
		cin >> pin;
		if (strlen(pin) == 5)
		{
			flag1 = 1;
		}

		if (flag1 == 0)
		{
			changeColor(12);
			cout << "\n\n\tInvalid Pin Length Try Again...";
			cout << endl;
			goto C;

		}
		changeColor(10);
		cout << "\n\n\tAccount Number: ";
		cin >> acc_num;

	M:
		changeColor(10);
		cout << "\n\n\tAccount Balance: ";
		cin >> acc_bal;

		if (acc_bal > 1000)
		{
			flag2 = 1;
		}

		if (flag2 == 0)
		{
			changeColor(12);
			cout << "\n\n\tInvalid Initial Amount ..";
			cout << endl;
			goto M;

		}
		changeColor(10);

		file.open("bank.txt", ios::in);

		if (!file)
		{
			file.open("bank.txt", ios::app | ios::out);

			file << " " << acc_id << " " << name << " " << fath_name << " " <<  " " << ph_num << " " << email << " " << ho <<    " " << se << " " << city << " " << pass << " " << pin << " " << acc_num << " " << acc_bal << "\n";
			file.close();
		}

		else
		{
			file >> id >> n >> fn >> cn >> pn >> em >> h >> s >> so >> cit >> pa >> pi >> an >> bal;
			while (!file.eof())
			{
				if (id == acc_id || pn == ph_num  || an == acc_num || em == email)
				{
					changeColor(12);
					cout << "\n\n\tUser Already Exis ..";
					_getch();
					goto A;
				}

				file >> id >> n >> fn >> cn >> pn >> em >> h >> s >> so >> cit >> pa >> pi >> an >> bal;


			}

			file.close();
			file.open("bank.txt", ios::app | ios::out);
			file << " " << acc_id << " " << name << " " << fath_name << " "  << " " << ph_num << " " << email << " " << ho <<    " " << se << " " << city << " " << pass << " " << pin << " " << acc_num << " " << acc_bal << "\n";

			file.close();
		}


		changeColor(10);

		cout << "\n\n\tNew User Account Created Successfully...";


	}


	if (option == 2)
	{
		c.bank_management();
	}

}

void Bank::already_user()
{

	system("cls");
	fstream file;

	string t_id = {};
	int found = 0;

	cout << "\n\n\t\t\tAlready User Account";
	file.open("bank.txt", ios::in);
	if (!file)
	{
		changeColor(12);
		cout << "\n\n\n\tNo Database Found ";
	}
	else
	{
		changeColor(10);
		cout << "\n\n\n\n\tUser Account ID: ";
		cin >> t_id;
		file >> acc_id >> name >> fath_name >> ph_num >> email >> ho >>    se >> city >> pass >> pin >> acc_num >> acc_bal;
		while (!file.eof())
		{
			if (t_id == acc_id)
			{
				cout << "\n\n\tPassword            :  " << pass << endl;
				cout << "\n\n\tPin                 :  " << pin << endl;
				cout << "\n\n\tBalance             :  " << acc_bal << endl;
				found++;


			}
			file >> acc_id >> name >> fath_name >>  ph_num >> email >> ho >>    se >> city >> pass >> pin >> acc_num >> acc_bal;
		}

		file.close();
		if (found == 0)
		{
			changeColor(12);
			cout << "\n\n\tUser ID not Found...";

		}

	}


}

void Bank::deposit()
{


	fstream file, file1;
	string t_id = {};
	long long dep_amo = {};
	int found = 0;
	long long a = {};


	system("cls");
	cout << "\n\n\t\t\t\tDeposit Amount Option";

	file.open("bank.txt", ios::in);
	if (!file)
	{
		changeColor(12);
		cout << "\n\n\n\tNo Database Found ";
	}

	else
	{
		changeColor(10);
		cout << "\n\n\n\n\tUser Account ID: ";
		cin >> t_id;
		file1.open("bank1.txt", ios::app | ios::out);
		file >> acc_id >> name >> fath_name >> 
		 ph_num >> email >> ho >>    se >> city >> pass >> pin >> acc_num >> acc_bal;
		while (!file.eof())
		{
			if (t_id == acc_id)
			{
				cout << "\n\n\tDeposit Amount: ";
		
				cin >> dep_amo;
				a = dep_amo;
				acc_bal += dep_amo;
				file1 << " " << acc_id << " " << name << " " << fath_name << " "<< " " << ph_num << " " << email << " " << ho <<    " " << se << " " << city << " " << pass << " " << pin << " " << acc_num << " " << acc_bal << "\n";

				found++;

				cout << "\n\n\tYour Amount: " << a << " Successfully Deposited";
				cout << endl;
				cout << "\n\n\tYour Account Balance is: " << acc_bal;

				changeColor(11);
				cout << endl;
				
			}
			else
			{

				file1 << " " << acc_id << " " << name << " " << fath_name << " " << " " << ph_num << " " << email << " " << ho <<    " " << se << " " << city << " " << pass << " " << pin << " " << acc_num << " " << acc_bal << "\n";


			}

			file >> acc_id >> name >> fath_name >> ph_num >> email >> ho >>    se >> city >> pass >> pin >> acc_num >> acc_bal;


		}

		file.close();
		file1.close();

		remove("bank.txt");

		rename("bank1.txt", "bank.txt");




		if (found == 1)
		{
			file.open("deposit.txt", ios::app | ios::out);
			file << t_id << " " << a << " "  "\n";
			file.close();
			file.close();
		}


		if (found == 0)
		{
			changeColor(12);
			cout << "\n\n\tUser ID not Found...";

		}

	}

}

void Bank::withdraw()
{
	fstream file, file1;
	string t_id = {};
	long long with_amo = {};
	//float b = {};
	int found = 0;


	system("cls");
	cout << "\n\n\t\t\t\tWithdraw Amount Option";
	file.open("bank.txt", ios::in);
	if (!file)
	{
		changeColor(12);
		cout << "\n\n\n\tNo Database Found ";
	}

	else
	{
		changeColor(10);
		cout << "\n\n\n\tUser Account ID: ";
		cin >> t_id;
		file1.open("bank1.txt", ios::app | ios::out);
		file >> acc_id >> name >> fath_name  >> ph_num >> email >> ho >>    se >> city >> pass >> pin >> acc_num >> acc_bal;
		while (!file.eof())
		{
			if (t_id == acc_id)
			{
				cout << endl;
				cout << "\n\tWithdraw Amount: ";
				cin >> with_amo;
				if (with_amo <= acc_bal)
				{

					acc_bal -= with_amo;
					file1 << " " << acc_id << " " << name << " " << fath_name <<  " " << ph_num << " " << email << " " << ho <<    " " << se << " " << city << " " << pass << " " << pin << " " << acc_num << " " << acc_bal << "\n";

					changeColor(10);
					cout << "\n\n\tYour Amount: " << with_amo << " Successfully Withdraw";
					cout << endl;
					cout << "\n\n\tYour Account Balance is: " << acc_bal;
					changeColor(11);
					cout << endl;
					

				}

				else
				{
					file1 << " " << acc_id << " " << name << " " << fath_name << " " << " " << ph_num << " " << email << " " << ho <<    " " << se << " " << city << " " << pass << " " << pin << " " << acc_num << " " << acc_bal << "\n";

					changeColor(12);
					cout << "\n\n\tYour Current Balance is Low....";
					cout << endl;
					cout << "\n\n\tYour Current Balance is: " << acc_bal;






				}


				found++;


			}


			else
			{

				file1 << " " << acc_id << " " << name << " " << fath_name << " " <<  " " << ph_num << " " << email << " " << ho <<    " " << se << " " << city << " " << pass << " " << pin << " " << acc_num << " " << acc_bal << "\n";


			}
			file >> acc_id >> name >> fath_name  >> ph_num >> email >> ho >>    se >> city >> pass >> pin >> acc_num >> acc_bal;


		}

		file.close();
		file1.close();
		remove("bank.txt");

		rename("bank1.txt", "bank.txt");

		if (found == 1)
		{
			file.open("withdrawal.txt", ios::app | ios::out);
		

			file << t_id << " " << with_amo << "\n";
			file.close();
		
			file.close();

		}

		if (found == 0)
		{
			changeColor(12);
			cout << "\n\n\tUser ID not Found...";

		}


	}

}

void Bank::search()
{
	system("cls");
	fstream file;
	string t_id;
	int found = 0;
	cout << "\n\n\t\t\t\tSearch User Record";
	file.open("bank.txt", ios::in);
	if (!file)
	{
		changeColor(12);
		cout << "\n\n\n\t\t\tNo Database Found";
	}
	else
	{
		changeColor(10);
		cout << "\n\n\n\t""User Account ID: ";
		cin >> t_id;
		file >> acc_id >> name >> fath_name  >> ph_num >> email >> ho >>    se >> city >> pass >> pin >> acc_num >> acc_bal;
		while (!file.eof())
		{
			if (t_id == acc_id)
			{
				system("cls");
				cout << "\n\n\n\tUser Account Details" << endl << endl;
				cout << endl;
				cout << "\tAccount ID                                     :  " << acc_id << endl << endl;
				cout << "\tName                                           :  " << name << endl << endl;
				cout << "\tFather Name                                    :  " << fath_name << endl << endl;
			
				cout << "\tPhone Number:  " << ph_num << endl << endl;
				cout << "\tE-mail                                         :  " << email << endl << endl;
				cout << "\tAddress: " << endl << endl;
				cout << "\tHouse No                                       :  " << ho << endl << endl;
			
				cout << "\tSector                                         :  " << se << endl << endl;
				cout << "\tCity                                           :  " << city << endl << endl;
				cout << "\tPassword (5 Characters Only)                   :  " << pass << endl << endl;
				cout << "\tPin (5 Digits Only)                            :  " << pin << endl << endl;
				cout << "\tAccount Number                                 :  " << acc_num << endl << endl;
				cout << "\tAccount Balance                                :  " << acc_bal << endl << endl;


				found++;
			}
			file >> acc_id >> name >> fath_name >> ph_num >> email >> ho >>    se >> city >> pass >> pin >> acc_num >> acc_bal;
		}
		file.close();
		if (found == 0)
		{
			changeColor(12);
			cout << "\n\n\tUser ID not Found...";
		}
	}
}

void Bank::update()
{
	int flag = 0;
	int flag1 = 0;
	system("cls");
	fstream file, file1;
	char pa[20] = {};
	char pi[20] = {};
	string t_id, n, fn, cn, pn, em, ad, h, s, so, cit,an;
	float ba = {};
	int found = 0;
	cout << "\n\n\t\t\tUpdate User Record";
	file.open("bank.txt", ios::in);
	if (!file)
	{
		changeColor(12);
		cout << "\n\n\n\t\t\tNo Database Found";
	}
	else

	{
		changeColor(10);
		cout << "\n\n\n\tUser Account ID: ";
		cin >> t_id;
		file1.open("bank1.txt", ios::app | ios::out);
		file >> acc_id >> name >> fath_name >> ph_num >> email >> ho >>    se >> city >> pass >> pin >> acc_num >> acc_bal;

		while (!file.eof())
		{
			if (t_id == acc_id)
			{
				changeColor(11);
				cout << "\n\n\n\tPrevious User Account Data" << endl << endl;
				cout << "\tAccount ID                                     :  " << acc_id << endl << endl;
				cout << "\tName                                           :  " << name << endl << endl;
				cout << "\tFather Name                                    :  " << fath_name << endl << endl;
				cout << "\tPhone Number  :  " << ph_num << endl << endl;
				cout << "\tE-mail                                         :  " << email << endl << endl;
				cout << "\tAddress: " << endl << endl;
				cout << "\tHouse No                                       :  " << ho << endl << endl;
	
				cout << "\tSector                                         :  " << se << endl << endl;
				cout << "\tCity                                           :  " << city << endl << endl;
				cout << "\tPassword (5 Characters Only)                   :  " << pass << endl << endl;
				cout << "\tPin (5 Digits Only)                            :  " << pin << endl << endl;
				cout << "\tAccount Number                                 :  " << acc_num << endl << endl;
				cout << "\tAccount Balance                                :  " << acc_bal << endl << endl;

				changeColor(10);
				cout << "\n\n\n\tEnter New User Account Data";
				cout << "\n\n\tName: ";
				cin >> n;
				cout << "\n\n\tFather Name: ";
				cin >> fn;
		
				cout << "\n\n\tPhone Number";
				cin >> pn;
				cout << "\n\n\tE-mail: ";
				cin >> em;
				cout << "\n\n\tAddress: ";
				cout << "\n\n\tHouse No: ";
				cin >> h;
			
				cout << "\n\tSector: ";
				cin >> so;
				cout << "\n\tCity: ";
				cin >> cit;
			B:
				changeColor(10);
				cout << "\n\n\tPassword (5 Characters Only): ";
				cin >> pa;
				if (strlen(pa) == 5)
				{
					flag = 1;
				}

				if (flag == 0)
				{
					changeColor(12);
					cout << "\n\n\tInvalid Password Length Try Again...";
					cout << endl;
					goto B;

				}
			F:
				changeColor(10);
				cout << "\n\n\tPin (5 Digits Only): ";
				cin >> pi;
				if (strlen(pi) == 5)
				{
					flag1 = 1;
				}

				if (flag1 == 0)
				{
					changeColor(12);
					cout << "\n\n\tInvalid Pin Length Try Again...";
					cout << endl;
					goto F;

				}
				//cout << "\n\n\tAccount Number: ";
				//cin >> an;

				file1 << " " << acc_id << " " << n << " " << fn <<  " " << pn << " " << em << " " << h << " " << s << " " << so << " " << cit << " " << pa << " " << pi << " " << acc_num << " " << acc_bal << "\n";


				changeColor(10);

				cout << "\n\n\tUser Account Successfully Edi ..";

				found++;
			}
			else
			{
				file1 << " " << acc_id << " " << name << " " << fath_name <<  " " << ph_num << " " << email << " " << ho <<    " " << se << " " << city << " " << pass << " " << pin << " " << acc_num << " " << acc_bal << "\n";


			}
			file >> acc_id >> name >> fath_name >>  ph_num >> email >> ho >>    se >> city >> pass >> pin >> acc_num >> acc_bal;

		}
		file.close();
		file1.close();
		remove("bank.txt");
		rename("bank1.txt", "bank.txt");
		if (found == 0)
		{
			changeColor(12);
			cout << "\n\n\tUser ID not Found...";
		}

	}
}

void Bank::del_record()
{
	system("cls");
	fstream file, file1;
	string t_id;
	int found = 0;
	int a = {};
	cout << "\n\n\t\t\t\tDelete User Record";
	file.open("bank.txt", ios::in);
	if (!file)
	{
		changeColor(12);
		cout << "\n\n\n\t\t\tNo Database Found";
	}
	else
	{
		changeColor(10);
		system("cls");
		cout << "\n\n\t\t\t\tDelete User Record";
		//changeColor(10);
		cout << "\n\n\n\tUser Account ID: ";
		cin >> t_id;
		file1.open("bank1.txt", ios::app | ios::out);
		file >> acc_id >> name >> fath_name >>  ph_num >> email >> ho >>    se >> city >> pass >> pin >> acc_num >> acc_bal;

		while (!file.eof())
		{
			if (t_id == acc_id)
			{
				changeColor(12);
				cout << "\n\n\n\tYour Required User Account Data is Deleted...";
				found++;
			}
			else
			{
				file1 << " " << acc_id << " " << name << " " << fath_name << " " << ph_num << " " << email << " " << ho <<    " " << se << " " << city << " " << pass << " " << pin << " " << acc_num << " " << acc_bal << "\n";

			}
			file >> acc_id >> name >> fath_name >>ph_num >> email >> ho >>    se >> city >> pass >> pin >> acc_num >> acc_bal;

		}

		file.close();
		file1.close();


		remove("bank.txt");
		rename("bank1.txt", "bank.txt");



		if (found == 0)
		{
			changeColor(12);
			cout << "\n\n\tUser ID not Found...";
		}



	}

}

void Bank::show_all_records()
{
	system("cls");
	fstream file;
	int found = 0;
	cout << "\n\n\t\t\tShow All User's Records";
	file.open("bank.txt", ios::in);
	if (!file)
	{
		changeColor(12);
		cout << "\n\n\n\t\t\tNo Database Found";
	}
	else
	{
		file >> acc_id >> name >> fath_name >> ph_num >> email >> ho >>    se >> city >> pass >> pin >> acc_num >> acc_bal;

		while (!file.eof())
		{
			changeColor(10);
			cout << "\n\n\n\n\tAccount ID                                     :  " << acc_id << endl << endl;
			cout << "\tName                                           :  " << name << endl << endl;
			cout << "\tFather Name                                    :  " << fath_name << endl << endl;
			
			cout << "\tPhone Number:  " << ph_num << endl << endl;
			cout << "\tE-mail                                         :  " << email << endl << endl;
			cout << "\tAddress: " << endl << endl;
			cout << "\tHouse No                                       :  " << ho << endl << endl;
			
			cout << "\tSector                                         :  " << se << endl << endl;
			cout << "\tCity                                           :  " << city << endl << endl;
			cout << "\tPassword (5 Characters Only)                   :  " << pass << endl << endl;
			cout << "\tPin (5 Digits Only)                            :  " << pin << endl << endl;
			cout << "\tAccount Number                                 :  " << acc_num << endl << endl;
			cout << "\tAccount Balance                                :  " << acc_bal << endl << endl;



			file >> acc_id >> name >> fath_name >> ph_num >> email >> ho >>    se >> city >> pass >> pin >> acc_num >> acc_bal;
			found++;
		}
		file.close();
		if (found == 0)
		{
			changeColor(12);
			cout << "\n\n\tDatabase is Empty...";
		}

	}
}

void ATM::user_balance_atm()
{
	system("cls");
	fstream file;
	int found = 0;
	string t_id, t_pin, t_pass;
	char ch;

	cout << "\n\n\t\t\t\tUser Login & Check Balance";
	file.open("bank.txt", ios::in);
	if (!file)
	{
		changeColor(12);
		cout << "\n\n\n\t\t\tNo Database Found";
	}
	else
	{
		changeColor(10);
		cout << "\n\n\n\tUser Account ID: ";
		cin >> t_id;
		cout << "\n\n\tPassword (5 Characters Only): ";
		for (int i = 1; i <= 5; i++)
		{
			ch = _getch();
			t_pass += ch;
			cout << "*";
		}
		cout << "\n\n\n\tPin Code (5 Digits Only): ";
		for (int i = 1; i <= 5; i++)
		{
			ch = _getch();
			t_pin += ch;
			cout << "*";
		}
		file >> acc_id >> name >> fath_name >> ph_num >> email >> ho >>    se >> city >> pass >> pin >> acc_num >> acc_bal;

		while (!file.eof())
		{
			if (t_id == acc_id && t_pass == pass && t_pin == pin)
			{
				system("cls");
				cout << "\n\n\t\t\t\tUser Login & Check Balance";
				cout << "\n\n\n\tYour Current Balance : " << acc_bal;
				found++;
				cout << endl;
				changeColor(11);
			
			}
			file >> acc_id >> name >> fath_name >> ph_num >> email >> ho >>    se >> city >> pass >> pin >> acc_num >> acc_bal;

		}
		file.close();
		if (found == 0)
		{
			changeColor(12);
			system("cls");
			cout << "\n\n\t\t\t\tUser Login & Check Balance";
			cout << "\n\n\n\tUser Account ID, Password & Pin is Invalid....";

		}

	}
}

void ATM::withdraw()
{

	fstream file, file1;
	string t_id, t_pass, t_pin;
	long long with_amo = {};
	long long b = {};
	int found = 0;

	char ch;

	system("cls");
	cout << "\n\n\n\t\t\t\tWithdraw Amount Option";
	file.open("bank.txt", ios::in);
	if (!file)
	{
		changeColor(12);
		cout << "\n\n\tNo Database Found ";
	}

	else
	{
		changeColor(10);
		cout << "\n\n\n\tUser Account ID: ";
		cin >> t_id;
		cout << "\n\n\tPassword (5 Characters Only): ";
		for (int i = 1; i <= 5; i++)
		{
			ch = _getch();
			t_pass += ch;
			cout << "*";
		}
		cout << "\n\n\n\tPin Code (5 Digits Only): ";
		for (int i = 1; i <= 5; i++)
		{
			ch = _getch();
			t_pin += ch;
			cout << "*";
		}
		file1.open("bank1.txt", ios::app | ios::out);
		file >> acc_id >> name >> fath_name >> ph_num >> email >> ho >>  se >> city >> pass >> pin >> acc_num >> acc_bal;
		while (!file.eof())
		{
			if (t_id == acc_id && t_pass == pass && t_pin == pin)
			{
				system("cls");
				cout << "\n\n\n\t\t\t\tWithdraw Amount Option";
				cout << endl;
				cout << "\n\n\tWithdraw Amount: ";
				cin >> with_amo;
				if (with_amo <= acc_bal)
				{

					acc_bal -= with_amo;
					file1 << " " << acc_id << " " << name << " " << fath_name <<  " " << ph_num << " " << email << " " << ho <<    " " << se << " " << city << " " << pass << " " << pin << " " << acc_num << " " << acc_bal << "\n";

					changeColor(10);
					cout << "\n\n\tYour Amount: " << with_amo << " Successfully Withdraw";
					cout << endl;
					cout << "\n\n\tYour Account Balance is: " << acc_bal;
					changeColor(11);
					cout << endl;
					

				}
				else
				{
					changeColor(12);
					file1 << " " << acc_id << " " << name << " " << fath_name << " " << ph_num << " " << email << " " << ho <<    " " << se << " " << city << " " << pass << " " << pin << " " << acc_num << " " << acc_bal << "\n";


					cout << "\n\n\tYour Current Balance is Low....";
					cout << endl;
					cout << "\n\n\tYour Current Balance is: " << acc_bal;


				}
				found++;

			}

			else
			{

				file1 << " " << acc_id << " " << name << " " << fath_name <<  " " << ph_num << " " << email << " " << ho <<    " " << se << " " << city << " " << pass << " " << pin << " " << acc_num << " " << acc_bal << "\n";


			}
			file >> acc_id >> name >> fath_name >>ph_num >> email >> ho >>    se >> city >> pass >> pin >> acc_num >> acc_bal;

		}

		file.close();
		file1.close();
		remove("bank.txt");

		rename("bank1.txt", "bank.txt");

		if (found == 1)
		{
			file.open("withdrawal.txt", ios::app | ios::out);
			file << t_id << " " << with_amo << "\n";

			file.close();

		}

		if (found == 0)
		{
			changeColor(12);
			cout << endl;
			cout << "\n\n\tUser ID not Found...";

		}


	}

}

void ATM::check_details_atm()
{
	system("cls");
	fstream file;
	string t_id, t_pass, t_pin;
	int found = 0;
	char ch;
	cout << "\n\n\t\t\t\tSearch User Record";
	file.open("bank.txt", ios::in);
	if (!file)
	{
		changeColor(12);
		cout << "\n\n\n\t\t\tNo Database Found";
	}
	else
	{
		changeColor(10);
		cout << "\n\n\n\t""User Account ID: ";
		cin >> t_id;
		cout << "\n\n\tPassword (5 Characters Only): ";
		for (int i = 1; i <= 5; i++)
		{
			ch = _getch();
			t_pass += ch;
			cout << "*";
		}
		cout << "\n\n\n\tPin Code (5 Digits Only): ";
		for (int i = 1; i <= 5; i++)
		{
			ch = _getch();
			t_pin += ch;
			cout << "*";
		}
		file >> acc_id >> name >> fath_name >>  ph_num >> email >> ho >>    se >> city >> pass >> pin >> acc_num >> acc_bal;
		while (!file.eof())
		{
			if (t_id == acc_id && t_pass == pass && t_pin == pin)
			{
				system("cls");
				cout << "\n\n\n\tUser Account Details" << endl << endl;
				cout << endl;
				cout << "\tAccount ID                                     :  " << acc_id << endl << endl;
				cout << "\tName                                           :  " << name << endl << endl;
				cout << "\tFather Name                                    :  " << fath_name << endl << endl;
				cout << "\tPhone Number  :  " << ph_num << endl << endl;
				cout << "\tE-mail                                         :  " << email << endl << endl;
				cout << "\tAddress: " << endl << endl;
				cout << "\tHouse No                                       :  " << ho << endl << endl;
	
				cout << "\tSector                                         :  " << se << endl << endl;
				cout << "\tCity                                           :  " << city << endl << endl;
				cout << "\tPassword (5 Characters Only)                   :  " << pass << endl << endl;
				cout << "\tPin (5 Digits Only)                            :  " << pin << endl << endl;
				cout << "\tAccount Number                                 :  " << acc_num << endl << endl;
				cout << "\tAccount Balance                                :  " << acc_bal << endl << endl;
				found++;
			}
			file >> acc_id >> name >> fath_name >>  ph_num >> email >> ho >>    se >> city >> pass >> pin >> acc_num >> acc_bal;
		}
		file.close();
		if (found == 0)
		{
			changeColor(12);
			cout << endl;
			cout << "\n\n\tUser ID not Found...";
		}
	}
}

int main()
{
	Management M;
	introduction();
	M.menu();

}

void changeColor(int desiredColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}