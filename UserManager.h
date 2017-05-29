#ifndef ASSIGNMENT2_USERMANAGER_H
#define ASSIGNMENT2_USERMANAGER_H


#include "User.h"

#include <iostream>
#include <fstream>
#include <string>

class UserManager : public User
{
public:
	UserManager(long lid = 0, long uid = 0, long pid = 0, std::string name = "", std::string dob = "", std::string job = "", std::string mail = "",
		long[NUM_ACCOUNT] = {}, int numA = 0, bool st = false);
	UserManager(long lid, long uid, long pid, std::string name, std::string dob, std::string job, std::string mail, bool st);
	UserManager(const User&);
	void addNewUser();			// Xuat ra menu them nguoi dung moi, xem nhu dang nhap lieu
	void deleteUser();			// Xoa nguoi dung, in ra menu day du
	void deleteUser(long);		// Xoa nguoi dung, nhan vao ma so thu vien tu dong xoa luon
	void lockUser();			// Khoa nguoi dung, xuat ra menu ..
	void lockUser(long);		// Dua vao ma so thu vien tu dong khoa luon
	void unlockUser();			// Tong tu hai ham tren
	void unlockUser(long);
	void resetPassword();		// Reset mat khau
	void resetPassword(long);	// Reset mat khau
	void findUser();			// Tim kiem nguoi dung
	void userInteract();		// Xu ly menu khi doc gia truy cap voi tu cach User Manager
	void endProg();				// Khi ket thuc 1 chuc nang, co lua chon thoat/ quay lai
	void editUser(long id);		// Sua thong tin nguoi dung
private:

};

#endif // !ASSIGNMENT2_USERMANAGER_H
