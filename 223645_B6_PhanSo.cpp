#include <iostream>
#include <algorithm> // N�n include <numeric> cho __gcd
using namespace std;

class PhanSo {
private:
    int tuSo, mauSo;
public:

    PhanSo(int t = 0, int m = 1) {
        tuSo = t;
        mauSo = (m == 0) ? 1 : m; // S? d?ng to�n t? di?u ki?n cho g?n
    }

    // N?p ch?ng to�n t? +, -, *, / n�n tr? v? const PhanSo
    // d? tr�nh l?i khi g�n k?t qu? cho m?t d?i tu?ng const
    friend const PhanSo operator+(const PhanSo& ps1, const PhanSo& ps2) {
        PhanSo kq;
        kq.tuSo = ps1.tuSo * ps2.mauSo + ps1.mauSo * ps2.tuSo;
        kq.mauSo = ps1.mauSo * ps2.mauSo;
        kq.ToiGian(); // T?i gi?n ngay k?t qu?
        return kq;
    }

    friend const PhanSo operator-(const PhanSo& ps1, const PhanSo& ps2) {
        PhanSo ketQua;
        ketQua.tuSo = ps1.tuSo * ps2.mauSo - ps1.mauSo * ps2.tuSo;
        ketQua.mauSo = ps1.mauSo * ps2.mauSo;
        ketQua.ToiGian(); // T?i gi?n ngay k?t qu?
        return ketQua;
    }

    friend const PhanSo operator*(const PhanSo& ps1, const PhanSo& ps2) {
        PhanSo ketQua;
        ketQua.tuSo = ps1.tuSo * ps2.tuSo;
        ketQua.mauSo = ps1.mauSo * ps2.mauSo;
        ketQua.ToiGian(); // T?i gi?n ngay k?t qu?
        return ketQua;
    }

    friend const PhanSo operator/(const PhanSo& ps1, const PhanSo& ps2) {
        PhanSo ketQua;
        ketQua.tuSo = ps1.tuSo * ps2.mauSo;
        ketQua.mauSo = ps1.mauSo * ps2.tuSo;
        ketQua.ToiGian(); // T?i gi?n ngay k?t qu?
        return ketQua;
    }

    friend istream& operator>>(istream& input, PhanSo& ps) {
        cout << "Nhap Tu So : ";
        input >> ps.tuSo;
        cout << "Nhap Mau So : ";
        input >> ps.mauSo;
        while (ps.mauSo == 0) {
            cout << "Nhap Lai Mau So Khac 0 :";
            input >> ps.mauSo;
        }
        return input;
    }

    friend ostream& operator<<(ostream& output, const PhanSo& ps) { 
        output <<ps.tuSo<<"/"<<ps.mauSo<< endl;
        return output;
    }

    void ToiGian() {
        int UCLN = __gcd(tuSo, mauSo);
        tuSo /= UCLN;
        mauSo /= UCLN;
        if (mauSo < 0) {
            mauSo = -mauSo, tuSo = -tuSo;
        }
        if (tuSo == 0) {
            mauSo = 1;
        }
    }

    // H�m GiaTri() n�n khai b�o l� const v� kh�ng thay d?i gi� tr?
    float GiaTri() const {
        return (float)tuSo / mauSo; 
    }

    // N�n khai b�o c�c to�n t? so s�nh l� const 
    friend bool operator==(const PhanSo& ps1, const PhanSo& ps2) {
        return ps1.GiaTri() == ps2.GiaTri();
    }

    friend bool operator!=(const PhanSo& ps1, const PhanSo& ps2) {
        return ps1.GiaTri() != ps2.GiaTri();
    }

    friend bool operator>(const PhanSo& ps1, const PhanSo& ps2) {
        return ps1.GiaTri() > ps2.GiaTri();
    }
 	friend bool operator<(const PhanSo& ps1, const PhanSo& ps2) {
        return ps1.GiaTri() < ps2.GiaTri();
    }
    friend bool operator>=(const PhanSo& ps1, const PhanSo& ps2) {
        return ps1.GiaTri() >= ps2.GiaTri();
    }

    friend bool operator<=(const PhanSo& ps1, const PhanSo& ps2) {
        return ps1.GiaTri() <= ps2.GiaTri();
    }
};

int main() {
    PhanSo p1, p2, p3;
    cin >> p1;
    cin >> p2;
    p3 = p1 + p2;
    cout << p1 << "  +  " <<p2<< "  =  " << p3 << endl;
    p3 = p1 - p2;
    cout << p1 << "  -  " <<p2<< "  =  " << p3 << endl;
    p3 = p1 * p2;
    cout << p1 << "  *  " <<p2<< "  =  " << p3 << endl;
    p3 = p1 / p2;
    cout << p1 << "  /  " <<p2<< "  =  " << p3 << endl;
 if (p1 == p2) { // S?a to�n t? g�n = th�nh to�n t? so s�nh ==
        cout << p1 << "==" << p2 << endl;
    } else if(p1 != p2) {
        cout << p1 << "!=" << p2 << endl;
    } 
    else if(p1 >= p2) {
        cout << p1 << ">=" << p2 << endl;
    } 
      else if(p1 <= p2) {
        cout << p1 << "<=" << p2 << endl;
    }
     else if(p1 < p2) {
        cout << p1 << "<" << p2 << endl;
    }
    else if(p1 > p2) {
        cout << p1 << ">" << p2 << endl;
    }
    return 0;
}
