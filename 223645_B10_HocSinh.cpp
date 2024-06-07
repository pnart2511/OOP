#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class HocSinh {
private:
  string maSo;
  string hoTen;
  float diemToan;
  float diemVan;
  
  

public:
  void Nhap() {
    while (true) {
      try {
        cout << "Nhap ma so (6 ky tu): ";
        cin >> maSo;
        if (maSo.length() != 6) {
          throw length_error("Ma so phai co 6 ky tu!");
        }
        break;
      }
      catch (length_error& e) {
        cout << e.what() << endl;
      }
    }

    cout << "Nhap ho ten: ";
    cin.ignore();
    getline(cin, hoTen);

    while (true) {
      try {
        cout << "Nhap diem toan: ";
        cin >> diemToan;
        if (diemToan < 0 || diemToan > 10) {
          throw out_of_range("Diem so phai tu 0 den 10!");
        }
        break;
      }
      catch (out_of_range& e) {
        cout << e.what() << endl;
      }
    }

    while (true) {
      try {
        cout << "Nhap diem van: ";
        cin >> diemVan;
        if (diemVan < 0 || diemVan > 10) {
          throw out_of_range("Diem so phai tu 0 den 10!");
        }
        break;
      }
      catch (out_of_range& e) {
        cout << e.what() << endl;
      }
    }
  }

  void Xuat() {
    cout << "Ma so: " << maSo << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Diem toan: " << diemToan << endl;
    cout << "Diem van: " << diemVan << endl;
    cout << "Diem trung binh: " << (diemToan + diemVan) / 2 << endl;
  }
};

int main() {
  try {
    HocSinh hs;
    hs.Nhap();
    hs.Xuat();
  }
  catch (length_error& e) {
    cout << e.what() << endl;
  }
  catch (out_of_range& e) {
    cout << e.what() << endl;
  }
  catch (logic_error& e) {
    cout << e.what() << endl;
  }
  catch (...) {
    cout << "Loi chuong trinh!" << endl;
  }
  return 0;
}
