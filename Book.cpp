
#include "Book.h"
using namespace std;
Book::Book(string name, string author, string typ, string summ, int y, long times, long amou)
	:bookID(0), timesAccess(times), year(y), amount(amou)
{
	setTitle(name);
	setAuthor(author);
	setTimesAcess(times);
	setType(typ);
	setSummary(summ);
	setAmount(amount);
}
void Book::setAuthor(string author)
{
	int size = (author.size() < AUTHOR_SIZE ? author.size() : AUTHOR_SIZE - 1);
	author.copy(bookAuthor, size);
	bookAuthor[size] = '\0';
}
void Book::setBookID(long id)
{
	bookID = id;
}
void Book::setTimesAcess(long times)
{
	timesAccess = times;
}
void Book::setTitle(string name)
{
	int size = (name.size() < TITLE_SIZE ? name.size() : TITLE_SIZE - 1);
	name.copy(bookTitle, size);
	bookTitle[size] = '\0';
}
string Book::getAuthor() const
{
	return bookAuthor;
}
string Book::getName() const
{
	return bookTitle;
}
long Book::getTimeAccess() const
{
	return timesAccess;
}
long Book::getBookID() const
{
	return bookID;
}

long Book::getNumOfBook()
{
	ifstream readParam("param_data.txt");
	string temp;
	long numBook;
	for (int i = 1; i <= 3; ++i)
		readParam >> temp >> numBook;
	return numBook;
}
void Book::setNumOfBook(long num)
{
	fstream readParam("param_data.txt");
	ofstream xxx("foo.txt");
	xxx.close();
	fstream newFile("foo.txt");
	string temp;
	long numBook = 0;
	readParam.seekp(0);
	readParam >> temp >> numBook;
	readParam.ignore();
	newFile << temp << ' ' << numBook << endl;
	readParam >> temp >> numBook;
	newFile << temp << ' ' << num << endl;
	readParam.close();
	remove("param_data.txt");
	newFile.close();
	rename("foo.txt", "param_data.txt");
}
int Book::getYear() const
{
	return year;
}
void Book::setType(string typ)
{
	int size = typ.size() < TYPE_SIZE ? typ.size() : TYPE_SIZE - 1;
	typ.copy(type, size);
	type[size] = '\0';
}
string Book::getType() const
{
	return type;
}
void Book::setSummary(string s)
{
	int size = s.size() < SUM_SIZE ? s.size() : SUM_SIZE - 1;
	s.copy(summary, size);
	summary[size] = '\0';
}
void Book::outputSummary()
{
	cout << "   ";
	int counter = 0;
	for (int i = 0; i < my_strlen(summary); ++i)
	{
		cout << summary[i];
		++counter;
		if (counter >= 60 && summary[i] == ' ')
		{
			cout << endl;
			counter = 0;
		}
	}
	cout << endl;
}
void Book::outputSpecific() 
{
	cout << "Ma so sach: " << getBookID() << endl;
	cout << "Ten sach: " << getName() << endl;
	cout << "Tac gia: " << getAuthor() << endl;
	cout << "Nam phat hanh: " << getYear() << endl;
	cout << "So luong con lai: " << getAmount() << endl;
	cout << "Tom tat noi dung: " << endl;
	outputSummary();
}
void Book::setAmount(int amou)
{
	amount = amou;
}
int Book::getAmount() const
{
	return amount;
}
void Book::readData(long bid)
{
	ifstream bookFin("book_data.txt");
	bookFin.seekg((bid - 1) * sizeof(Book));
	bookFin.read(reinterpret_cast<char*>(this), sizeof(Book));
	bookFin.close();
}
void Book::saveData()
{
	fstream bookFout("book_data.txt");
	bookFout.seekp((getBookID() - 1) * sizeof(Book));
	bookFout.write(reinterpret_cast<char*>(this), sizeof(Book));
	bookFout.close();
}
void Book::saveData(long id)
{
	fstream bookFout("book_data.txt");
	bookFout.seekp((id - 1) * sizeof(Book));
	bookFout.write(reinterpret_cast<char*>(this), sizeof(Book));
	bookFout.close();
}
void Book::outputMainInfo()
{
	cout << getBookID() << '\t' << getName() << '\t' << getAuthor() << '\t' << getYear() << endl;
}
void Book::setDateAdd()
{
	dateAdd = dateAdd.getCurrentDate();
}
Date Book::getDateAdd() const
{
	return dateAdd;
}
void Book::changeInfo()
{
	cout << "Nhap -1 de bo qua " << endl;
	cout << "Nhap ten sach moi: ";
	string newTitle;
	getline(cin, newTitle);
	cout << "Nhap ten tac gia moi: ";
	string newAuthor;
	getline(cin, newAuthor);
	cout << "Nhap the loai: ";
	string newType;
	getline(cin, newType);
	string summ;
	cout << "Nhap tom tat: ";
	getline(cin, summ);
	cout << "Nhap nam san xuat: ";
	int year;
	cin >> year;
	cin.ignore();
	int amount;
	cout << "Nhap so luong: ";
	cin >> amount;
	cin.ignore();
	if (newTitle != "-1")
		setTitle(newTitle);
	if (newAuthor != "-1")
		setAuthor(newAuthor);
	if (newType != "-1")
		setType(newType);
	if (summ != "-1")
		setSummary(summ);
	if (year != -1)
		setYear(year);
	if (amount != -1)
		setAmount(amount);


}
void Book::setYear(int y)
{
	year = y;
}
size_t Book::my_strlen(const char *str)
{
  size_t i;

  for (i = 0; str[i]; i++);
  return i;
}