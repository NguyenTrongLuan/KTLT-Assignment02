#include "Account.h"
using namespace std;
Account::Account(long lid, long aid, string usn, string pwd, string role, bool st)
	:state(st),libID(lid),accountID(aid)
{
	setUserName(usn);
	setPassword(pwd);
	setRole(role);
}
void Account::setNumAccount(long numA)
{
	User temp;
	temp.setFAccount(numA);
}
long Account::getNumAccount()
{
	User temp;
	return temp.getFAccount();
}
void Account::setUserName(string usn)
{
	int size = usn.size() < USN_SIZE ? usn.size() : USN_SIZE - 1;
	usn.copy(userName, size);
	userName[size] = '\0';
}
void Account::setPassword(string pwd)
{
	int size = pwd.size() < PWD_SIZE ? pwd.size() : PWD_SIZE - 1;
	pwd.copy(password, size);
	password[size] = '\0';
}
void Account::setState(bool st)
{
	state = st;
}
void Account::setLibID(long lid)
{
	libID = lid;
}
void Account::setAccountID(long aid)
{
	accountID = aid;
}
long Account::getLibID() const
{
	return libID;
}
long Account::getAccountID() const
{
	return accountID;
}
std::string Account::getUserName() const
{
	return userName;
}
std::string Account::getPassword() const
{
	return password;
}
bool Account::getState() const
{
	return state;
}
void Account::readData(long id)
{
	fstream dataFin("account_data.txt");
	dataFin.seekg((id - 1) * sizeof(Account));
	dataFin.read(reinterpret_cast<char*>(this), sizeof(Account));
	dataFin.close();
}
void Account::saveData()
{
	saveData(getAccountID());
}
void Account::saveData(long id)
{
	fstream dataFout("account_data.txt");
	dataFout.seekp((id - 1) * sizeof(Account));
	dataFout.write(reinterpret_cast<char*>(this), sizeof(Account));
	dataFout.close();
}

bool Account::isDupUSN(string usn)
{
	User temp;
	Account tempA;
	fstream dataFin("account_data.txt");
	for (int i = 1; i <= temp.getFAccount(); ++i)
	{
		dataFin.seekg((i - 1) * sizeof(Account));
		dataFin.read(reinterpret_cast<char*>(&tempA), sizeof(Account));
		if (tempA.getUserName() == usn)
		{
			dataFin.close();
			return true;
		}
	}
	dataFin.close();
	return false;
}
void Account::setRole(string role)
{
	int size = role.size() < ROLE_SIZE ? role.size() : ROLE_SIZE - 1;
	role.copy(userRole, size);
	userRole[size] = '\0';
}
string Account::getRole() const
{
	return userRole;
}
void Account::setNumRent(long numR)
{
	numRent = numR;
}
long Account::getNumRent() const
{
	return numRent;
}
void Account::setRentList(long rList[MAX_RENT2])
{
	for (int i = 0; i < getNumRent(); ++i)
		rentList[i] = rList[i];
}
long* Account::getRentList()
{
	return rentList;
}
void Account::outputData() const
{
	cout << getLibID() << '\t' << getAccountID() << '\t' << getUserName() << '\t' 
		<< getPassword() << (getState() ? "ACTIVE" : "LOCK") << endl;
}
void Account::addRentRecord(long id)
{
	rentList[numRent++] = id;
}