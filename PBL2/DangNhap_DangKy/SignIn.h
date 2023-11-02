#pragma once
#include "../Menu/Menu.cpp"
#include <iostream>
#include <conio.h>
#include "../QuanLy/Account/ListAccount.cpp"
#include "../QuanLy/Bank/QLNH.cpp"
#include <string.h>
using namespace std;

class SignIn
{
public:
    static void DangNhapQuaSoLanQuyDinh();
    static string DangNhap(QLNH &);
};
