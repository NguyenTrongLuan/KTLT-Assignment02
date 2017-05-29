#include "User.h"
using namespace std;

User::User(long lid, long uid , long pid , string name, string dob , string job , string mail ,
		long listA[NUM_ACCOUNT], int numA, bool st)
	:libID(lid), userID(uid), PID(pid), numAccount(numA)
{
	setFullName(name);
	setDayOfB(dob);
	setJob(job);
	setMailAddr(mail);
	setAccountList(listA);
}
User::User(long lid, long uid, long pid, string name, string dob, string job, string mail
	, bool st)
	:libID(lid), userID(uid), PID(pid), state(st),numAccount(0)
{
	setFullName(name);
	setDayOfB(dob);
	setJob(job);
	setMailAddr(mail);
}
void User::setLibID(long lid)
{
	libID = lid;
}
void User::setUserID(long uid)
{
	userID = uid;
}
void User::setPID(long pid)
{
	PID = pid;
}
void User::setFullName(string full)
{
	int size = full.size() < NAME_SIZE ? full.size() : NAME_SIZE - 1;
	full.copy(fullName, size);
	fullName[size] = '\0';
}
void User::setDayOfB(string dob)
{
	int size = dob.size() < DOB_SIZE ? dob.size() : DOB_SIZE - 1;
	dob.copy(dayOfBirth, size);
	dayOfBirth[size] = '\0';

}
void User::setJob(string job)
{
	int size = job.size() < JOB_SIZE ? job.size() : JOB_SIZE - 1;
	job.copy(userJob, size);
	userJob[size] = '\0';
}
void User::setMailAddr(string mail)
{
	int size = mail.size() < MAIL_SIZE ? mail.size() : MAIL_SIZE - 1;
	mail.copy(mailAddr, size);
	mailAddr[size] = '\0';
}
void User::setAccountList(long listA[NUM_ACCOUNT])
{
	for (int i = 0; i < numAccount; ++i)
		listAccount[i] = listA[i];
}
void User::setNumAccount(long numA)
{
	numAccount = numA;
}
void User::setState(bool st)
{
	state = st;
}
long User::getLibID() const
{
	return libID;
}
long User::getUserID() const
{
	return userID;
}
long User::getUserPID() const
{
	return PID;
}
string User::getFullName() const
{
	return fullName;
}
string User::getDOB() const
{
	return dayOfBirth;
}
string User::getMailAddr() const
{
	return mailAddr;
}
long* User::getAccountList() 
{
	return listAccount;
}
long User::getNumAccount() const
{
	return numAccount;
}
bool User::getState() const
{
	return state;
}
void User::setNumBook(long numB)
{
	fstream paramFin("param_data.txt");
	ofstream paramFout("foo.txt");
	string temp;
	long num = 0;
	paramFin >> temp >> num;
	paramFin.ignore();
	paramFout << temp << '\t' << numB << endl;
	for (int i = 1; i <= 2; ++i)
	{
		paramFin >> temp >> num;
		paramFin.ignore();
		paramFout << temp << '\t' << num << endl;
	}
	paramFin.close();
	paramFout.close();
	remove("param_data.txt");
	rename("foo.txt", "param_data.txt");
}
long User::getNumBook() const
{
	fstream paramFin("param_data.txt");
	string temp;
	long num = 0;
	paramFin >> temp >> num;
	paramFin.close();
	return num;
}
void User::setNumUser(long numB)
{

	fstream paramFin("param_data.txt");
	ofstream paramFout("foo.txt");
	string temp;
	long num = 0;
	paramFin >> temp >> num;
	paramFin.ignore();
	paramFout << temp << '\t' << num << endl;
	
	paramFin >> temp >> num;
	paramFin.ignore();
	paramFout << temp << '\t' << numB << endl;

	paramFin >> temp >> num;
	paramFin.ignore();
	paramFout << temp << '\t' << num << endl;

	paramFin >> temp >> num;
	paramFin.ignore();
	paramFout << temp << '\t' << num << endl;

	paramFin.close();
	paramFout.close();
	remove("param_data.txt");
	rename("foo.txt", "param_data.txt");
}
long User::getNumUser() const
{
	fstream paramFin("param_data.txt");
	string temp;
	long num = 0;
	for (int i = 1; i <= 2; ++i)
	{
		paramFin >> temp >> num;
		paramFin.ignore();
	}
	paramFin.close();
	return num;
}
string User::getJob() const
{
	return userJob;
}
void User::setFAccount(long numB)
{
	fstream paramFin("param_data.txt");
	ofstream paramFout("foo.txt");
	string temp;
	long num = 0;
	for (int i = 1; i <= 2; ++i)
	{
		paramFin >> temp >> num;
		paramFin.ignore();
		paramFout << temp << '\t' << num << endl;
	}
	paramFin >> temp >> num;
	paramFout << temp << '\t' << numB << endl;
	paramFin.ignore();
	paramFin >> temp >> num;
	paramFout << temp << '\t' << num << endl;
	paramFin.close();
	paramFout.close();
	remove("param_data.txt");
	rename("foo.txt", "param_data.txt");
}
long User::getFAccount() const
{
	fstream paramFin("param_data.txt");
	string temp;
	long num = 0;
	for (int i = 1; i <= 3; ++i)
	{
		paramFin >> temp >> num;
		paramFin.ignore();
	}
	return num;
}
void User::readUser(long id)
{
	fstream dataFin("user_data.txt");
	dataFin.seekg((id - 1) * sizeof(User));
	dataFin.read(reinterpret_cast<char*>(this), sizeof(User));
	dataFin.close();
}
void User::saveUser()
{
	fstream dataFout("user_data.txt");
	dataFout.seekg((getLibID() - 1) * sizeof(User));
	dataFout.write(reinterpret_cast<char*>(this), sizeof(User));
	dataFout.close();
}
void User::saveUser(long id)
{
	fstream dataFout("user_data.txt");
	dataFout.seekg((id - 1) * sizeof(User));
	dataFout.write(reinterpret_cast<char*>(this), sizeof(User));
	dataFout.close();
}
bool User::isDupEmail(string mail)
{
	User xxx;
	for (int i = 0; i < getNumUser(); ++i)
	{
		xxx.readUser(i + 1);
		if (mail == xxx.getMailAddr())
			return true;
	}
	return false;
}
bool User::isDupUID(long uid)
{
	User temp;
	for (int i = 0; i < getNumUser(); ++i)
	{
		temp.readUser(i + 1);
		if (temp.getUserID() == uid)
			return true;
	}
	return false;
}
bool User::isDupPID(long pid)
{
	User temp;
	for (int i = 0; i < getNumUser(); ++i)
	{
		temp.readUser(i + 1);
		if (temp.getUserPID() == pid)
			return true;
	}
	return false;
}


void User::setFNumRent(long numR)
{
	fstream paramFin("param_data.txt");
	ofstream paramFout("foo.txt");
	string temp;
	long num = 0;
	for (int i = 1; i <= 3; ++i)
	{
		paramFin >> temp >> num;
		paramFin.ignore();
		paramFout << temp << '\t' << num << endl;
	}
	paramFin >> temp >> num;
	paramFout << temp << '\t' << numR << endl;
	paramFin.close();
	paramFout.close();
}
long User::getFNumRent() const
{
	fstream paramFin("param_data.txt");
	ofstream paramFout("foo.txt");
	string temp;
	long num = 0;
	for (int i = 1; i <= 4; ++i)
	{
		paramFin >> temp >> num;
		paramFin.ignore();
		paramFout << temp << '\t' << num << endl;
	}
	paramFin.close();
	paramFout.close();
	return num;
}

void User::outputSpecific() const
{
	cout << "Ten: " << getFullName() << endl;
	cout << "Ngay sinh: " << getDOB() << endl;
	cout << "Nghe nghiep" << getJob() << endl;
	cout << "CMND: " << getUserPID() << endl;
	cout << "MSSV: " << getUserID() << endl;
	cout << "Email: " << getMailAddr() << endl;
}

void User::exitProg() const
{
	cout << "Thoat chuong trinh..." << endl;
	this_thread::sleep_for(chrono::seconds(3));
	exit(EXIT_SUCCESS);
}
void User::outputMainInfo() const
{
	cout << getFullName()<< '\t' << getUserID() << '\t' << getUserPID() << '\t' << getDOB() << '\t' << getJob() << '\t' << '\t' << endl;
}
void User::addMoreAccount(long id)
{
	listAccount[getNumAccount()] = id;
	++numAccount;
}