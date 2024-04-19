#include <iostream>
using namespace std;

class Date{
	private:
		 int Ngay , Thang , Nam;
	public:
		void Nhap(){
			cout<<"Nhap Ngay:";
			cin>>Ngay;
			cout<<"Nhap Thang:";
			cin>>Thang;
			cout<<"Nhap Nam:";
			cin>>Nam;
			
		}
		void Xuat()
		
		{
			cout<<Ngay<<"/"<<Thang<<"/"<<Nam<<endl;
		}
	
};

class SinhVien{
	private:
		string MaSinhVien , HoTen , Lop;
		Date NgaySinh;
	public:
		void Nhap(){
			cout<<"Ma Sinh Vien: "; getline(cin,MaSinhVien);
			cout<<"Ho Ten: "; getline(cin,HoTen);
			cout<<"Lop: "; getline(cin,Lop);
			cout<<"Ngay Sinh  "<<endl;NgaySinh.Nhap();
		}
		void Xuat(){
			cout<<"Ma Sinh Vien: "<<MaSinhVien<<endl;
			cout<<"Ho Ten: "<<HoTen<<endl;
			cout<<"Lop: "<<Lop<<endl;
			cout<<"Ngay Sinh : ";NgaySinh.Xuat();
		}
		
};



int main()
{
	SinhVien sv;
	sv.Nhap();
	sv.Xuat();
	
	
	
	
	
	
	return 0 ;
}
