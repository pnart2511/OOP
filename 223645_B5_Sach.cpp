#include <iostream>
#include<iomanip>
using namespace std;

class SACH {
	private:
	string nameSach , tenTacGia;
	int soTrang, giaBan;
	public:
		void Nhap(){
			cout<<"Nhap Ten Sach :"; cin.ignore(); getline(cin , nameSach);
			cout<<"Ten Tac Gia 	 :";  getline(cin,tenTacGia);
			cout<<"So Trang 	 :"; cin>>soTrang;
			cout<<"Gia Ban 		 :"; cin>>giaBan;
		}
		void Xuat(){
			cout<<"Ten Sach:"<<nameSach<<" - "<<"Ten tac gia:"<<tenTacGia<<" - "<<"So trang:"<<soTrang<<" - "<<"Gia ban:"<<giaBan<<endl;
		}
	
};

class BIA : public SACH{
	private:
		int MaHinhAnh;
		long tienVe;
	public:
		void Nhap(){
			cout<<"Nhap ma sach"; cin>>MaHinhAnh;
			cout<<"Tien Ve 		 :"; cin>>tienVe;
		
		
		}
		void Xuat(){
			cout<<"Thong Tin Bia Sach\n"<<endl;
			cout<<MaHinhAnh<<" - "<<tienVe<<endl;
		}
		
	
	
};
class HoaSy {
	private:
		string nameHoaSy , DiaChi ;
	public:
		void Nhap(){
			cout<<"Ten Hoa Sy :"; cin.ignore(); getline(cin , nameHoaSy);
			cout<<"Dia Chi 		 :"; cin>>DiaChi;
		}
		void Xuat(){
			cout<<"Thong Tin Hoa Sy\n";
			cout<<nameHoaSy<<" - "<<DiaChi<<endl;
		}
		
		
};

class SachVeBia:public HoaSy,public BIA {
	public:
		void Nhap(){
			SACH::Nhap();
			BIA::Nhap();
			HoaSy::Nhap();
		}
		void Xuat(){
			SACH::Xuat();
			BIA::Xuat();
			HoaSy::Xuat();
		}
		
};


int main()
{
	HoaSy *s;
	int n;
	cout<<"So Luong Sach Can Nhap:";
	cin>>n;
	s = new HoaSy[n];
	for(int i = 0 ; i < n ; i++)
	{
		cout <<"----------------["<<i+1<<"]--------------------"<<endl;
		s[i].Nhap();
	}
		cout<<"So Luong Sach Vua Nhap:\n";
		for(int i = 0 ; i < n ; i++)
	{
		cout <<"----------------["<<i+1<<"]--------------------"<<endl;
		s[i].Xuat();
	}
	
}
