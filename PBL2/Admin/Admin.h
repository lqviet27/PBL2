#include <filesystem>
namespace fs = std::filesystem;
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

class AdminQLNH{
    public:
        static void TraCuuDanhSachNganHang(QLNH&);
        static void ThemNganHang(QLNH&);
        static void XoaNganHang(QLNH&,QLKH&,QLTK&);
        static void CapNhapThongTinNganHang(QLNH&);
        static void TraCuuDanhSachTaiKhoan(QLNH&);
        static void TraCuuDanhSachKhachHang(QLNH&);
        static void TongDoanhThu(QLNH&);
        static void ThongKeSoLuongNapTien(QLNH&);
        static void ThongKeSoLuongRutTien(QLNH&);
        static void ThongKeSoLuongChuyenTien(QLNH&);
};

