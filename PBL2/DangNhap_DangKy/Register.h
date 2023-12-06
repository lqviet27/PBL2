#pragma once
#include "SignIn.h"

class Register
{
public:
    static void NhapThongTinKhachHang(Node<Bank> *,QLKH&, QLTK&);
    static void DangKi(QLNH&,QLKH&,QLTK&);
    static Node<Bank>* ChonNganHang(QLNH&);
};
