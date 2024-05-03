#include <iostream>
#include<iomanip>
using namespace std;

class VienChuc{
	private:
		string hoVaTen,NgaySinh,DiaChi,DienThoai,NgayKyHopDong;
	public:
		void Nhap(){
			cout<<"Nhap Ho Ten  : "; cin.ignore(); getline(cin , hoVaTen);
			cout<<"Nhap Ngay Sinh  : "; cin.ignore(); getline(cin , NgaySinh);
			cout<<"Nhap Dia Chi  : "; cin.ignore(); getline(cin , DiaChi);
			cout<<"Nhap Dien Thoai  : "; cin.ignore(); getline(cin , DienThoai);
			cout<<"Nhap NgayKyHopDong  : "; cin.ignore(); getline(cin , NgayKyHopDong);
			
			
		}
		void Xuat(){
			cout<<"Ho Ten: "<<hoVaTen<<"\nNgaySinh : "<<NgaySinh<<"\nDia Chi: "<<DiaChi<<"\nDien Thoai: "<<DienThoai<<"\nNgay Ky Hop Dong : "<<NgayKyHopDong<<endl;
		}
		double TinhLuong();	
};
class GiaoVien: public VienChuc{
	private:
		int SoTietDay;
		long TienDayMotTiet;
	public:
			void Nhap()
			{
				VienChuc::Nhap();
				cout<<"\nSo Tiet Day "; cin>>SoTietDay;
				cout<<"\nTienDayMotTiet "; cin>>TienDayMotTiet;
			}
			void Xuat(){
					VienChuc::Xuat();
					cout<<"\nSo Tiet Day : "<<SoTietDay<<"\nTien Day Mot Tien :  "<<TienDayMotTiet;
					cout<<fixed<<setprecision(0)<<"\nLuong: "<<TinhLuong()<<"VND"<<endl;
			}
			double TinhLuong(){
				return SoTietDay * TienDayMotTiet;
			}
			
		
};
class NhanVienHopDong: public VienChuc{
	private:
		int soNgayCong;
		long tienCongNgay;
	public:
			void Nhap()
			{
				VienChuc::Nhap();
				cout<<"\nsoNgayCong "; cin>>soNgayCong;
				cout<<"\ntienCongNgay "; cin>>tienCongNgay;
			}
			void Xuat(){
					VienChuc::Xuat();
					cout<<"\nSo Ngay Cong"<<soNgayCong<<"\nTien Cong Day"<<tienCongNgay;
					cout<<fixed<<setprecision(0)<<"\nLuong: "<<TinhLuong()<<"VND"<<endl;
			}
			double TinhLuong()
			{
				return soNgayCong * tienCongNgay;
			}
		
};

int main()
{
	char gocTT = 218;
	char gocTD = 192;
	char gocPT = 191;
	char gocPD = 217;
	char duongTD = 196;
	char duongTP = 179;	
	int chon; 
	do{
		cout<<"\n";
		cout<<gocTT<<setw(40)<<setfill(duongTD)<<gocPT<<endl;
		cout<<duongTP<<"1.Nhap Va Xuat Giao Vien		"<<duongTP<<endl;
		cout<<duongTP<<"2.Nhap Va Xuat NVHD    		"<<duongTP<<endl;
		cout<<duongTP<<"0.Thoat Chuong Trinh   		"<<duongTP<<endl;
		cout<<gocTD<<setw(40)<<setfill(duongTD)<<gocPD<<endl;
		cout<<"Ban Chon Muc: "; cin>>chon;
		switch(chon){
			case 1:{
				GiaoVien s;
				s.Nhap();
				s.Xuat();
				s.TinhLuong();
				break;
			}
			case 2:{
				NhanVienHopDong cd;
				cd.Nhap();
				cd.Xuat();
				cd.TinhLuong();
				break;
			}
		}
	}while(chon!=0);
	return 0;
}
