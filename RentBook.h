#ifndef ASSIGNMENT2_RENTBOOK_H
#define ASSIGNMENT2_RENTBOOK_H

#include "Date.h"
#include <fstream>
#include <string>

class RentBook
{
public:
	RentBook(long = 0, long = 0, Date = {}, Date = {}, long = 0, bool = false);
	void setRentID(long);
	void setLibID(long);
	void setRentDate(const Date &);
	void setExpireDate(const Date &);
	void setBookID(long);
	void setState(bool);

	long getRentID() const;
	long getLibID() const;
	Date getRentDate() const;
	Date getExpDate() const;
	long getBookID() const;
	bool getState() const;

	void setNumRent(long);			// Open file - > set number of record
	long getNumRent() const;		//	Open file - > get number of record
	void saveData();
	void saveData(long);			
	void readData(long);

private:
	long rentID;
	long libID;
	Date rentDate;
	Date expDate;
	long bookID;
	bool isReturn;
};
#endif // !ASSIGNMENT2_RENTBOOK_H
