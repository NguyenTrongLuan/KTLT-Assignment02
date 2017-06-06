#pragma once

/*
 * -------------------- Introduction ----------------------------
 *																
 * BookStorage.h													
 * Created by Nguyen Trong Luan				
 * Bach Khoa University - CSE Department						
 * Descripbe : Thư viện này giống như một kho sách cho độc giả, độc giả có thể		
 * xem những cuốn sách mình đang mượn																
 * --------------------------------------------------------------
 */

/*
 Khi độc giả đang mượn cuốn nào, thời gian mượn, trả, mọi thứ sẽ lưu vào đối tượng này, liên kết qua dữ liệu tv UserName
 Khi độc giả trả sách, thông tin trên sẽ mất, giải phóng
 Khi độc giả làm mất, lúc thủ thư chọn chức năng giải quyết việc mất sách, thì thông tin cũng sẽ được xóa

 Số sách được mượn tối đa ở dưới là 10, chỉ là tạm thời, Thức có thể thay đổi! Và thay xong thì thay đổi hết trong các hàm t viết
*/

#ifndef _BOOK_STORAGE_H
#define _BOOK_STORAGE_H


#include <iostream>
#include <array>
#include <string>
#include <fstream>

class BookStorage
{
public:
	BookStorage();
	void setUserName(std::string);
	void setlistRent(const std::array<long, 10>&);
	void setNumRent(const int&);

	std::string getUserName() const;
	std::array<long, 10> getlistRent() const;
	int getNumRent() const;

	void saveData();
	void readData(std::string);
private:
	char UserName[35];						//Ten tai khoan
	std::array<long, 10> listRent;			//Danh sach cac lan muon, moi lan muon nhieu lam la 10 cuon
	int numRent;							//So sach dang muon
};

#endif // !_BOOK_STORAGE_H
