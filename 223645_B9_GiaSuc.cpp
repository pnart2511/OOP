#include <iostream>
#include <cstdlib>
using namespace std;
class GiaSuc{
	protected:
		int SoCon;
		int LuongSua;
	public:
		virtual string TenGiaSuc()= 0 ;
		virtual void Keu()= 0;
		virtual void HienThi(){
			cout<<TenGiaSuc()<<endl;
			cout<<"So con sau 1 lua sinh: "<<SoCon<<endl;
			cout<<"So lit sua thu duoc la: "<<LuongSua<<endl;
		}
}; 
int random(int min , int max){
	return min+rand()%(max-min);
}
class Bo:public GiaSuc{
	public:
		Bo(){
			SoCon = random(0,1);
			LuongSua = random(0,20);
			
		}
		virtual string TenGiaSuc(){
			return "Bo";
			
		}
		virtual void Keu(){
			cout<<"Bo Keu : Mow mow moww......"<<endl;
		}
};
class Cuu:public GiaSuc{
	public:
		Cuu(){
			SoCon = random(0,3);
			LuongSua = random(0,5);
			
		}
		virtual string TenGiaSuc(){
			return "Cuu";
			
		}
		virtual void Keu(){
			cout<<"Cuu Keu : Opaoapapapa"<<endl;
		}
};
class De:public GiaSuc{
	public:
		De(){
			SoCon = random(0,3);
			LuongSua = random(0,5);
			
		}
		virtual string TenGiaSuc(){
			return "De";
			
		}
		virtual void Keu(){
			cout<<"De Keu : bee bee bee ......"<<endl;
		}
};
int main(){
	GiaSuc **gs;
	gs= new GiaSuc*[3];
	gs[0] = new Bo;
	gs[1] = new Cuu;
	gs[2] = new De;
	cout<<"hom nay chu di vang gia suc keu am i"<<endl;
	for(int i = 0 ; i<3 ; i++){
		gs[i]->Keu();
	}
	
	cout<<"thong ke"<<endl;
	for(int i = 0 ; i<3 ; i++){
		gs[i]->HienThi();
	}
	return 0;
}
