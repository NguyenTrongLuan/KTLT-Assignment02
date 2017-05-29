#ifndef ASSIGNMENT2_READER_H
#define ASSIGNMENT2_READER_H

#include "User.h"

using namespace std;
class Reader : public User
{
public:
	Reader(long lid = 0, long uid = 0, long pid = 0, std::string name = "", std::string dob = "", std::string job = "", std::string mail = "",
		long[NUM_ACCOUNT] = {}, int numA = 0, bool st = false);
	Reader(long lid, long uid, long pid, std::string name, std::string dob, std::string job, std::string mail, bool st);
	Reader(const User&);
	void findBook();		// Tim sach
	void readNotif();		// Xem thong bao, chua biet la thong bao gi
	void readInfo();		// Xem thong tin, chua biet thong tin gi 
	void changePassword();	// Doi mat khau
	void userInteract();		// Menu khi nguoi dung dang nhap la  reader
	void rentBook();		// Muon sach, xuat ra man hinh yeu cau ......
	void endProg();			// Khi ket thuc chuc nang, co lua chon quay lai / thoat
private:
};

#endif // !ASSIGNMENT2_READER_H
