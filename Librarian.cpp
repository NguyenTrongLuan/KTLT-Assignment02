#include "Librarian.h"
using namespace std;
Librarian::Librarian(long lid, long uid, long pid, string name, string dob, string job, string mail,
	long listA[NUM_ACCOUNT], int numA, bool st)
	:User(lid, uid, pid, name, dob, job, mail, listA, numA, st)
{}
Librarian::Librarian(long lid, long uid, long pid, string name, string dob, string job, std::string mail, bool st)
	: User(lid, uid, pid, name, dob, job, mail, st)
{}
Librarian::Librarian(const User &temp)
	: User(temp)
{}
void Librarian::addBook()		// 100%
{
	system("cls");
	cout << "--------------------THEM SACH-----------------" << endl;
	cout << "Nhap ten sach: ";
	string title;
	getline(cin, title);
	cout << "Nhap ten tac gia: ";
	string auth;
	getline(cin, auth);
	cout << "Nhap the loai: ";
	string typ;
	getline(cin, typ);
	cout << "Nhap nam san xuat: ";
	int year = 0;
	cin >> year;
	cout << "Nhap so luong: ";
	int amou = 0;
	cin >> amou;
	cin.ignore();
	cout << "Nhap tom tat: ";
	string summ;
	getline(cin, summ);
	Book newBook(title, auth, typ, summ, year, 0, amou);
	newBook.setBookID(getNumBook() + 1);
	newBook.saveData();
	setNumBook(getNumBook() + 1);
	cout << "\n\nThem sach thanh cong" << endl;
	cout << "Nhap -1 de tiep tuc them sach " << endl;
	cout << "Nhap 0 de quay lai man hinh chinh " << endl;
	cout << "Nhap 1 de thoat khoi chuong trinh" << endl;
	cout << "Nhap vao lua chon: ";
	int choose = 0;
	cin >> choose;
	switch (choose)
	{
	case -1:
		cin.ignore();
		addBook();
		break;
	case 0:
		cin.ignore();
		userInteract();
		break;
	case 1:
		exit(EXIT_SUCCESS);
		break;
	default:
		exit(EXIT_SUCCESS);
		break;
	}
}
void Librarian::userInteract()	// 100%
{
	system("cls");
	cout << "1. Them sach" << endl;
	cout << "2. Sua doi thong tin sach" << endl;
	cout << "3. Xoa sach khoi he thong" << endl;
	cout << "4. Tim kiem sach" << endl;
	cout << "5. Kiem tra cac yeu cau" << endl;
	cout << "6. Phat nguoi dung vi vi pham" << endl;
	cout << "7. Giai quyet truong hop mat sach" << endl;
	cout << "0. Thoat" << endl;
	cout << "Nhap lua chon: ";
	int choose = 0;
	cin >> choose;
	while (choose<0 || choose>7)
	{
		cout << "Lua chon khong hop le, nhap lai: ";
		cin >> choose;
	}

	if (choose >= 0 && choose <= 7)
	{
		cin.ignore();
		enum { EXIT = 0, ADD = 1, CHANGE = 2, DELETE = 3, FIND = 4, CHECK_REQ, PENALIZE, LOST };
		switch (choose)
		{
		case EXIT:
			exit(EXIT_SUCCESS);
			break;
		case ADD:
			addBook();
			break;
		case CHANGE:
			changeBookInfo();
			break;
		case DELETE:
			deleteBook();
			break;
		case FIND:
			findBook();
			break;
		case CHECK_REQ:
			verifyRequest();
			break;
		case PENALIZE:
			penalizeUser();
			break;
		case LOST:
			lostBook();
			break;
		default:
			break;
		}
	}
}
void Librarian::changeBookInfo()	// Not tested yet
{
	system("cls");
	cout << "---------------------THAY DOI THONG TIN SACH--------------------" << endl;
	Book tempBook;
	cout << "Nhap ma so sach muon thay doi thong tin" << endl;
	long idx = 0;


	cout << "Nhap 0 de quay lai " << endl;
	cout << "Nhap -1 de thoat" << endl;
	cout << "Nhap lua chon: ";
	cin >> idx;
	tempBook.readData(idx);
	while (tempBook.getBookID() == 0)			// Xac thuc lua chon cua nguoi dung
	{
		if (idx == 0)
			userInteract();
		else if (idx == -1)
			exit(EXIT_SUCCESS);
		else
		{
			cout << "Khong tim thay sach yeu cau, nhap lai yeu cau:  ";
			cin >> idx;
			tempBook.readData(idx);
		}
	}			// Sau khi xac thuc xong yeu cau nguoi dung
	if (tempBook.getBookID() != 0)		// Neu tim thay thong tin thoa man
	{
		cout << "Tim thay thong tin: " << endl;
		tempBook.outputSpecific();
		cout << "Nhap 1 de xac xac nhan doi thong tin" << endl;
		cout << "Nhap 0 de quay lai" << endl;
		cout << "Nhap -1 de thoat chuong trinh" << endl;
		cout << "Nhap lua chon: ";
		int choose = 0;
		cin >> choose;
		cin.ignore();
		switch (choose)
		{
		case 1:
		{
			tempBook.changeInfo();
			tempBook.saveData();
			cout << "Sua thong tin thanh cong" << endl;
			cout << "Nhap 0 de thoat " << endl;
			cout << "Nhap 1 de quay lai man hinh chinh" << endl;
			int choose2 = 0;
			cin >> choose2;
			switch (choose2)
			{
			case 0:
				exit(EXIT_SUCCESS);
				break;
			case 1:
				userInteract();
				break;
			default:
				break;
			}
		}
		break;
		case 0:
			userInteract();
			break;
		case -1:
			exit(EXIT_SUCCESS);
		default:
			exit(EXIT_SUCCESS);
			break;
		}
	}
}
void Librarian::deleteBook() // Not tested yet
{
	system("cls");
	cout << "---------------XOA SACH KHOI THU VIEN-----------------" << endl;
	cout << "Nhap ma so sach can xoa " << endl;
	cout << "Nhap 0 de quay lai" << endl;
	cout << "Nhap -1 de thoat" << endl;
	cout << "Nhap lua chon: ";
	long bid = 0;
	cin >> bid;
	cin.ignore();
	while (bid < -1)
	{
		cout << "Lua chon khong hop le, nhap lai: ";
		cin >> bid;
		cin.ignore();
	}
	if (bid == 0)
		userInteract();
	else if (bid == -1)
		exit(EXIT_SUCCESS);
	else
	{
		Book tempBook;
		Book blankBook;
		tempBook.readData(bid);
		while (tempBook.getBookID() == 0)
		{
			cout << "Khong tim thay thong tin sach" << endl;
			cout << "Nhap lai lua chon: ";
			cin >> bid;
			while (bid < -1)
			{
				cout << "Lua chon khong hop le, nhap lai: ";
				cin >> bid;
				cin.ignore();
			}
			if (bid == 0)
				userInteract();
			else if (bid == -1)
				exit(EXIT_SUCCESS);
			else tempBook.readData(bid);

		}
		if (tempBook.getBookID() != 0)
		{
			system("cls");
			cout << "Tim thay thong tin: " << endl;
			tempBook.outputSpecific();
			cout << "Nhap 1 de xac nhan xoa" << endl;
			cout << "Nhap 0 de quay lai" << endl;
			cout << "Nhap -1 de thoat chuong trinh " << endl;
			cout << "Nhap lua chon: ";
			int choose = 0;
			cin >> choose;
			cin.ignore();
			switch (choose)
			{
			case 1:
			{
				blankBook.saveData(bid);
				cout << "Xoa sach thanh cong" << endl;
				endProg();
			}
			break;
			case 0:
				userInteract();
				break;
			case -1:
				exit(EXIT_SUCCESS);
				break;
			default:
				exit(EXIT_SUCCESS);
				break;
			}
		}
	}
}
void Librarian::verifyRequest()	// Muon, tra sach
{

}
void Librarian::penalizeUser()		// Phat vi qua han
{

}
void Librarian::lostBook()			// Giai quyet viec mat sach
{

}
void Librarian::endProg()	// Tested, 100%
{
	cout << "Nhap 0 de quay lai" << endl;
	cout << "Nhap 1 de thoat" << endl;
	cout << "Nhap lua chon: ";
	int choose = 0;
	cin >> choose;
	if (choose == 0)
		userInteract();
	else exit(EXIT_SUCCESS);
}
void Librarian::findBook() // Tested, 90%
{
	// Next version
	//	- Change search algorithm
	//  - Split search result if there is more than 10 result\
		//	- Enhance style
//	- Change date add
	system("cls");
	cout << "--------------------TIM SACH-----------------" << endl;
	Book tempBook;
	string fKey;
	map<int, long> fRes;
	int counter = 0;
	cout << "Nhap vao tu khoa: ";
	getline(cin, fKey);
	for (int i = 0; i < getNumBook(); ++i)		// Tim sach luu vao container ( O day dung std::map)
	{
		tempBook.readData(i + 1);
		if (tempBook.getAuthor().find(fKey) != string::npos
			|| tempBook.getName().find(fKey) != string::npos
			|| tempBook.getType().find(fKey) != string::npos
			|| to_string(tempBook.getYear()).find(fKey) != string::npos)
		{

			fRes.insert(make_pair(++counter, tempBook.getBookID()));
			if (counter == 1)
				cout << "Tim thay thong tin sau: " << endl;
			cout << counter << "   ";
			tempBook.outputMainInfo();
		}

	}
	if (fRes.size() == 0)			// Neu khong tim thay
	{
		cout << "Khong tim thay ket qua phu hop" << endl;
		cout << "0. Tiep tuc tim kiem" << endl;
		cout << "1. Quay lai menu chinh" << endl;
		cout << "2. Thoat chuong trinh" << endl;
		cout << "Nhap lua chon: ";
		int choose = 0;
		cin >> choose;
		cin.ignore();
		if (choose == 0)
			findBook();
		else userInteract();
	}
	else
	{
		cout << "Nhap so thu tu de chon sach" << endl;
		cout << "Nhap 0  de quay lai" << endl;
		cout << "Nhap -1 de thoat" << endl;
		int choose = 0;
		cin >> choose;
		cin.ignore();
		if (choose >= 1 && choose <= counter)
		{
			system("cls");
			cout << "Thong tin chi tiet: " << endl;
			tempBook.readData(fRes[choose]);
			tempBook.outputSpecific();
			int choose2 = 0;
			cout << "\n\n1. Thay doi thong tin" << endl;
			cout << "2. Xoa sach nay" << endl;
			cout << "3. Thoat chuong trinh" << endl;
			cout << "0. Quay lai" << endl;
			cin >> choose2;
			cin.ignore();
			while (choose > 3 || choose < 0)
			{
				cout << "Lua chon khong hop le" << endl;
				cin >> choose;
				cin.ignore();
			}
			switch (choose2)
			{
			case 1:
			{
				tempBook.changeInfo();
				tempBook.saveData();
				system("cls");
				cout << "Thay doi thong tin thanh cong" << endl;
				endProg();
			}
			break;
			case 2:
			{
				Book blankBook;

				blankBook.saveData(fRes[choose]);			// Replace old book by a blank record
				system("cls");
				cout << "Xoa sach nay thanh cong" << endl;
				endProg();
			}
			break;
			default:
				exit(EXIT_SUCCESS);
				break;
			}
		}
		else if (choose == 0)
			userInteract();
		else exit(EXIT_SUCCESS);
	}

}