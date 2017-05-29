#ifndef ASSIGNMENT2_ACCOUNT_H
#define ASSIGNMENT2_ACCOUNT_H


#include "User.h"
#include <string>
#include <iostream>
#include <fstream>


const size_t USN_SIZE = 30;
const size_t PWD_SIZE = 30;
const size_t ROLE_SIZE = 4;
const size_t MAX_RENT2 = 15;
class Account
{
public:
	Account(long lid = 0, long aid = 0, std::string usn = "", std::string pwd = "", std::string role ="100", bool st = false);
	void setNumAccount(long);
	long getNumAccount();		// Read file and return number of account saved
	void setUserName(std::string);
	void setPassword(std::string);
	void setState(bool);
	void setLibID(long);
	void setAccountID(long);
	long getLibID() const;
	long getAccountID() const;
	std::string getUserName() const;
	std::string getPassword() const;
	bool getState() const;
	void setRole(std::string);
	std::string getRole() const;
	void setNumRent(long );
	long getNumRent() const;
	void setRentList(long [MAX_RENT2]);
	long* getRentList();



	void readData(long);
	void saveData();
	void saveData(long);

	bool isDupUSN(std::string);

	void outputData() const;
	void addRentRecord(long);
private:
	
	long libID;
	long accountID;
	char userName[USN_SIZE];
	char password[PWD_SIZE];
	char userRole[ROLE_SIZE];
	int numRent;
	long rentList[MAX_RENT2];
	bool state;
};
#endif // !ASSIGNMENT2_ACCOUNT_H
