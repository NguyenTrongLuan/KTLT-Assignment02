//
// Created by hvlpro98 on 02/05/2017.
//

#ifndef ASSIGNMENT2_BOOK_H
#define ASSIGNMENT2_BOOK_H

#include <iostream>
#include <fstream>
#include <string>
#include "Date.h"
#define TYPE_SIZE 50
#define AUTHOR_SIZE 100
#define TITLE_SIZE 100
#define SUM_SIZE 400

class Book
{
public:
	Book(std::string = "", std::string = "", std::string = "", std::string = "", int = 0, long = 0, long = 0);	// Constructor, it dung
	std::string getName() const;	// Tra ve ten sach
	std::string getAuthor() const;	// Tra ve ten tac gia
	long getTimeAccess() const;		// Tra ve so luot xem sach do
	long getBookID() const;			// Tra ve ma so sach
	void setTitle(std::string);		// Gan ten sach
	void setAuthor(std::string);	// Gan ten tac gia
	void setBookID(long);			// Gan ma so sach
	void setTimesAcess(long);		// Gan so luot truy cap
	long getNumOfBook();			// Doc file, tra ve so sach da duoc luu
	void setNumOfBook(long);		// Ghi file, sua so sach duoc luu
	int getYear() const;			// Tra ve nam xuat ban
	std::string getType() const;	// Tra ve the loai
	void setType(std::string);		// Gan the loai
	void setSummary(std::string);	// Gan tom tat cho sach
	void outputSummary();		// In ra tom tat theo form, co thut dau dong, xuong hang...
	void outputMainInfo();	// Xuat ra thong tin co ban, dung khi tim kiem sach, chiem 1 hang
	void setAmount(int);			// Gan so luong cua loai sach do
	int getAmount() const;			// Tra ve so luong loai sach do

	void readData(long);			// Dua vao id, doc file luu thong tin vao doi tuong de dung
	void saveData();				// Luu du lieu vao file, tu dong lay ma so sach hien tai de xac dinh vi tri luu
	void saveData(long);;	// Xuat ra thong tin cu the, dung khi nguoi dung muon xem sach chi tiet, chiem man hinh nhieu hon (~ 7 hang)
	void setDateAdd();
	Date getDateAdd() const;
	void changeInfo();
	void setYear(int);
	void outputSpecific() ;
private:
	size_t my_strlen(const char *str);
	long bookID;					// Ma so sach
	char bookTitle[TITLE_SIZE];		// Ten sach
	char bookAuthor[AUTHOR_SIZE];	// Tac gia
	char type[TYPE_SIZE];			// The loai
	char summary[SUM_SIZE];			// Tom tat
	int year;						// Nam san xuat
	long amount;					// So luong cua loai sach do
	long timesAccess;				// So lan truy cap sach do
	Date dateAdd;
};
#endif //ASSIGNMENT2_BOOK_H
