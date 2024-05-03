#include <iostream>
#include<iomanip>
using namespace std;

class AnPham{
	private:
		string tenAnPham,NgayPhatHanh;
		long giaTien;
	public:
		void Nhap(){
			cout<<"Nhap Ten An Pham:  " ; cin.ignore(); 
			 getline(cin , tenAnPham);
			cout<<"Ngay Phat Hanh : "; getline(cin,NgayPhatHanh);
			cout<<"Gia Tien : " ; cin>>giaTien;
		}
		void Xuat(){
			cout<<"</>-----------------------------------</>";
			cout<<"\nTen An Pham : "<<tenAnPham<<"\nNgay Phat Hanh: "<<NgayPhatHanh<<"\nGia Tien: "<<giaTien<<endl;
		}
};
class Sach: public AnPham{
	private:
		int SoTrang;
	public:
		void Nhap(){
			AnPham::Nhap();
			cout<<"So Trang :"; cin>>SoTrang;
		}
		void Xuat(){
			AnPham::Xuat();
			cout<<"\nSo Trang: "<<SoTrang<<endl;
		}
};
class DiaCD : public AnPham{
	private:
		int SoLuongTapTin;
		float DungLuong;
	public:
		void Nhap()
		{
			AnPham::Nhap();
			cout<<"So Luong Tap Tin : "; cin>>SoLuongTapTin;
			cout<<"Dung Luong :  "; cin>>DungLuong;
		}
		void Xuat()
		{
			AnPham::Xuat();
			cout<<"\nSo Luong Tap Tin: "<<SoLuongTapTin<<"\nDung Luong: "<<DungLuong<<"MB"<<endl;
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
		cout<<gocTT<<setw(25)<<setfill(duongTD)<<gocPT<<endl;
		cout<<duongTP<<"1.Nhap Va Xuat Sach     "<<duongTP<<endl;
		cout<<duongTP<<"2.Nhap Va Xuat DiaCD    "<<duongTP<<endl;
		cout<<duongTP<<"0.Thoat Chuong Trinh    "<<duongTP<<endl;
		cout<<gocTD<<setw(25)<<setfill(duongTD)<<gocPD<<endl;
		cout<<"Ban Chon Muc: "; cin>>chon;
		switch(chon){
			case 1:{
				Sach s;
				s.Nhap();
				s.Xuat();
				break;
			}
			case 2:{
				DiaCD cd;
				cd.Nhap();
				cd.Xuat();
				break;
			}
		}
	}while(chon!=0);
	
	return 0;
}
