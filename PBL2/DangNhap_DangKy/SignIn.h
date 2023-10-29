#pragma once
#include <iostream>
#include <conio.h>
#include "../Menu/Menu.cpp"
#include "../QuanLy/Account/ListAccount.cpp"
#include <string.h>
using namespace std;

class SignIn
{
public:
    static void DangNhapQuaSoLanQuyDinh();
    static int DangNhap();
};
