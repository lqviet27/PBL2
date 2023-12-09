#pragma once
#include "../Menu/Menu.cpp"
// #include "../QuanLy/Account/QLTK.cpp"
#include "../QuanLy/Bank/QLNH.cpp"
#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;


class SignIn
{
public:
    static void DangNhapQuaSoLanQuyDinh();
    static Node<Account>* DangNhap(QLNH &,QLKH &,QLTK &);
};
