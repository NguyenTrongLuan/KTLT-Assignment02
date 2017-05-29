#ifndef ASSIGNMENT2_USER_H
#define ASSIGNMENT2_USER_H


#include "Account.h"
#include "Book.h"
#include "Date.h"
#include "RentBook.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>


const size_t NAME_SIZE = 30;
const size_t DOB_SIZE = 11;
const size_t JOB_SIZE = 20;
const size_t MAIL_SIZE = 50;
const size_t NUM_ACCOUNT = 5;
const size_t MAX_RENT = 15;

class User
{
public:
	User(long lid = 0, long uid = 0, long pid =0 , std::string name = "", std::string dob = "", std::string job = "", std::string mail = "",
		long[NUM_ACCOUNT] = {}, int numA = 0, bool st = false);
	User(long lid, long uid, long pid, std::string name, std::string dob, std::string job, std::string mail, bool st);
	void setLibID(long);
	void setUserID(long);
	void setPID(long);
	void setFullName(std::string);
	void setDayOfB(std::string);
	void setJob(std::string);
	void setMailAddr(std::string);
	void setAccountList(long[NUM_ACCOUNT]);
	void setNumAccount(long);
	void setState(bool);
	long getLibID() const;
	long getUserID() const;
	long getUserPID() const;
	std::string getFullName() const;
	std::string getDOB() const;
	std::string getMailAddr() const;
	std::string getJob() const;
	long* getAccountList() ;
	long getNumAccount() const;
	bool getState() const;
	


	void setNumBook(long);
	long getNumBook() const;
	void setNumUser(long);
	long getNumUser() const;
	void setFAccount(long);
	long getFAccount() const;
	void setFNumRent(long);
	long getFNumRent() const;
	
	void readUser(long);
	void saveUser();
	void saveUser(long);

	bool isDupEmail(std::string);
	bool isDupUID(long);
	bool isDupPID(long);

	void outputSpecific() const;
	void outputMainInfo() const;
	void exitProg() const;

	void addMoreAccount(long);
private:
	
	long libID;				// Ma so thu vien
	long userID;					// Ma so sinh vien / giao vien
	long PID;						// CMND
	char fullName[NAME_SIZE];		// Ten day du
	char dayOfBirth[DOB_SIZE];		// Ngay thang nam sinh
	char userJob[JOB_SIZE];			// Nghe nghiep
	char mailAddr[MAIL_SIZE];       // Dia chi email
	int numAccount;
	long listAccount[NUM_ACCOUNT];	// Danh sach tai khoan
	
	bool state;					// Trang thai hoat dong
};
#endif // !ASSIGNMENT2_USER_H
