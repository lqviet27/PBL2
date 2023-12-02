#pragma once
#include "SignIn.h"

class Register
{
public:
    static void NhapThongTinKhachHang();
    static Node<Account>* DangKi(QLNH&,QLKH&,QLTK&);
    static Node<Bank>* ChonNganHang(QLNH&);

};
