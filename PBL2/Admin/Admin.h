
#include"../QuanLy/Account/QLTK.cpp"
#include"../QuanLy/Users/QLKH.cpp"
#include"../QuanLy/Bank/QLNH.cpp"


class AdminQLTK{
    public:
        static void TraCuuThongTinTaiKhoan(QLTK &);
        static void TraCuuLichSuGiaoDich(QLTK &);
        static void XoaTaiKhoan(QLNH &,QLKH &,QLTK &);
};

class AdminQLKH{
    public:
        static void TraCuuDanhSachTaiKhoan(QLKH &);
        static void TraCuuThongTin(QLKH &);
        static void CapNhapThongTinKhachHang(QLNH &,QLKH &);
};