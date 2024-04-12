#include <iostream>
#include <stdexcept>
using namespace std;

class CTime{
	private:
	int iHour , iMinute, iSecond;
	public:
		CTime(){
			iHour =  iMinute = iSecond = 0;
		}
		CTime(CTime &t){
			
			iHour = t.iHour;
			iMinute = t.iMinute;
			iSecond = t.iSecond;
		}
		CTime(int h , int m ,int s){
			
			iHour = h ;
			iMinute = m ;
			iSecond = s ;
		}
		
		void Print()
		{
			if(!IsHour())
			{
				throw invalid_argument("Gio Khong Hop Le!!!!!!!!!!!!!!!!!!!!");
				
			}
			if(!IsMinute())
			{
				throw invalid_argument("Phut Khong Hop Le!!!!!!!!!!!!!!!!!!!!");
				
			}
			if(!IsSecond())
			{
				throw invalid_argument("Giay Khong Hop Le!!!!!!!!!!!!!!!!!!!!");
				
			}
			cout<<iHour<<"Gio - "<<iMinute<<"Phut - "<<iSecond<<"Giay "<<endl;
		}
		
				void IncHour() {
				    iHour++;
				    if (iHour > 23) {
				        iHour = 0;
				    }
				}
				
				void DecHour() {
				    iHour--;
				    if (iHour < 0) {
				        iHour = 23;
				    }
				}
				
				void IncMinute() {
				    iMinute++;
				    if (iMinute > 59) {
				        IncHour();
				        iMinute = 0;
				    }
				}
				
				void DecMinute() {
				    iMinute--;
				    if (iMinute < 0) {
				        DecHour();
				        iMinute = 59;
				    }
				}
				
				void IncSecond() {
				    iSecond++;
				    if (iSecond > 59) {
				        IncMinute();
				        iSecond = 0;
				    }
				}
				
				void DecSecond() {
				    iSecond--;
				    if (iSecond < 0) {
				        DecMinute();
				        iSecond = 59;
				    }
				}


		
		
		bool IsHour(){
		
				return (iHour >= 0 && iHour <= 23);
		
		}
		bool IsMinute(){
			
				return (iMinute >= 0 && iMinute <= 59);
		
		}
		bool IsSecond(){
			
				return (iSecond >= 0 && iSecond <=59);
		
		}
		
		void IncHour(int n)
	{
		for(int i = 0 ; i < n ; i ++)
		{
			IncHour();
		}
	}
	void DecHour(int n){
		for(int i = 0 ; i < n ; i ++)
		{
			DecHour();
		}
	}
	void IncMinute(int n)
	{
		for(int i = 0 ; i < n ; i ++)
		{
			IncMinute();
		}
	}
	void DecMinute(int n)
	{
		for(int i = 0 ; i < n ; i ++)
		{
			DecMinute();
		}
	}
	void IncSecond(int n)
	{
		for(int i = 0 ; i < n ; i ++)
		{
			IncSecond();
		}
	}
	void DecSecond(int n){
		for(int i = 0 ; i < n ; i ++)
		{
			DecSecond();
		}
	}
		
		
};

int main(){
	try
	{
	CTime t(23,59,58);
	t.Print();
	t.IncSecond(200);
	t.Print();
	
	}
	catch(logic_error e)
	{
		cout<<e.what()<<endl;
	}
		

	return 0;
}








































































