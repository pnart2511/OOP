#include <iostream>
#include <string>

using namespace std;

class ThiSinh {
private:
    string SBD, HoTen, DiaChi;
    float DiemUT;

public:
    ThiSinh() {}

    ThiSinh(string sbd, string ht, string dc, float dUT) {
        SBD = sbd;
        HoTen = ht;
        DiaChi = dc;
        DiemUT = dUT;
    }

    ~ThiSinh() {}

    void Nhap(istream& is) {
        cout << "So Bao Danh: "; 
        getline(is, SBD); 
        cout << "Ho Ten: "; 
        getline(is, HoTen);
        cout << "Dia Chi: "; 
        getline(is, DiaChi);
        cout << "Diem Uu Tien: "; 
        is >> DiemUT;
    }

    friend istream& operator>>(istream& is, ThiSinh& ts) {
        ts.Nhap(is);
        return is;
    }

    void Xuat(ostream& os) {
        os << "SBD: " << SBD << endl;
        os << "Ho Ten: " << HoTen << endl;
        os << "Dia Chi: " << DiaChi << endl;
        os << "Diem Uu Tien: " << DiemUT << endl;
    }

    friend ostream& operator<<(ostream& os, ThiSinh& ts) {
        ts.Xuat(os);
        return os;
    }

    float LayDiemUT() {
        return DiemUT;
    }
};

class ThiSinhKhoiA : public ThiSinh {
private:
    float Toan, Ly, Hoa;

public:
    ThiSinhKhoiA() {}

    ThiSinhKhoiA(string sbd, string ht, string dc, float dUT, float t, float l, float h) : ThiSinh(sbd, ht, dc, dUT) {
        Toan = t;
        Ly = l;
        Hoa = h;
    }

    ~ThiSinhKhoiA() {}

    float DiemTrungBinh() {
        return Toan + Ly + Hoa + LayDiemUT();
    }

    friend bool operator>(ThiSinhKhoiA t1, ThiSinhKhoiA t2) {
        return t1.DiemTrungBinh() > t2.DiemTrungBinh();
    }

    friend istream& operator>>(istream& is, ThiSinhKhoiA& ts) {
        ts.Nhap(is);
        cout << "Diem Toan: "; is >> ts.Toan;
        cout << "Diem Ly: "; is >> ts.Ly;
        cout << "Diem Hoa: "; is >> ts.Hoa;
        return is;
    }

    friend ostream& operator<<(ostream& os, ThiSinhKhoiA& ts) {
        ts.Xuat(os); 
        os << "Diem Toan: " << ts.Toan << endl;
        os << "Diem Ly: " << ts.Ly << endl;
        os << "Diem Hoa: " << ts.Hoa << endl;
        return os;
    }
};

int main() {
    ThiSinhKhoiA ts;
    cin >> ts;
    cout << ts;
    return 0;
}
