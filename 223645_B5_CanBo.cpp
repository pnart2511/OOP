#include <iostream>
#include<iomanip>
using namespace std;

class CANBO{
	private:
	
		int maCanBo , maDonVi ;
		string hoTen, ngaySinh;
		
	public:
		void Nhap(){
			cout<<"Nhap Ma Can Bo :"; cin>>maCanBo;
			cout<<"Nhap ma don vi :"; cin>>maDonVi;
			cout<<"Nhap ho va ten :"; cin.ignore();getline(cin , hoTen);
			cout<<"Nhap Ngay Sinh :"; cin.ignore(); getline(cin , ngaySinh);
			
		}
		void Xuat(){
			cout<<"-"<<"Ma Can Bo:"<<maCanBo<<endl;
			cout<<"-"<<"Ma Don Vi:"<<maDonVi<<endl;
			cout<<"-"<<"Ho Va Ten:"<<hoTen<<endl;
			cout<<"-"<<"Ngay Sinh:"<<ngaySinh<<endl;
			
		}
		int LayMaDonVi(){
			return maDonVi;
		}
};
class LUONG:public CANBO{
	private:
	float  heSoLuong;
	long phuCap , baoHiem;
	
	public:
		void Nhap(){
			CANBO::Nhap();
			cout<<"He So Luong : "; cin>>heSoLuong;
			cout<<"Phu Cap: "; cin>>phuCap;
			cout<<"bao Hiem: "; cin>>baoHiem;
			
		}	
		void Xuat(){
			CANBO::Xuat();
			cout<<"HSL : "<<heSoLuong<<endl;
			cout<<"Phu Cap : "<<phuCap<<endl;
			cout<<"Bao Hiem : "<<baoHiem<<endl;
			cout<<"Luong : "<<fixed<<setprecision(0)<<TinhLuong()<<endl;
		}
		
	 float TinhLuong() {
    return heSoLuong * 1800000 + phuCap - baoHiem;
  }
};

int main() {
   LUONG *cb;
   int n;
   cout<<"So Luong Can bo can nhap: "; cin>>n;
   cb= new LUONG[n];
   for(int i = 0 ; i < n ; i ++)
   {
   	cout<<"Thong tin can bo thu "<<i+1<<endl;
   	cb[i].Nhap();
   }
   
   //thuat toan
   bool DaHoanVi;
   for(int i = 0 ; i<n ; i++)
   {
   	DaHoanVi = false;
   	
   	for(int j = 0 ; j<n - i - 1 ; j ++)
   	{
   		if(	cb[j].LayMaDonVi() > cb[j+1].LayMaDonVi())
   		{
   			LUONG tmp  = cb[j];
   			cb[j] = cb[j+1];
   			cb[j+1] = tmp;
   			DaHoanVi = true;
		   }
	   }
	   if(DaHoanVi == false)
	   			break;
   }
   
   
   
  
	cout<<"Danh Sach Vua Nhap:\n"<<endl;
	for(int i = 0 ; i < n ; i ++)
   {
   	 cout<<"--------------------------------------------------\n"<<endl;
   	cout<<"Thong tin can bo thu "<<i+1<<endl;
   	cb[i].Xuat();
   }
    return 0;
}

