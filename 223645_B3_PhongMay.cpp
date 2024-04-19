#include <iostream>
#include<iomanip>
using namespace std;

class NhanVien{
	private: 
		string MaNhanVien , HoTen, DienThoai;
	public:
		void Nhap(){
			cout<<"Nhap Ma Nhan Vien : " ; cin.ignore(); getline(cin , MaNhanVien);
			cout<<"Ho Ten :"; getline(cin , HoTen);
			cout<<"Dien Thoai :" ; cin>>DienThoai;
		}
		void Xuat(){
			cout<<MaNhanVien<<"-"<<HoTen<<"-"<<DienThoai<<endl;
		}
};
class MayTinh{
	private: 
		string MaMay , TinhTrang;
		
		
		int SoThuTu;
	public:
		void Nhap(){
			cout<<"Ma May 	  : "; cin.ignore() ; getline(cin , MaMay);
			cout<<"Tinh Trang : " ; getline(cin , TinhTrang);
			cout<<"So Thu Tu  : "; cin>>SoThuTu;
		}
		void Xuat(){
				cout<<setw(10)<<left<<MaMay<<setw(10)<<left<<SoThuTu<<setw(20)<<right<<TinhTrang<<endl;
		}
};
class PhongMay{
	private:
		string MaPhongMay;
		MayTinh *MT;
		int TongSoMayTinh;
		NhanVien QuanLy;
	public:
	void Nhap(){
		cout<<"Ma Phong May : " ;getline(cin , MaPhongMay);
		cout<<"Tong So May Tinh : ";cin>>TongSoMayTinh;
		MT = new MayTinh[TongSoMayTinh];
		for(int i = 0 ; i<TongSoMayTinh ; i ++ )
		{
			cout<<"May Tinh Thu " <<" "<<i + 1<<endl;
			MT[i].Nhap();
		}
		cout<<"Nhap Nhan vien quan ly"<<endl;
		QuanLy.Nhap();
	}
		void Xuat(){
			cout<<"Ma Phong May : " <<MaPhongMay<<endl;
			cout<<"Tong So May  : " <<TongSoMayTinh<<endl;
			cout<<"Quan ly      :";QuanLy.Xuat();
			cout<<"Danh Sach May Tinh : "<<endl;
			cout<<setw(10)<<left<<"Ma May"<<setw(10)<<left<<"So Thu Tu"<<setw(20)<<right<<"Tinh Trang"<<endl;
			for(int i = 0 ; i<TongSoMayTinh ; i ++)
			{
				MT[i].Xuat();
			}
		}
};

int main(){
	PhongMay PM;
	PM.Nhap();
	PM.Xuat();
	return 0;
}


