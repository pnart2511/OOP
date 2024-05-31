#include <iostream>
#include <string>

using namespace std;


class NhanVien {
private:
    string MaNhanVien;
    string HoVaTen;
    int Tuoi;

public:
 
    NhanVien(string maNhanVien = "", string hoVaTen = "", int tuoi = 0) {
        MaNhanVien = maNhanVien;
        HoVaTen = hoVaTen;
        Tuoi = tuoi;
    }

  
    bool VeHuu() {
        return Tuoi >= 60;
    }

    
    friend istream& operator>>(istream& is, NhanVien& nv) {
        cout << "Nhap ma nhan vien: ";
        is >> nv.MaNhanVien;
        cout << "Nhap ho va ten: ";
        is.ignore();
        getline(is, nv.HoVaTen);
        cout << "Nhap tuoi: ";
        is >> nv.Tuoi;
        return is;
    }

   
    friend ostream& operator<<(ostream& os, const NhanVien& nv) {
        os << "Ma nhan vien: " << nv.MaNhanVien << endl;
        os << "Ho va ten: " << nv.HoVaTen << endl;
        os << "Tuoi: " << nv.Tuoi << endl;
        return os;
    }
};


class CanBo : public NhanVien {
private:
    double HeSoLuong;
    double PhuCap;
    string TrinhDo;

public:
   
    CanBo(string maNhanVien = "", string hoVaTen = "", int tuoi = 0, double heSoLuong = 0, double phuCap = 0, string trinhDo = "")
        : NhanVien(maNhanVien, hoVaTen, tuoi), HeSoLuong(heSoLuong), PhuCap(phuCap), TrinhDo(trinhDo) {}

  
    friend istream& operator>>(istream& is, CanBo& cb) {
        is >> (NhanVien&)cb;
        cout << "Nhap he so luong: ";
        is >> cb.HeSoLuong;
        cout << "Nhap phu cap: ";
        is >> cb.PhuCap;
        cout << "Nhap trinh do: ";
        is.ignore();
        getline(is, cb.TrinhDo);
        return is;
    }

  
    friend ostream& operator<<(ostream& os, const CanBo& cb) {
        os << (NhanVien&)cb;
        os << "He so luong: " << cb.HeSoLuong << endl;
        os << "Phu cap: " << cb.PhuCap << endl;
        os << "Trinh do: " << cb.TrinhDo << endl;
        return os;
    }

   
    double TinhLuong() {
        if (VeHuu()) {
            return 0.7 * (HeSoLuong * 1800000 + PhuCap);
        }
        else {
            return HeSoLuong * 1800000 + PhuCap;
        }
    }

   
    double getHeSoLuong() const { 
        return HeSoLuong; 
    }
};

int main() {
    int n;
    cout << "Nhap so luong can bo: ";
    cin >> n;
    CanBo* dsCanBo = new CanBo[n];

   
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin can bo thu " << i + 1 << endl;
        cin >> dsCanBo[i];
    }

    
    cout << "\nThong tin cac can bo:\n";
    for (int i = 0; i < n; i++) {
        cout << dsCanBo[i];
        cout << "Luong: " << dsCanBo[i].TinhLuong() << endl;
    }

   
    cout << "\nDanh sach can bo chua ve huu va co he so luong lon hon 7.0:\n";
    for (int i = 0; i < n; i++) {
       
        if (!dsCanBo[i].VeHuu() && dsCanBo[i].getHeSoLuong() > 7.0) {
            cout << dsCanBo[i];
        }
    }

    delete[] dsCanBo;
    return 0;
}
