#include "UserManager.h"
using namespace std;
UserManager::UserManager(long lid, long uid, long pid, string name, string dob, string job, string mail,
	long listA[NUM_ACCOUNT], int numA, bool st)
	:User(lid, uid, pid, name, dob,job, mail, listA, numA, st)
{}
UserManager::UserManager(long lid, long uid, long pid, string name, string dob, string job, std::string mail
	, bool st)
	:User(lid,uid,pid,name,dob,job,mail,st)
{}
UserManager::UserManager(const User &temp)
	:User(temp)
{}
void UserManager::userInteract()
{
	system("cls");
	cout << "----------------QUAN LY NGUOI DUNG-----------------" << endl;
	cout << "1. Tim kiem nguoi dung" << endl;
	cout << "2. Them nguoi dung moi" << endl;
	cout << "3. Xoa nguoi dung" << endl;
	cout << "4. Khoa tai khoan" << endl;
	cout << "5. Mo khoa tai khoan" << endl;
	cout << "6. Lap lai mat khau" << endl;
	cout << "0. Thoat" << endl;
	cout << "Nhap vao lua chon: ";
	int choose = 0;
	cin >> choose;
	cin.ignore();
	switch (choose)
	{
	case 1:
		findUser();
		break;
	case 2:
		addNewUser();
		break;
	case 3:
		deleteUser();
		break;
	case 4:
		lockUser();
		break;
	case 5:
		unlockUser();
		break;
	case 6:
		resetPassword();
		break;
	default:
		endProg();
		break;
	}
}
void UserManager::addNewUser()
{
	system("cls");
	cout << "-------------------THEM NGUOI DUNG-----------------" << endl;
	cout << "Nhap ten day du: ";
	string name;
	getline(cin, name);
	string usn;
	cout << "Nhap tai khoan moi: ";
	cin >> usn;
	string pwd;
	cout << "Nhap mat khau moi: ";
	cin.ignore();
	cin >> pwd;
	cout << "Nhap email: ";
	string mail;
	cin >> mail;
	cin.ignore();
	cout << "Nhap ngay thang nam sinh: ";
	string dob;
	cin >> dob;
	cin.ignore();
	cout << "Nhap nghe nghiep: ";
	string job;
	cin >> job;
	cout << "Nhap ma so tai khoan: ";
	long uid;
	cin >> uid;
	long pid;
	cout << "Nhap so chung minh nhan dan: ";
	cin >> pid;
	cin.ignore();
	cout << "Nhap ma so vai tro: ";
	string role;
	cin >> role;
	ifstream userFin("user_data.txt");
	User tempUser;
	bool dupUID = false;
	bool dupPID = false;
	while (userFin.read(reinterpret_cast<char*>(&tempUser), sizeof(User)))
	{
		if (tempUser.getLibID() == 0)
			break;
		if (tempUser.getUserID() == uid)
			dupUID = true;
		if (tempUser.getUserPID() == pid)
			dupPID = true;
	}
	cout << "Done" << endl;
	if (!dupPID && !dupUID)
	{
		Account newAccount(getNumUser() + 1, getFAccount() + 1, usn, pwd, role, true);
		newAccount.saveData();
		cout << "Done" << endl;
		User newUser(getNumUser() + 1, uid, pid, name, dob, job, mail, true);
		newUser.saveUser();
		cout << "Done" << endl;
		setFAccount(getFAccount() + 1);
		setNumUser(getNumUser() + 1);
		cout << "Done" << endl;
		system("cls");
		cout << "Them tai khoan thanh cong" << endl;
		cout << "\n1. Tiep tuc them tai khoan" << endl;
		cout << "2. Quay lai" << endl;
		cout << "3. Thoat chuong trinh" << endl;
		cout << "\nNhap lua chon: ";
		int choose = 0;
		cin >> choose;
		cin.ignore();
		while (choose > 3 || choose < 1)
		{
			cout << "Lua chon khong hop le, vui long nhap lai: ";
			cin >> choose;
			cin.ignore();
		}
		if (choose == 1)
			addNewUser();
		else if (choose == 2)
			userInteract();
		else if (choose == 3)
			endProg();
	}
	else
	{
		if (dupPID)
			cout << "Chung minh nhan dan da dang ki" << endl;
		if (dupUID)
			cout << "Ma so sinh vien/giang vien da dang ki" << endl;
		cout << "Tao moi nguoi dung that bai" << endl;
		cout << "Nhap 1 de nhap lai " << endl;
		cout << "Nhap 0 de thoat" << endl;
		int choose = 0;
		cin >> choose;
		cin.ignore();
		while (choose != 0 && choose != 1)
		{
			cout << "Lua chon khong hop le, vui long nhap lai: ";
			cin >> choose;
			cin.ignore();
		}
		if (choose)
			addNewUser();
		else exitProg();
	}
}
void UserManager::deleteUser()
{
	system("cls");
	cout << "----------------XOA NGUOI DUNG----------------" << endl;
	cout << "Nhap ma so thu vien: ";
	long lid = 0;
	cin >> lid;
	cin.ignore();
	User tempUser;
	tempUser.readUser(lid);
	fstream userFin("user_data.txt");
	if (tempUser.getLibID() != 0)
	{
		cout << "Tim thay thong tin: " << endl;
		tempUser.outputMainInfo();
		cout << "1. Xac nhan xoa nguoi dung nay" << endl;
		cout << "0. Quay lai" << endl;
		cout << "2. Thoat" << endl;
		int choose = 0;
		cin >> choose;
		cin.ignore();
		while (choose > 2 || choose < 0)
		{
			cout << "Lua chon khong hop le, vui long nhap lai: ";
			cin >> choose;
			cin.ignore();
		}
		if (choose == 1)
		{
			User blankUser;
			blankUser.saveUser(lid);
			cout << "Xoa nguoi dung thanh cong  " << endl;
			cout << "0. Quay lai" << endl;
			cout << "1. Thoat" << endl;
			int choose2 = 0;
			cin >> choose2;
			cin.ignore();
			while (choose2 != 1 && choose2 != 0)
			{
				cout << "Lua chon khong hop le, vui long nhap lai: ";
				cin >> choose2;
				cin.ignore();
			}
			if (choose2 == 0)
				userInteract();
			else exitProg();
		}
		else if (choose == 0)
			userInteract();
		else exitProg();

	}
	else
	{
		cout << "Ma so thu vien khong ton tai!" << endl;
		cout << "0. Thu lai" << endl;
		cout << "1. Quay lai man hinh chinh" << endl;
		cout << "2. Thoat chuong trinh" << endl;
		
		int choose = 0;
		cin >> choose;
		cin.ignore();
		while (choose > 2 || choose < 0)
		{
			cout << "Lua chon khong hop le, vui long nhap lai: ";
			cin >> choose;
			cin.ignore();
		}
		if (choose == 0)
			deleteUser();
		else if (choose == 1)
			userInteract();
		else exitProg();
	}
}
void UserManager::lockUser()
{
	system("cls");
	cout << "-----------------KHOA TAI KHOAN-----------------" << endl;
	cout << "Nhap ma so thu vien: ";
	long lid = 0;
	cin >> lid;
	User tempUser;
	Account tempAcc;
	tempUser.readUser(lid);
	if (tempAcc.getNumAccount() != 0)	//	 Neu tim thay thong tin phu hop
	{
		cout << "Tim thay cac tai khoan ung voi nguoi dung nay: " << endl;
		for (int i = 0; i < tempAcc.getNumAccount(); ++i)
		{
			cout << i+1 << ". ";
			tempAcc.readData(tempUser.getAccountList()[i]);
			tempAcc.outputData();
		}
		cout << "Nhap so tai khoan de khoa" << endl;
		cout << "0. Khoa tat ca tai khoan" << endl;
		cout << "-1. Quay lai" << endl;
		cout << "-2. Thoat" << endl;
		int choose = 0;
		cin >> choose;
		cin.ignore();

		while (choose > tempAcc.getNumAccount() || choose < -2)
		{
			cout << "Lua chon khong hop le, nhap lai: ";
			cin >> choose;
			cin.ignore();
		}


		switch (choose)
		{
		case 0:
		{
			for (int i = 0; i < tempAcc.getNumAccount(); ++i)
			{
				tempAcc.readData(tempUser.getAccountList()[i]);
				tempAcc.setState(false);
				tempAcc.saveData();
			}
			cout << "Khoa tat ca tai khoan thanh cong" << endl;
			cout << "0. Tiep tuc khoa tai khoan" << endl;
			cout << "1. Quay lai" << endl;
			cout << "2. Thoat chuong trinh" << endl;
			cout << "Nhap lua chon: ";
			int choose2 = 0;
			cin >> choose2;

			while (choose2 > 2 || choose2 < 0)
			{
				cout << "Lua chon khong hop le, nhap lai: ";
				cin >> choose2;
				cin.ignore();
			}

			if (choose2 == 0)
				lockUser();
			else if (choose2 == 1)
				userInteract();
			else exitProg();
 		}
			break;
		case -1:
			userInteract();
			break;
		case -2:
			exitProg();
		default:
		{
			if (choose <= tempAcc.getNumAccount() && choose >= 1)
			{
				tempAcc.readData(tempUser.getAccountList()[choose - 1]);
				tempAcc.setState(false);
				tempAcc.saveData();
				cout << "Khoa tai khoan thanh cong" << endl;
				endProg();
			}
			else
			{
				cout << "Lua chon khong hop le " << endl;
				endProg();
			}
		}
		break;
		}
	}
}
void UserManager::unlockUser()
{
	system("cls");
	cout << "----------------------MO KHOA TAI KHOAN---------------" << endl;
	cout << "Nhap ma so thu vien: ";
	int lid = 0;
	cin >> lid;
	User tempUser;
	Account tempAcc;
	if (tempUser.getLibID() != 0)
	{
		cout << "Tim thay thong tin nguoi dung: " << endl;
		tempUser.outputSpecific();
		cout << "Tim duoc thong tin cac tai khoan" << endl;
		for (int i = 0; i < tempAcc.getNumAccount(); ++i)
		{
			cout << i + 1 << ". ";
			tempAcc.readData(tempUser.getAccountList()[i]);
			tempAcc.outputData();
		}
		cout << "Chon tai khoan de mo khoa" << endl;
		cout << "Nhap -1 de quay lai " << endl;
		cout << "Nhap 0 de thoat" << endl;
		int choose = 0;
		vector<int> cho;
		while (choose >= 1 && choose <= tempAcc.getNumAccount())
		{
			cin >> choose;
			cho.push_back(choose);
		}
		for (int i = 0; i < cho.size(); ++i)
		{
			switch (cho[i])
			{
			case -1:
				userInteract();
				break;
			case 0:
				exitProg();
				break;
			default:
				if (choose >= 1 && choose <= tempAcc.getNumAccount())
				{
					tempAcc.readData(tempUser.getAccountList()[choose]);
					tempAcc.setState(false);
					tempAcc.saveData();
				}
				else
				{
					cout << "Lua chon khong hop le" << endl;
					endProg();
				}
				break;
			}
		}
	}
	else
	{
		cout << "Khong tim thay thong tin thoa man" << endl;
		cout << "0. Thuc hien lai" << endl;
		cout << "1. Quay lai man hinh chinh" << endl;
		cout << "2. Thoat chuong trinh" << endl;
		cout << "Nhap lua chon: ";
		int choose = 0;
		cin >> choose;
		cin.ignore();

		while (choose > 2 || choose < 0)
		{
			cout << "Lua chon khong hop le, vui long nhap lai: ";
			cin >> choose;
			cin.ignore();
		}

		if (choose == 0)
			unlockUser();
		else if (choose == 1)
			userInteract();
		else if (choose == 2)
			exitProg();

	}

}
void UserManager::resetPassword()
{
	system("cls");
	cout << "-----------------------LAP LAI MAT KHAU----------------------" << endl;
	cout << "Nhap tai khoan: ";
	string usn;
	cin >> usn;
	Account tempAccount;
	int flag = -1;
	cin.ignore();
	for (int i = 0; i < getFAccount() && flag == -1; ++i)
	{
		tempAccount.readData(i + 1);
		if (tempAccount.getUserName() == usn)
			flag = i;
	}
	if (flag == -1)
	{
		cout << "\nTen dang nhap khong ton tai" << endl;
		cout << "0. Thuc hien lai" << endl;
		cout << "1. Quay lai man hinh chinh" << endl;
		cout << "2. Thoat" << endl;
		cout << "Nhap lua chon:  ";
		int choose = 0;
		cin >> choose;
		cin.ignore();
		while (choose > 2 || choose < 0)
		{
			cout << "Lua chon khong hop le, nhap lai: ";
			cin >> choose;
			cin.ignore();
		}
		if (choose == 0)
			resetPassword();
		else if (choose == 1)
			userInteract();
		else if (choose == 2)
			exitProg();
	}
	if (flag != -1)
	{
		cout << "Nhap mat khau moi: ";
		string pwd;
		cin >> pwd;
		cout << "1. Xac nhan lap lai mat khau" << endl;
		cout << "0. Quay lai" << endl;
		cout << "Nhap lua chon: ";
		int choose2 = 0;
		cin >> choose2;
		cin.ignore();
		while (choose2 != 0 && choose2 != 1)
		{
			cout << "Lua chon khong hop le, nhap lai: ";
			cin >> choose2;
			cin.ignore();
		}
		if (choose2)
		{
			tempAccount.setPassword(pwd);
			tempAccount.saveData();
			cout << "Lap lai mat khau thanh cong" << endl;
			endProg();
		}
		else
			userInteract();
	}


}
void UserManager::findUser()
{
	system("cls");
	cout << "------------------------TIM KIEM NGUOI DUNG-------------------" << endl;
	cout << "Nhap tu khoa tim kiem: ";
	string searchKey;
	getline(cin, searchKey);
	User tempUser;
	vector<long> fRes;
	for (long i = 0; i < getNumUser(); ++i)
	{
		tempUser.readUser(i + 1);
		if (tempUser.getFullName().find(searchKey) != string::npos
			|| tempUser.getMailAddr().find(searchKey) != string::npos
			|| to_string(tempUser.getUserID()).find(searchKey) != string::npos)
			fRes.push_back(i+1);
	}
	if (fRes.size() == 0)
	{
		cout << "Khong tim thay thong tin yeu cau" << endl;
		cout << "\nNhap 1 de quay lai tim kiem " << endl;
		cout << "Nhap 0 de quay lai man hinh chinh" << endl;
		cout << "Nhap -1 de thoat" << endl;
		cout << "Nhap lua chon : ";
		int choose = 0;
		cin >> choose;
		cin.ignore();
		if (choose == 1)
			findUser();
		else if (choose == 0)
			userInteract();
		else if (choose == -1)
			exitProg();
	}
	else if (!fRes.empty())
	{
		User tempUser;
		cout << "Tim thay thong tin sau: " << endl;
		for (int i = 0; i < fRes.size(); ++i)
		{
			tempUser.readUser(fRes[i]);
			cout << i+1 << ". ";
			tempUser.outputMainInfo();
		}
		cout << "\n\nNhap so thu tu de xem lua chon doi voi nguoi dung" << endl;
		cout << "0. Quay lai" << endl;
		cout << "-1. Thoat" << endl;
		cout << "Nhap lua chon: ";
		int choose = 0;
		cin >> choose;
		if (choose >= 1 && choose <= fRes.size())
		{
			system("cls");
			tempUser.readUser(fRes[choose - 1]);
			tempUser.outputSpecific();
			cout << "\n\n1. Sua thong tin nguoi dung" << endl;
			cout << "2. Xoa thong tin nguoi dung" << endl;
			cout << "3. Khoa/mo khoa nguoi dung" << endl;
			cout << "Nhap lua chon: ";
			int choose2 = 0;
			cin >> choose2;
			cin.ignore();
			if (choose2 == 1)	// Sua thong tin
			{
				system("cls");
				editUser(fRes[choose - 1]);
				endProg();
			}
			else if (choose == 2)		//  Xoa thong tin
			{
				User blank;
				blank.saveUser(fRes[choose - 1]);
				endProg();
			}
			else if (choose == 3)		//  Khoa/ mo khoa
			{
				if (tempUser.getState())
				{
					cout << "Nguoi dung nay dang hoat dong binh thuong" << endl;
					cout << "0. Khoa nguoi dung nay" << endl;
					cout << "1. Quay lai" << endl;
					cout << "2. Thoat chuong trinh" << endl;

					int choose2 = 0;
					cin >> choose2;
					cin.ignore();
					while (choose2 > 2 || choose2 < 0)
					{
						cout << "Lua chon khong hop le, nhap lai: ";
						cin >> choose2;
						cin.ignore();
					}
					if (choose == 0)
					{
						tempUser.setState(false);
						tempUser.saveUser();
						cout << "Khoa tai khoan thanh cong" << endl;
						endProg();
					}
					else if (choose == 1)
						userInteract();
					else exitProg();
				}
				else
				{
					cout << "Nguoi dung dang bi khoa" << endl;
					cout << "0. Mo khoa nguoi dung nay" << endl;
					cout << "1. Quay lai" << endl;
					cout << "2. Thoat chuong trinh" << endl;
					int choose2 = 0;
					cin >> choose2;
					tempUser.setState(true);
					tempUser.saveUser();
					cout << "Mo khoa tai khoan thanh cong" << endl;
					endProg();
				}
			}
		}
	}
}
void UserManager::endProg()
{
	cout << "Nhap 0 de quay lai" << endl;
	cout << "Nhap 1 de thoat" << endl;
	int choose = 0;
	cin >> choose;
	if (choose == 0)
		userInteract();
	else exit(EXIT_SUCCESS);
}
void UserManager::deleteUser(long id)
{
	User blankUser;
	blankUser.saveUser(id);
}

void UserManager::editUser(long id)	// 100%
{
	system("cls");
	User tempUser;
	int choose = 0;
	int choose2 = 1;
	tempUser.readUser(id);
	
	while (choose2==1)
	{
		system("cls");
		cout << "1. Sua ten" << endl;
		cout << "2. Sua ma so sinh vien/ giang vien" << endl;
		cout << "3. Sua so chung minh nhan dan" << endl;
		cout << "4. Sua ngay thang nam sinh" << endl;
		cout << "5. Sua dia chi email" << endl;
		cout << "0. Quay lai" << endl;
		cout << "Nhap lua chon: ";
		cin >> choose;
		cin.ignore();
		while (choose > 5 || choose < 0)
		{
			cout << "Lua chon khong hop le, vui long nhap lai: ";
			cin >> choose;
			cin.ignore();
		}

		if (choose > 0)
		{
			string newInfo;
			cout << "Nhap thong tin moi: ";
			getline(cin, newInfo);

			switch (choose)
			{
			case 1:
				tempUser.setFullName(newInfo);
				break;
			case 2:
				tempUser.setUserID(stol(newInfo));
				break;
			case 3:
				tempUser.setPID(stol(newInfo));
				break;
			case 4:
				tempUser.setDayOfB(newInfo);
				break;
			case 5:
				tempUser.setMailAddr(newInfo);
				break;
			default:
				break;
			}
			tempUser.saveUser();
			cout << "Doi thong tin thanh cong" << endl;
			cout << "0. Quay lai" << endl;
			cout << "1. Tiep tuc doi thong tin" << endl;
			cout << "Nhap lua chon: ";
			cin >> choose2;
			cin.ignore();
			if (choose2 == 0)
				userInteract();
		}
	}
}