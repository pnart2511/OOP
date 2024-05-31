#include <iostream>
#include <string>
#include <vector>

using namespace std;


class BenhNhan {
private:
    string MaBenhNhan;
    string TenBenhNhan;
    int Tuoi;

public:
    
    BenhNhan(string maBenhNhan = "", string tenBenhNhan = "", int tuoi = 0) {
        MaBenhNhan = maBenhNhan;
        TenBenhNhan = tenBenhNhan;
        Tuoi = tuoi;
    }

  
    friend istream& operator>>(istream& is, BenhNhan& bn) {
        cout << "Nhap ma benh nhan: ";
        is >> bn.MaBenhNhan;
        cout << "Nhap ten benh nhan: ";
        is.ignore();
        getline(is, bn.TenBenhNhan);
        cout << "Nhap tuoi: ";
        is >> bn.Tuoi;
        return is;
    }

   
    friend ostream& operator<<(ostream& os, const BenhNhan& bn) {
        os << "Ma benh nhan: " << bn.MaBenhNhan << endl;
        os << "Ten benh nhan: " << bn.TenBenhNhan << endl;
        os << "Tuoi: " << bn.Tuoi << endl;
        return os;
    }

    
    int getTuoi() {
        return Tuoi;
    }

    // Setter cho Tuoi
    void setTuoi(int tuoi) {
        Tuoi = tuoi;
    }

    // Getter cho MaBenhNhan
    string getMaBenhNhan() {
        return MaBenhNhan;
    }
};

class Khoa {
private:
    string TenKhoa;
    vector<BenhNhan> DanhSachBenhNhan;

public:
    
    Khoa(string tenKhoa = "") {
        TenKhoa = tenKhoa;
    }

  
    void ThemBenhNhan(BenhNhan bn) {
        DanhSachBenhNhan.push_back(bn);
    }

 
    void InDanhSachBenhNhan() {
        cout << "\nDanh sach benh nhan cua khoa " << TenKhoa << ":\n";
        for (int i = 0; i < DanhSachBenhNhan.size(); i++) {
            cout << DanhSachBenhNhan[i] << endl;
        }
    }

 
    BenhNhan* TimBenhNhanTheoMa(string maBenhNhan) {
        for (int i = 0; i < DanhSachBenhNhan.size(); i++) {
            if (DanhSachBenhNhan[i].getMaBenhNhan() == maBenhNhan) {
                return &DanhSachBenhNhan[i];
            }
        }
      
        return 0; 
    }

   
    int DemBenhNhanLonHon30Tuoi() {
        int count = 0;
        for (int i = 0; i < DanhSachBenhNhan.size(); i++) {
            if (DanhSachBenhNhan[i].getTuoi() > 30) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    int n;
    cout << "Nhap so luong benh nhan: ";
    cin >> n;
    Khoa khoa("Khoa A");

    // Nh?p thông tin b?nh nhân
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin benh nhan thu " << i + 1 << endl;
        BenhNhan bn;
        cin >> bn;
        khoa.ThemBenhNhan(bn);
    }

   
    khoa.InDanhSachBenhNhan();

  
    cout << "\nSo luong benh nhan lon hon 30 tuoi: " << khoa.DemBenhNhanLonHon30Tuoi() << endl;

   
    BenhNhan* bn = khoa.TimBenhNhanTheoMa("BN01");
    if (bn != 0) {  
        bn->setTuoi(20);
        cout << "\nThong tin benh nhan co ma BN01 sau khi cap nhat:\n";
        cout << *bn << endl;
    }
    else {
        cout << "\nKhong tim thay benh nhan co ma BN01.\n";
    }

    return 0;
}
