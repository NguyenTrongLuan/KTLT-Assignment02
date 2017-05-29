#ifndef ASSIGNMENT2_LIBRARIAN_H
#define ASSIGNMENT2_LIBRARIAN_H

#include "User.h"
class Librarian : public User
{
public:
	Librarian(long lid = 0, long uid = 0, long pid = 0, std::string name = "", std::string dob = "", std::string job = "", std::string mail = "",
		long[NUM_ACCOUNT] = {}, int numA = 0, bool st = false);
	Librarian(long lid, long uid, long pid, std::string name, std::string dob, std::string job, std::string mail, bool st);
	Librarian(const User&);
	void addBook();			// Them sach
	void findBook();		// Tim sach
	void changeBookInfo();	// Sua thong tin sach
	void deleteBook();		// Xoa sach
	void verifyRequest();		// Muon, tra sach
	void penalizeUser();		// Phat vi qua han
	void lostBook();			// Giai quyet viec mat sach
	void userInteract();		// Menu khi nguoi dung dang nhap
	void endProg();				// Khi ket thuc 1 chuc nang, co lua chon quay lai / thoat
private:
};
#endif // !ASSIGNMENT2_LIBRARIAN_H

