#include <iostream>
#include<iomanip>
using namespace std;


class SanPham{
	private:
	 	string MaSanPham , TenSanPham;
	 	long DonGia;
	public:
		void Nhap(){
			cout<<"Ma San Pham : ";cin.ignore();
			 getline(cin , MaSanPham);
		
			cout<<"Ten San Pham : "; getline(cin , TenSanPham);
			
			cout<<"Don Gia : "; cin>>DonGia;
			
		}
		void Xuat(){
			cout<<setw(10)<<left<<MaSanPham<<setw(25)<<left<<TenSanPham<<setw(10)<<right<<DonGia<<endl;
			
			
		}
		long layDonGia()
		{
			return DonGia;
		}
};
class HoaDon{
	private:
	string MaHoaDon;
	SanPham *SP ;
	int TongSanPham ;
	long TongTien;
	public:
		void Nhap(){
			cout<<"Ma Hoa Don:    " ; getline(cin , MaHoaDon );
			cout<<"Tong San Pham"<<endl ; cin>>TongSanPham;
			//nhap danh sach san pham dua vao TongSanPham		
			SP = new SanPham[TongSanPham];
			for(int i = 0 ; i < TongSanPham ; i ++)
			{
				cout<<"San Pham Thu  - "<<" "<<i + 1 << endl;
				SP[i].Nhap();
				TongTien += SP[i].layDonGia();
			}
			//tinh tong tien sau khi nhap
		
	}
		void Xuat()
		{
		
			cout<<"Ma Hoa Don :  "<<MaHoaDon<<endl;
			cout<<"Tong So San Pham: "<<TongSanPham<<endl;
			cout<<"Tong Tien  :"<<TongTien<<endl;
			cout<<"Danh Sach San Pham: "<<endl;
			cout<<setw(10)<<left<<"Ma SP"<<setw(25)<<left<<"Ten San Pham"<<setw(10)<<right<<"Don Gia"<<endl;
			for(int i = 0 ; i < TongSanPham; i ++)
			{
				SP[i].Xuat();
			}
					
		}
};


int main()
{
HoaDon hd;
hd.Nhap();
hd.Xuat();
	return 0 ;
}
