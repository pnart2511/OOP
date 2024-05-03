#include <iostream>
#include<iomanip>
 using namespace std;
 
 
 class NhanVien{
 	private:
 		string MaNhanVien , HoVaTen, NgaySinh,DiaChi;
 	public:
 		void Nhap(){
 			cout<<"Ma Nhan Vien: "; cin>>MaNhanVien;
 			cout<<"Ho Va Ten   : "; cin.ignore(); getline(cin , HoVaTen);
 			cout<<"Dia Chi : "; cin.ignore(); getline(cin , DiaChi);
 			cout<<"Ngay Sinh : "; cin.ignore(); getline(cin , NgaySinh);
		 }
 		void Xuat(){
 			cout<<"MNV : "<<MaNhanVien<<"\nHo Va Ten: "<<HoVaTen<<"\nDia Chi: "<<DiaChi<<"\nNgay Sinh : "<<NgaySinh<<endl;
		 }
 		double TinhLuong(){
 			return 0;
		 }
 	
 };
 class NVSanXuat : public NhanVien{
 	private:
 		int SoSanPham , DonGiaSanPham;
 	public:
 		void Nhap()
 		{
 			NhanVien::Nhap();
 			cout<<"\nSo San Pham : "; cin>>SoSanPham;
 			cout<<"\nDon gia san pham : "; cin>>DonGiaSanPham;
 			
 			
		 }
 		void Xuat()
 		{
 			NhanVien::Xuat();
 			cout<<"\nSo San Pham:"<<SoSanPham<<"\nDon Gia San Pham: "<<DonGiaSanPham<<endl;
			cout<<fixed<<setprecision(0)<<"\nLuong: "<<TinhLuong()<<"VND"<<endl;
		 }
		 
		 double TinhLuong()
		 {
		 	return SoSanPham * DonGiaSanPham;
		 }
 };
 class NVCongNhat: public NhanVien{
 	private: 
	 	int SoNgayCong;
	 	long DonGiaNgay , PhuCapNgoaiGio;
	public:
		void Nhap()
		{
			NhanVien::Nhap();
			cout<<"\nSo Ngay Cong: "; cin>>SoNgayCong;
			cout<<"\nDon Gia Ngay: "; cin>>DonGiaNgay;
			cout<<"\nPhu Cap Ngoai Gio : "; cin>>PhuCapNgoaiGio;
			
		}
		void Xuat()
		{
			NhanVien::Xuat();
			cout<<"\nSo Ngay Cong :"<<SoNgayCong<<"\nDon Gia Ngay:"<<DonGiaNgay<<"\nPhu Cap Ngoai Gio :"<<PhuCapNgoaiGio;
				cout<<fixed<<setprecision(0)<<"\nLuong: "<<TinhLuong()<<"VND"<<endl;
		}
		double TinhLuong(){
			return (SoNgayCong * DonGiaNgay  ) + PhuCapNgoaiGio; 
		}
 	
 };
 class NVQuanLy: public NhanVien{
 	private: 
	 	long LuongCoBan,PhuCapChucVu;
	 	float HeSoLuong;
	public:
		void Nhap()
		{
			NhanVien::Nhap();
			
			cout<<"Luong Co Ban : "; cin>>LuongCoBan;
			cout<<"Phu Cap Phuc Vu: "; cin>>PhuCapChucVu;
			cout<<"He So Luong : "; cin>>HeSoLuong;	
		}
		void Xuat()
		{
			NhanVien::Xuat();
			cout<<"\nLuong Co Ban :"<<LuongCoBan<<"\nPhu Cap Phuc Vu:"<<PhuCapChucVu<<"\nHe So Luong: "<<HeSoLuong<<endl;
				cout<<fixed<<setprecision(0)<<"\nLuong: "<<TinhLuong()<<"VND"<<endl;
		}
		double TinhLuong()
		{
			return (LuongCoBan *  HeSoLuong )+ PhuCapChucVu;
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
		cout<<gocTT<<setw(24)<<setfill(duongTD)<<gocPT<<endl;
		cout<<duongTP<<"1.Nhap Va Xuat NVSX	"<<duongTP<<endl;
		cout<<duongTP<<"2.Nhap Va Xuat NVCN   	"<<duongTP<<endl;
		cout<<duongTP<<"3.Nhap Va Xuat NVQL   	"<<duongTP<<endl;
		cout<<duongTP<<"0.Thoat Chuong Trinh   "<<duongTP<<endl;
		cout<<gocTD<<setw(24)<<setfill(duongTD)<<gocPD<<endl;
		cout<<"Ban Chon Muc: "; cin>>chon;
		switch(chon){
			case 1:{
				NVSanXuat s;
				s.Nhap();
				s.Xuat();
				
				break;
			}
			case 2:{
				NVCongNhat cd;
				cd.Nhap();
				cd.Xuat();
				
				break;
			}
			case 3:{
				NVQuanLy ql;
				ql.Nhap();
				ql.Xuat();
			
				break;
			}
		}
	}while(chon!=0);
 	return 0;
 }
