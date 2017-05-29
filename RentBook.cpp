#include "RentBook.h"
using namespace std;
RentBook::RentBook(long rid, long lid, Date rentD, Date expireD, long bid, bool st)
	:rentID(rid),libID(lid),rentDate(rentD),expDate(expireD),bookID(bid),isReturn(st)
{}
void RentBook::setRentID(long rid)
{
	rentID = rid;
}
void RentBook::setLibID(long lid)
{
	libID = lid;
}
void RentBook::setRentDate(const Date &rent)
{
	rentDate = rent;
}
void RentBook::setExpireDate(const Date &exp)
{
	expDate = exp;
}
void RentBook::setBookID(long bid)
{
	bookID = bid;
}
void RentBook::setState(bool st)
{
	isReturn = st;
}
long RentBook::getRentID() const
{
	return rentID;
}
long RentBook::getLibID() const
{
	return libID;
}
Date RentBook::getRentDate() const
{
	return rentDate;
}
Date RentBook::getExpDate() const
{
	return expDate;
}
long RentBook::getBookID() const
{
	return bookID;
}
bool RentBook::getState() const
{
	return isReturn;
}

void RentBook::setNumRent(long numR)
{
	fstream paramIn("param_data.txt");
	ofstream paramOut("foo.txt");
	string temp;
	long num;
	for (int i = 0; i < 3; ++i)
	{
		paramIn >> temp >> num;
		paramIn.ignore();
		paramOut << temp << '\t' << num << endl;
	}
	paramIn >> temp;
	paramOut << temp << '\t' << numR << endl;
	paramIn.close();
	paramOut.close();
}
long RentBook::getNumRent() const
{
	fstream paramIn("param_data.txt");
	string temp;
	long num;
	for (int i = 0; i < 4; ++i)
	{
		paramIn >> temp >> num;
		paramIn.ignore();
	}
	return num;
}
void RentBook::saveData()
{
	saveData(getRentID());
}
void RentBook::saveData(long rid)
{
	fstream dataFout("rent_data.txt");
	dataFout.seekp((rid - 1) * sizeof(RentBook));
	dataFout.write(reinterpret_cast<char*>(this), sizeof(RentBook));
	dataFout.close();
}
void RentBook::readData(long rid)
{
	fstream dataFin("rent_data.txt");
	dataFin.seekg((rid - 1) * sizeof(RentBook));
	dataFin.read(reinterpret_cast<char*>(this), sizeof(RentBook));
}