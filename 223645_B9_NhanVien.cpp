#include <iostream>
#include <string>
using namespace std;

class nhanvien {
protected:
    string hoten, ngaysinh;
    int luong;  
public:
    virtual void Nhap() {
        cin.ignore();
        cout << "Ho va ten: "; getline(cin, hoten);
        cout << "Ngay sinh: "; getline(cin, ngaysinh);
    }
    virtual void Xuat() {
        cout << hoten << " " << ngaysinh << " " << luong;
    }
    virtual void tinhluong() = 0;
    int getLuong() {
        return luong;
    }
};

class nvvanphong : public nhanvien {
private:
    int songaylamviec;
public:
    void Nhap() {
        nhanvien::Nhap();
        cout << "So ngay lam viec: "; cin >> songaylamviec;
    }
    void Xuat()  {
        nhanvien::Xuat();
        cout << " " << songaylamviec << endl;
    }
    void tinhluong()  {
        luong = songaylamviec * 100000;
    }
};

class nvsanxuat : public nhanvien {
private:
    int sosanpham;
    int luongcanban;
public:
    void Nhap()  {
        nhanvien::Nhap();
        cout << "So san pham: "; cin >> sosanpham;
        cout << "Luong can ban: "; cin >> luongcanban;
    }
    void Xuat()  {
        nhanvien::Xuat();
        cout << " " << sosanpham << " " << luongcanban << endl;
    }
    void tinhluong()  {
        luong = luongcanban + sosanpham * 5000;
    }
};

int main() {
    nhanvien **nv;
    int n, chon;

    cout << "So luong nhan vien: "; cin >> n;

    nv = new nhanvien*[n];

 
    for (int i = 0; i < n; i++) {
        do {
            cout << "Nhan vien van phong(1) hay san xuat(2): "; cin >> chon;
        } while (chon != 1 && chon != 2);

        if (chon == 1) {
            nv[i] = new nvvanphong();
        } else {
            nv[i] = new nvsanxuat();
        }
        nv[i]->Nhap();
        nv[i]->tinhluong();
    }

    
    cout << "Thong tin nhan vien:" << endl;
    for (int i = 0; i < n; i++) {
        nv[i]->Xuat();
    }

    
    int tongLuong = 0;
    for (int i = 0; i < n; i++) {
        tongLuong += nv[i]->getLuong();
    }
    cout << "Tong luong: " << tongLuong << endl;

   
    int maxLuong = nv[0]->getLuong();
    int minLuong = nv[0]->getLuong();
    int maxIndex = 0, minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (nv[i]->getLuong() > maxLuong) {
            maxLuong = nv[i]->getLuong();
            maxIndex = i;
        }
        if (nv[i]->getLuong() < minLuong) {
            minLuong = nv[i]->getLuong();
            minIndex = i;
        }
    }
    cout << "Nhan vien co luong cao nhat: ";
    nv[maxIndex]->Xuat();
    cout << "Nhan vien co luong thap nhat: ";
    nv[minIndex]->Xuat();

   
    for (int i = 0; i < n; i++) {
        delete nv[i];
    }
    delete[] nv;

    return 0;
}
