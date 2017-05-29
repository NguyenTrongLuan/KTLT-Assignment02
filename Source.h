#include "User.h"
#include "Account.h"
#include "Book.h"
#include "Date.h"
#include "Guest.h"
#include "Librarian.h"
#include "Reader.h"
#include "RentBook.h"
#include "UserManager.h"
using namespace std;
void startProg();
void userLogin();
void resetProg();
void userLogin()
{
	vector<int> role;
	int counter = 0;
	int choose = 0;
	string userName;
	string password;
	cout << "Nhap tai khoan: ";
	cin >> userName;
	cin.ignore();
	cout << "Nhap mat khau: ";
	cin >> password;
	int flag = -1;
	Account tempAcc;
	User tempUser;
	fstream dataFin("account_data.txt");
	for (int i = 1; i <= tempUser.getFAccount() && flag == -1; ++i)
	{
		dataFin.seekg((i - 1) * sizeof(Account));
		dataFin.read(reinterpret_cast<char*>(&tempAcc), sizeof(Account));
		if (tempAcc.getUserName() == userName && tempAcc.getPassword() == password)
			flag = i;
	}
	dataFin.close();
	while (flag == -1)
	{
		cout << "Mat khau hoac tai khoan khong dung" << endl;
		cout << "1. Dang nhap lai" << endl;
		cout << "0. Quay lai man hinh chinh " << endl;
		cout << "-1. Thoat chuong trinh" << endl;
		cout << "Nhap vao lua chon: ";
		int choose = 0;
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			system("cls");
			string userName;
			string password;
			cout << "Nhap tai khoan: ";
			cin >> userName;
			cout << "Nhap mat khau: ";
			cin >> password;
			fstream dataFin("account_data.txt");
			for (int i = 1; i <= tempUser.getFAccount() && flag == -1; ++i)
			{
				dataFin.seekg((i - 1) * sizeof(Account));
				dataFin.read(reinterpret_cast<char*>(&tempAcc), sizeof(Account));
				if (tempAcc.getUserName() == userName && tempAcc.getPassword() == password)
					flag = i;
			}
			dataFin.close();
		}
		break;
		case 0:
			userLogin();
			break;
		case -1:
			exit(EXIT_SUCCESS);
			break;
		default:
			break;
		}
	}
	if (flag != -1)
	{
		system("cls");
		tempUser.readUser(tempAcc.getLibID());
		if (tempAcc.getState() && tempUser.getState())
		{
			cout << "Dang nhap thanh cong" << endl;
			for (int i = 0; i < 3; ++i)
			{
				if (tempAcc.getRole()[i] == '1')
				{
					cout << ++counter << ". truy cap voi tu cach ";

					if (i == 0)
						cout << "doc gia" << endl;
					else if (i == 1)
						cout << "thu thu" << endl;
					else cout << "quan ly nguoi dung" << endl;
					role.push_back(i + 1);
				}
			}
			cout << "Nhap lua chon: ";
			cin >> choose;
			cout << role[choose - 1] << endl;
			switch (role[choose - 1])
			{
			case 1:
			{
				Reader blankReader(tempUser);
				blankReader.userInteract();
			}
			break;
			case 2:
			{
				Librarian tempReader(tempUser);
				tempReader.userInteract();
			}
			break;
			case 3:
			{
				UserManager tempUSN(tempUser);
				tempUSN.userInteract();
			}
			break;
			default:
				exit(EXIT_SUCCESS);
				break;
			}
		}
		else
		{
			cout << "Tai khoan chua duoc kich hoat" << endl;
			cout << "Vui long lien he voi quan tri vien de giai quyet yeu cau" << endl;
			cout << "\n1. Thoat chuong trinh " << endl;
			cout << "2.Quay lai" << endl;
			cout << "Nhap lua chon: ";
			int choose = 0;
			cin >> choose;
			while (choose != 1 && choose != 2)
			{
				cout << "Lua chon khong hop le  " << endl;
				cout << "Vui long nhap lai: ";
				cin >> choose;
			}
			if (choose == 1)
				exit(EXIT_SUCCESS);
			else startProg();
		}
	}
	else cout << "Dang nhap that bai" << endl;
}

void startProg()
{
	cout << "1. Dang nhap" << endl;
	cout << "2. Dang ki" << endl;
	cout << "3. Thoat" << endl;
	int choose = 0;
	cin >> choose;
	cin.ignore();
	while (choose < 1 || choose > 3)
	{
		cout << "Lua chon khong hop le, vui long nhap lai: ";
		cin >> choose;
		cin.ignore();
	}
	switch (choose)
	{
	case 1:
		system("cls");
		userLogin();
		break;
	case 2:
	{
		Guest newGuest;
		newGuest.regAccount();
	}
	break;
	case 3:
		exit(EXIT_SUCCESS);
		break;
	default:
		exit(EXIT_SUCCESS);
		break;
	}
}
void resetProg()
{
	Book blankBook;
	User blankUser;
	Account blankAccount;
	RentBook blankRent;
	ofstream bookFout("book_data.txt");
	bookFout.seekp(0);
	ofstream accFout("account_data.txt");
	accFout.seekp(0);
	ofstream userFout("user_data.txt");
	userFout.seekp(0);
	ofstream rentFout("rent_data.txt");
	rentFout.seekp(0);
	for (int i = 0; i < 10000; ++i)
	{
		bookFout.write(reinterpret_cast<char*>(&blankBook), sizeof(Book));
		accFout.write(reinterpret_cast<char*>(&blankAccount), sizeof(Account));
		userFout.write(reinterpret_cast<char*>(&blankAccount), sizeof(User));
	}
	ofstream resParam("foo.txt");
	resParam << "NumBook:" << '\t' << 0 << endl;
	resParam << "NumUser: " << '\t' << 0 << endl;
	resParam << "NumAccount: " << '\t' << 0 << endl;
	resParam << "NumRent: " << '\t' << 0 << endl;
	remove("param_data.txt");
	resParam.close();
	rename("foo.txt", "param_data.txt");
}
