#include "Reader.h"
using namespace std;
Reader::Reader(long lid, long uid, long pid, string name, string dob, string job, string mail,
	long listA[NUM_ACCOUNT], int numA, bool st)
	:User(lid, uid, pid, name, dob, job, mail, listA, numA, st)
{}
Reader::Reader(long lid, long uid, long pid, string name, string dob, string job, std::string mail
	, bool st)
	: User(lid, uid, pid, name, dob, job, mail, st)
{}
Reader::Reader(const User &temp)
	: User(temp)
{}
void Reader::findBook() // 80%
{
	// Issue:
	//	- Don't know which account in loged in
	system("cls");
	cout << "---------------TIM SACH---------------" << endl;
	map<int, long> findEntry;
	fstream fBook("book_data.txt");
	cout << "Nhap tu khoa can tim: ";
	string searchKey;
	cin >> searchKey;
	cin.ignore();
	Book tempBook;
	int counter = 0;
	for (int i = 0; i < getNumBook(); ++i)
	{
		tempBook.readData(i + 1);
		if (tempBook.getAuthor().find(searchKey) != string::npos
			|| tempBook.getName().find(searchKey) != string::npos
			|| tempBook.getType().find(searchKey) != string::npos
			|| to_string(tempBook.getYear()).find(searchKey) != string::npos)
			findEntry.insert(make_pair(++counter, tempBook.getBookID()));
	}
	if (counter == 0)
	{
		cout << "Khong tim thay thong tin yeu cau" << endl;
		cout << "Nhap 0 de quay lai" << endl;
		int choose = 0;
		cin >> choose;
		if (choose == 0)
			userInteract();
	}
	else
	{
		cout << "\n\nNhap so sach de xem thong tin" << endl;
		cout << "Nhap 0 de quay lai" << endl;
		cout << "Nhap -1 de thoat chuong trinh" << endl;
		cout << "Nhap vao lua chon: ";
		int choose = -2;
		while (choose <-1 || choose > counter)
		{
			cin >> choose;
			if (choose <-1 && choose > counter)
				cout << "Nhap lai: ";
			if (choose == 0)
			{
				fBook.close();
				userInteract();
			}
			if (choose == -1)
			{
				fBook.close();
				exit(EXIT_SUCCESS);
			}
		}
		if (choose >= 1 && choose <= counter)
		{
			system("cls");
			fBook.seekg((findEntry[choose] - 1) * sizeof(Book));
			fBook.read(reinterpret_cast<char*>(&tempBook), sizeof(Book));
			tempBook.outputSpecific();
			tempBook.setTimesAcess(tempBook.getTimeAccess() + 1);
			cout << "\n\nNhap 1 de vao muon sach" << endl;
			cout << "Nhap 0 de tro lai" << endl;
			cout << "Nhap -1 de thoat chuong trinh" << endl;
			cout << "Nhap vao lua chon: ";
			choose = -2;
			fBook.close();
			while (choose < -1 || choose > 1)
			{
				cin >> choose;
				if (choose == -1)
					exit(EXIT_SUCCESS);
				if (choose == 0)
					userInteract();
				if (choose == 1)
				{
					cout << "Nhap ngay muon muon: ";
					int days = 0;
					cin >> days;
					Date expDate;
					Date current;
					current = current.getCurrentDate();
					expDate = current + days;
					RentBook newRent(getFNumRent() + 1, getLibID(), current, expDate, findEntry[choose], false);
					newRent.saveData();
					setFNumRent(getFNumRent() + 1);
					// Chua add sach muon vao danh sach duoc
					cout << "Gui yeu cau muon sach thanh cong" << endl;
					// Need more logic
				}
			}
		}
	}
}
void Reader::userInteract()	// 100%
{
	system("cls");
	cout << "Nhap 1 de tim kiem sach" << endl;
	cout << "Nhap 2 de gui yeu cau muon sach" << endl;
	cout << "Nhap 3 de doc thong bao" << endl;
	cout << "Nhap 4 de doc thong tin" << endl;
	cout << "Nhap 5 de doi mat khau" << endl;
	cout << "Nhap 0 de quay lai" << endl;
	cout << "Nhap -1 de thoat chuong trinh" << endl;
	cout << "Nhap vao lua chon: ";
	int choose = -2;
	enum { FIND_BOOK = 1, RENT_BOOK, READ_NOTI, READ_INFO, CHANGE_PASSWORD };
	while (choose < -1 || choose >5)
	{
		cin >> choose;
		if (choose < -2 || choose >5)
			cout << "Lua chon khong hop le. Nhap lai: ";
		else

		{
			if (choose == 0)
				exit(EXIT_SUCCESS);
			else if (choose == -1)
				exit(EXIT_SUCCESS);
			else if (choose <= 5 && choose >= -1)
				switch (choose)
				{
				case FIND_BOOK:
					findBook();
					break;
				case RENT_BOOK:
					rentBook();
					break;
				case READ_NOTI:
					readNotif();
					break;
				case READ_INFO:
					readInfo();
					break;
				case CHANGE_PASSWORD:
					changePassword();
					break;
				default:
					break;
				}
		}
	}
}
void Reader::readNotif()		// 100%
{
/*	system("cls");
	cout << "1. Xem sach muon sap het han/ da het han" << endl;
	cout << "2. Xem thong tin sach moi ve" << endl;
	int choose = 0;
	RentBook userRentList;
	Date current;
	current = current.getCurrentDate();
	cin >> choose;
	while (choose != 1 && choose != 2)		// Xac thuc lua chon
	{
		cout << "Lua chon khong hop le, nhap 0 de quay lai, nhap lua chon: ";
		cin >> choose;
		if (choose == 0)
			userInteract();
	}
	int counter = 0;
	if (choose == 1)		// Xem sach muon sap het han/ da het han
	{

		userRentList.readData(getLibID());
		for (int i = 0; i < userRentList.getNumRent(); ++i)
		{
			if (current - userRentList.getRentLisk()[i].getDateRent() < 5 && !userRentList.getRentLisk()[i].getState())
			{
				++counter;
				if (counter == 1)
					cout << "De dinh dang lai dong nay sau" << endl;
				cout << userRentList.getRentLisk()[i].getBookID() << '\t' << userRentList.getRentLisk()[i].getDateRent() << '\t'
					<< userRentList.getRentLisk()[i].getDateExpire() << endl;
			}
		}
		if (!counter)
			cout << "Chua co thong tin ve sach sap het han/ da het han" << endl;
		endProg();
	}
	else if (choose == 2)		// Xem thong tin sach moi ve
	{
		int counter = 0;
		map<int, long> searchPair;
		for (int i = 1; i <= getNumBook(); ++i)		// Tim kiem thong tin thoa man luu vao container (Sach cap nhat cach day ko qua 14 ngay)
		{
			Book newBook;
			newBook.readData(i);
			if (current - newBook.getDateAdd() <= 14)	// Ngay hien tai - ngay cap nhat < 14
			{
				++counter;
				if (counter == 1)
					cout << "Tim thay thong tin: " << endl;
				cout << counter << '\t' << newBook.getBookID() << '\t' << newBook.getName() << '\t' << newBook.getAuthor() << endl;
				searchPair.insert(make_pair(counter, newBook.getBookID()));

			}
		}
		if (counter > 0)		// Neu tim thay thong tin thoa man (Sach cap nhat cach day ko qua 14 ngay)
		{
			cout << "Nhap thu tu de xem thong tin chi tiet" << endl;
			cout << "Nhap 0 de quay lai " << endl;
			cout << "nhap lua chon: ";
			int choose = 0;
			cin >> choose;
			while (choose < 0 || choose > counter)		// Xu ly neu lua chon khong hop le
			{
				cout << "Lua chon khong hop le" << endl;
				cout << "Nhap lai lua chon: ";
				cin >> choose;
				if (choose == 0)
					userInteract();
			}
			if (choose >= 1 && choose <= counter)			// Xuat ra thong tin chi tiet sach ma nguoi dung muon xem
			{
				Book newBook;
				newBook.readData(searchPair[choose]);
				newBook.outputSpecific();
				endProg();
			}
		}
		else if (!counter)		// Neu khong tim thay sach
		{
			cout << "Hien tai chua co sach moi " << endl;
			cout << "Ban vui long quay lai sau" << endl;
			endProg();
		}
	}
	*/
}
void Reader::readInfo()	// 60%
{
	/*system("cls");
	cout << "---------------------XEM THONG TIN-----------------------" << endl;
	ifstream infoFin("rent_data");
	cout << "1. Xem lich su muon sach" << endl;
	cout << "2. Xem lich su phat " << endl;
	cout << "Nhap lua chon: " << endl;
	int choose = 0;
	cin >> choose;
	while (choose != 1 && choose != 2)		// Khi nguoi dung nhap sai
	{
		cout << "Lua chon khong hop le, nhap 0 de quay lai, nhap lua chon: ";
		cin >> choose;
		if (!choose)
			userInteract();
	}
	if (choose == 1)		// Xem lich su muon sach
	{
		RentBook newRent;
		newRent.readData(getLibID());
		if (newRent.getNumRent() != 0)
		{
			cout << "Tim thay thong tin sau: " << endl;
			for (int i = 0; i < newRent.getNumRent(); ++i)
				cout << newRent.getRentLisk()[i].getBookID() << '\t' << newRent.getRentLisk()[i].getDateRent() << '\t' << newRent.getRentLisk()[i].getDateExpire() << endl;
			endProg();
		}
		else
		{
			cout << "Khong tim thay lich su muon sach cua nguoi nay" << endl;
			endProg();
		}
	}
	else
	{
		// Xem lich su bi phat
	}*/
}
void Reader::changePassword()
{
	system("cls");
	cout << "------------------DOI MAT KHAU----------------" << endl;
	Account tempAccount;
	tempAccount.readData(getLibID());
	cout << tempAccount.getNumAccount() << endl;
	cout << "Nhap ten dang nhap: ";
	string usn;
	cin >> usn;
	cin.ignore();
	cout << "Nhap mat khau cu: ";
	string pwd;
	cin >> pwd;
	cout << "Nhap mat khau moi: ";
	string newPwd;
	cin.ignore();
	cin >> newPwd;
	bool found = false;
	for (int i = 0; i < getNumAccount() && !found; ++i)
	{
		tempAccount.readData(getAccountList()[i]);
		if (tempAccount.getUserName() == usn && tempAccount.getPassword() == pwd)
			found = true;
	}
	if (!found)
	{
		cout << "Thong tin nhap vao khong chinh xac" << endl;
		cout << "Nhap 0 de quay lai" << endl;
		cout << "Nhap -1 de thoat chuong trinh" << endl;
		int choose = 0;
		cin >> choose;
		if (choose)
			exit(EXIT_SUCCESS);
		else userInteract();
	}
	else
	{
		tempAccount.setPassword(newPwd);
		tempAccount.saveData();
		cout << "Doi mat khau thanh cong" << endl;
		endProg();
	}
}	
void Reader::rentBook()				//	 xxx
{
	cout << "-------------------------MUON SACH---------------------------" << endl;
	cout << "Nhap ma so sach muon muon " << endl;
	cout << "Nhap -1 de quay lai " << endl;
	cout << "Nhap 0 de thoat" << endl;
	cout << "Nhap lua chon: ";
	long bid = 0;
	
	Book tempBook;
	
	while (bid < -1)
	{
		cout << "Lua chon khong hop le, nhap lai: ";
		cin >> bid;
		cin.ignore();
	}
	do
	{
		cin >> bid;
		cin.ignore();
		if (bid == 0)
			exitProg();
		else if (bid == -1)
			userInteract();
		else tempBook.readData(bid);
		if (tempBook.getBookID() == 0)
		{
		cout << "Khong tin thay thong tin sach yeu cau" << endl;
		cout << "Nhap lai yeu cau: ";
		}
	} while (tempBook.getBookID() == 0);
	Date current;
	cout << "Nhap thoi gian muon muon: ";
	int days = 0;
	cin >> days;
	Date expDate = current + days;
	current = current.getCurrentDate();
	RentBook newRent(getFNumRent() + 1, getLibID(), current, expDate, bid, false);
	newRent.saveData();
	setFNumRent(getFNumRent() + 1);
	// Chua them duoc vao danh sach muon
	cout << "Muon sach thanh cong" << endl;
	endProg();
}
void Reader::endProg()
{
	cout << "1. Quay lai" << endl;
	cout << "2. Thoat" << endl;
	cout << "Nhap vao lua chon: ";
	int choose = 0;
	cin >> choose;
	if (choose == 1)
		userInteract();
	else exit(EXIT_SUCCESS);
}