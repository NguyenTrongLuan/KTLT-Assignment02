#include "Guest.h"
using namespace std;
Guest::Guest(long id, string name)
	:userID(id)
{
	setName(name);
}
int Guest::regAccount()			// Not tested yet
{
	system("cls");
	cout << "-----------------DANG KI TAI KHOAN---------------" << endl;
	cout << "Nhap thong tin theo yeu cau" << endl;
	cout << "0. Quay lai" << endl;
	cout << "1. Thoat" << endl;
	cout << "\n\nNhap ten day du: ";
	string name;
	getline(cin, name);
	if (name == "1")
		exit(EXIT_SUCCESS);
	else if (name == "0")
		return 1;
	cout << "Nhap ma so sinh vien: ";
	long uid;
	cin >> uid;
	if (uid == 1)
		exit(EXIT_SUCCESS);
	else if (uid == 0)
		return 1;
	cin.ignore();
	long pid;
	cout << "Nhap chung minh nhan dan: ";
	cin >> pid;
	if (pid == 1)
		exit(EXIT_SUCCESS);
	else if (pid == 0)
		return  1;
	cin.ignore();
	cout << "Nhap ngay thang nam sinh: ";
	string DOB;
	if (DOB == "1")
		exit(EXIT_SUCCESS);
	else if (DOB == "0")
		return 1;
	getline(cin, DOB);
	cout << "Nhap nghe nghiep: ";
	string job;
	if (job=="1")
		exit(EXIT_SUCCESS);
	getline(cin, job);
	cout << "Nhap dia chi email: ";
	string email;
	getline(cin, email);
	if (email == "1")
		exit(EXIT_SUCCESS);
	else if (email == "0")
		return 1;
	cout << "Nhap ten dang nhap moi: ";
	string usn;
	getline(cin, usn);
	if (usn=="1")
		exit(EXIT_SUCCESS);
	cout << "Nhap mat khau moi: ";
	string pwd;
	getline(cin, pwd);
	if (pwd=="1")
		exit(EXIT_SUCCESS);
	User tempUser;
	Account tempAccount;
	bool isDup = false;

	while (tempAccount.isDupUSN(usn))		// Neu trung ten dang nhap
	{
		cout << "Ten dang nhap da ton tai" << endl;
		cout << "Nhap lai ten dang nhap: ";
		isDup = true;
		getline(cin, usn);
		if (usn == "1")
			exit(EXIT_SUCCESS);
		if (usn == "0")
			return 1;
	}

	while (tempUser.isDupEmail(email))		// Neu trung dia chi email
	{
		cout << "Dia chi email da dang ki" << endl;
		cout << "Nhap lai dia chi email: ";
		isDup = true;
		getline(cin, email);
		if (email=="1")
			exit(EXIT_SUCCESS);
		if (email=="0")
			return 1;
	}

	while (tempUser.isDupUID(uid))			// Neu trung ma so sinh vien
	{
		cout << "Ma so sinh vien da ton tai" << endl;
		cout << "Nhap lai hoac nhap 0 de thoat, 1 de quay lai: " ;
		isDup = true;
		cin >> uid;
		cin.ignore();
		if (uid == 1)
			exit(EXIT_SUCCESS);
		if (uid == 0)
			return 1;
	}

	while (tempUser.isDupPID(pid))			// Neu trung cmnd
	{
		cout << "So chung minh nhan dan da ton tai" << endl;
		cout << "Nhap lai hoac nhap 0 de thoat, 1 de quay lai" << endl;
		isDup = true;
		cin >> pid;
		cin.ignore();
		if (pid == 1)
			exit(EXIT_SUCCESS);
		if (pid == 0)
			return 1;
	}

	// Neu vuot qua het :))
	User newUser(tempUser.getNumUser() + 1, uid, pid, name, DOB, job, email, false);
	newUser.saveUser();
	Account newAccount(tempUser.getNumUser() + 1, tempAccount.getNumAccount() + 1, usn, pwd, false);
	newAccount.saveData();
	tempUser.setNumUser(tempUser.getNumUser() + 1);
	tempUser.setFAccount(tempUser.getFAccount() + 1);
	cout << "Dang ki tai khoan thanh cong, vui long cho quan tri vien xac nhan" << endl;
	cout << "\n0. Quay lai" << endl;
	cout << "1. Thoat chuong trinh" << endl;
	cout << "Nhap vao lua chon" << endl;
	int choose = 0;
	cin >> choose;
	while (choose != 0 && choose != 1)
	{
		cout << "Lua chon khong hop le, vui long nhap lai: ";
		cin >> choose;
	}
	if (choose == 1)
		exit(EXIT_SUCCESS);
	else return 1;
}
void Guest::setName(string name)
{
	int size = name.size() < NAME_SIZE ? name.size() : NAME_SIZE - 1;
	name.copy(fullName, size);
	fullName[size] = '\0';
}
void Guest::setUserID(long id)
{
	userID = id;
}
string Guest::getFullName() const
{
	return fullName;
}
long Guest::getUserID() const
{
	return userID;
}
