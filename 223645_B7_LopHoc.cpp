#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_SINHVIEN = 100; // Maximum number of students


class SinhVien {
private:
    string MaSV;
    string HoTen;
    int KhoaHoc;
public:

    SinhVien(string maSV = "", string hoTen = "", int khoaHoc = 0) {
        MaSV = maSV;
        HoTen = hoTen;
        KhoaHoc = khoaHoc;
    }

    // Toán t? nh?p >>
    friend istream& operator>>(istream& is, SinhVien& sv) {
        cout << "Nhap MaSV: "; is >> sv.MaSV;
        cout << "Nhap HoTen: "; is >> sv.HoTen;
        cout << "Nhap KhoaHoc: "; is >> sv.KhoaHoc;
        return is;
    }

  
    friend ostream& operator<<(ostream& os, const SinhVien& sv) {
        os << "MaSV: " << sv.MaSV << ", HoTen: " << sv.HoTen
           << ", KhoaHoc: " << sv.KhoaHoc << endl;
        return os;
    }

    // Getter cho KhoaHoc
    int getKhoaHoc() const {
        return KhoaHoc;
    }
};


class LopHoc {
private:
    string MaLop;
    string TenLop;
    SinhVien DanhSachSV[MAX_SINHVIEN]; // Array to store students
    int SoLuongSV; // Number of students
public:
    
    LopHoc(string maLop = "", string tenLop = "") {
        MaLop = maLop;
        TenLop = tenLop;
        SoLuongSV = 0; // Initialize number of students to 0
    }

    friend istream& operator>>(istream& is, LopHoc& lop) {
        cout << "Nhap MaLop: "; is >> lop.MaLop;
        cout << "Nhap TenLop: "; is >> lop.TenLop;
        cout << "Nhap so luong sinh vien: ";
        is >> lop.SoLuongSV; // Read number of students
        for (int i = 0; i < lop.SoLuongSV; i++) {
            cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
            is >> lop.DanhSachSV[i];
        }
        return is;
    }

  
    friend ostream& operator<<(ostream& os, const LopHoc& lop) {
        os << "MaLop: " << lop.MaLop << ", TenLop: " << lop.TenLop << endl;
        os << "Danh sach sinh vien:" << endl;
        for (int i = 0; i < lop.SoLuongSV; i++) {
            os << lop.DanhSachSV[i];
        }
        return os;
    }

    // Hàm d?m s? sinh viên khóa 22
    int demSinhVienKhoa22() {
        int count = 0;
        for (int i = 0; i < SoLuongSV; i++) {
            if (DanhSachSV[i].getKhoaHoc() == 22) {
                count++;
            }
        }
        return count;
    }

   
void sapXepDanhSach() {
    for (int i = 0; i < SoLuongSV - 1; ++i) {
        for (int j = 0; j < SoLuongSV - i - 1; ++j) {
            if (DanhSachSV[j].getKhoaHoc() > DanhSachSV[j + 1].getKhoaHoc()) {
                // Swap the elements
                SinhVien temp = DanhSachSV[j];
                DanhSachSV[j] = DanhSachSV[j + 1];
                DanhSachSV[j + 1] = temp;
            }
        }
    }
}


};

int main() {
    LopHoc lopHoc;
    cout << "Nhap thong tin lop hoc:" << endl;
    cin >> lopHoc;

    cout << "\nThong tin lop hoc vua nhap:" << endl;
    cout << lopHoc;

    cout << "\nSo luong sinh vien khoa 22: " << lopHoc.demSinhVienKhoa22() << endl;

    lopHoc.sapXepDanhSach();

    cout << "\nDanh sach sinh vien sau khi sap xep:" << endl;
    cout << lopHoc;

    return 0;
}

