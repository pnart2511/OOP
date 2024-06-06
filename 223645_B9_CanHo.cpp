#include<iostream>
using namespace std;

class CanHo{
    private:
        string diaChi;
        long TienCoc , TienThue;
        bool TinhTrang;
    public:
        virtual void Nhap();
        virtual void Xuat();
        virtual long LayTienThue();
        virtual bool LayTinhTrang();
};

void CanHo::Nhap(){
    cout << "Nhap dia chi: ";
    cin >> diaChi;
    cout << "Nhap tien coc: ";
    cin >> TienCoc;
    cout << "Nhap tien thue: ";
    cin >> TienThue;
    cout << "Nhap tinh trang (1 - Con trong, 0 - Da cho thue): ";
    cin >> TinhTrang;
}

void CanHo::Xuat(){
    cout << "Dia chi: " << diaChi << endl;
    cout << "Tien coc: " << TienCoc << endl;
    cout << "Tien thue: " << TienThue << endl;
    cout << "Tinh trang: " << (TinhTrang ? "Con trong" : "Da cho thue") << endl;
}

long CanHo::LayTienThue(){
    return (TinhTrang ? TienThue : 0);
}

bool CanHo::LayTinhTrang(){
    return TinhTrang;
}

class CanHoChungCu:public CanHo{
    private:
        int ThuTuTang;
    public:
        virtual void Nhap();
        virtual void Xuat();    
};

class CanHoThuong :public CanHo{
    private:
        int soLuongTang;
    public:
        virtual void Nhap();
        virtual void Xuat();    
};

void CanHoChungCu::Nhap(){
    CanHo::Nhap();
    cout << "Nhap thu tu tang: ";
    cin >> ThuTuTang;
}

void CanHoChungCu::Xuat(){
    CanHo::Xuat();
    cout << "Thu tu tang: " << ThuTuTang << endl;
}

void CanHoThuong::Nhap(){
    CanHo::Nhap();
    cout << "Nhap so luong tang: ";
    cin >> soLuongTang;
}

void CanHoThuong::Xuat(){
    CanHo::Xuat();
    cout << "So luong tang: " << soLuongTang << endl;
}

int main(){
    CanHo **ch;
    int n, chon;
    long tongTienThue = 0; 
    int chungCuTrong = 0 ; 
    int chungCuChoThue = 0;
    int CanHoTrong = 0 , CanHoChoThue = 0;
    cout<<"So luong can ho: "; cin>>n;
    ch = new CanHo*[n];
    for(int i = 0; i < n; i++){
        do{
            cout<<"Chung cu (1) hay can ho thuong (2): ";
            cin>>chon;
        }
        while(chon != 1 && chon != 2);
        
        if(chon == 1){
            ch[i] = new CanHoChungCu;
            ch[i]->Nhap();
            if(ch[i]->LayTinhTrang())
                chungCuChoThue++;
            else
                chungCuTrong++;
        }
        else{
            ch[i] = new CanHoThuong;
            ch[i]->Nhap();
            if(ch[i]->LayTinhTrang())
                CanHoChoThue++;
            else
                CanHoTrong++;
        }
        
       
        tongTienThue += ch[i]->LayTienThue(); 
    }
    
    cout<<endl<<"Danh sach vua nhap : "<<endl;
    for(int i = 0; i < n; i++){
        ch[i]->Xuat();
        cout << endl;
    }

    cout << "Tong tien thue phong cua cac can ho dang cho thue: " << tongTienThue << endl;

    cout << "So luong can ho chung cu con trong: " << chungCuTrong << endl;
    cout << "So luong can ho chung cu dang cho thue: " << chungCuChoThue << endl;
    cout << "So luong can ho thuong con trong: " << CanHoTrong << endl;
    cout << "So luong can ho thuong dang cho thue: " << CanHoChoThue << endl;

    for(int i = 0; i < n; i++){
        delete ch[i];
    }
    delete [] ch;

    return 0;
}

