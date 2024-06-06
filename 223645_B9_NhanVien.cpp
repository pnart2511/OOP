#include <iostream>
#include <string>

using namespace std;

class NhanVien {
protected:
    string hoTen;
    string ngaySinh;
    double luong;
public:
    virtual void nhapThongTin() = 0;
    virtual double tinhLuong() = 0;
    virtual void xuatThongTin() = 0;
    double getLuong() { return luong; }
};

class NhanVienVanPhong : public NhanVien {
private:
    int soNgayLamViec;
public:
    void nhapThongTin()  {
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "Nhap ngay sinh: ";
        getline(cin, ngaySinh);
        cout << "Nhap so ngay lam viec: ";
        cin >> soNgayLamViec;
    }

    double tinhLuong()  {
        luong = soNgayLamViec * 100000;
        return luong;
    }

    void xuatThongTin()  {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Ngay sinh: " << ngaySinh << endl;
        cout << "Luong: " << luong << endl;
    }
};

class NhanVienSanXuat : public NhanVien {
private:
    int luongCanBan;
    int soSanPham;
public:
    void nhapThongTin()  {
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "Nhap ngay sinh: ";
        getline(cin, ngaySinh);
        cout << "Nhap luong can ban: ";
        cin >> luongCanBan;
        cout << "Nhap so san pham: ";
        cin >> soSanPham;
    }

    double tinhLuong()  {
        luong = luongCanBan + soSanPham * 5000;
        return luong;
    }

    void xuatThongTin()  {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Ngay sinh: " << ngaySinh << endl;
        cout << "Luong: " << luong << endl;
    }
};
int main() {
    int MAX_NHANVIEN = 100;
    NhanVien* danhSachNhanVien[MAX_NHANVIEN];
    int soLuongNhanVien = 0;

    
    cout << "Nhap so luong nhan vien van phong: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        danhSachNhanVien[soLuongNhanVien] = new NhanVienVanPhong();
        danhSachNhanVien[soLuongNhanVien]->nhapThongTin();
        soLuongNhanVien++;
    }

    cout << "Nhap so luong nhan vien san xuat: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        danhSachNhanVien[soLuongNhanVien] = new NhanVienSanXuat();
        danhSachNhanVien[soLuongNhanVien]->nhapThongTin();
        soLuongNhanVien++;
    }

    
    double tongLuong = 0;
    for (int i = 0; i < soLuongNhanVien; ++i) {
        cout << "Thong tin nhan vien " << i + 1 << ":" << endl;
        double luong = danhSachNhanVien[i]->tinhLuong();
        danhSachNhanVien[i]->xuatThongTin();
        tongLuong += luong;
        cout << endl;
    }

  
    cout << "Tong luong phai tra cho tat ca nhan vien: " << tongLuong << endl;

   
    double luongCaoNhat = danhSachNhanVien[0]->getLuong();
    double luongThapNhat = danhSachNhanVien[0]->getLuong();
    for (int i = 1; i < soLuongNhanVien; ++i) {
        double luong = danhSachNhanVien[i]->getLuong();
        if (luong > luongCaoNhat)
            luongCaoNhat = luong;
        if (luong < luongThapNhat)
            luongThapNhat = luong;
    }
    cout << "Nhan vien co luong cao nhat: " << luongCaoNhat << endl;
    cout << "Nhan vien co luong thap nhat: " << luongThapNhat << endl;

    
    for (int i = 0; i < soLuongNhanVien; ++i) {
        delete danhSachNhanVien[i];
    }

    return 0;
}
