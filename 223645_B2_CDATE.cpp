#include <iostream>
#include <stdexcept>
using namespace std;
 
class CDate{
	
	
	private:
		int iYear , iMonth , iDay;
		static int DayinMonth[13];
	public:
		//ham dung k tham so 
		CDate(){
			iYear = iMonth = iDay = 0;
		}
		CDate(CDate& d)
		{
			iDay = d.iDay;
			iMonth = d.iMonth;
			iYear = d.iYear;
		}
		CDate(int day , int month , int year){
			iDay = day;
			iMonth = month;
			iYear = year;
			if(IsLeapYear())
			{
				DayinMonth[2] = 29;
			}
		}
		//ham in
		
		void Print(){
			if(!IsYear())
			{
				throw invalid_argument("Nam Khong Hop Le!!!!!!!!!!!!!!!!!!!!");
				
			}
			if(!IsMonth())
			{
				throw invalid_argument("Thang Khong Hop Le!!!!!!!!!!!!!!!!!!!!");
				
			}
			if(!IsDay())
			{
				throw invalid_argument("Ngay Khong Hop Le!!!!!!!!!!!!!!!!!!!!");
				
			}
			
			cout<<iDay<<"/"<<iMonth<<"/"<<iYear<<endl;
		}
		//ham 14 ->17
		bool IsYear()
		{
			if(iYear> 0 )
				 {
				 	return true;
				 }
				 else
				 {
				 	return false;
				 }
		}
		
		
		bool IsMonth()
		{
			if(iMonth >= 1 && iMonth <= 12)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
		
		
		
	
		bool IsDay()
		{
			if(iDay >= 1 && iDay <= DayinMonth[iMonth] )
			{
				return true;
				
			}
			else {
				return false;
			}
		}
		bool IsLeapYear(){
			
			if(iYear % 4 == 0 && iYear % 100 != 0 || (iYear % 400 == 0)) 
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		//ham 2 -> 7 
		
	 void IncYear() {
        iYear++;
        if (IsLeapYear()) {
            DayinMonth[2] = 29;
        } else {
            DayinMonth[2] = 28;
        }
    }

   
    void DecYear() {
        iYear--;
        if (IsLeapYear()) {
            DayinMonth[2] = 29;
        } else {
            DayinMonth[2] = 28;
        }
    }

    
    void IncMonth() {
        iMonth++;
        if (iMonth > 12) {
            IncYear();
            iMonth = 1;
        }
    }

  
    void DecMonth() {
        iMonth--;
        if (iMonth < 1) {
            DecYear();
            iMonth = 12;
        }
    }

    
    void IncDay() {
        iDay++;
        if (iDay > DayinMonth[iMonth]) {
            IncMonth();
            iDay = 1;
        }
    }

    
    void DecDay() {
        iDay--;
        if (iDay < 1) {
            DecMonth();
            iDay = DayinMonth[iMonth];
        }
    }

	//ham 8 - 13 
	
	void IncYear(int n)
	{
		for(int i = 0 ; i < n ; i ++)
		{
			IncYear();
		}
	}
	void DecYear(int n){
		for(int i = 0 ; i < n ; i ++)
		{
			DecYear();
		}
	}
	void IncMonth(int n)
	{
		for(int i = 0 ; i < n ; i ++)
		{
			IncMonth();
		}
	}
	void DecMonth(int n)
	{
		for(int i = 0 ; i < n ; i ++)
		{
			DecMonth();
		}
	}
	void IncDay(int n)
	{
		for(int i = 0 ; i < n ; i ++)
		{
			IncDay();
		}
	}
	void DecDay(int n){
		for(int i = 0 ; i < n ; i ++)
		{
			DecDay();
		}
	}
};
int CDate::DayinMonth[13]= { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; 
int main()
{
	
	try{
	CDate d(12,4,2024);
	d.Print();
	
	d.IncDay(4000);
	d.Print();
	
	
	
	}
	catch(logic_error e)
	{
		cout<<e.what()<<endl;
	}
	
	
	
	

	
	
	
	return 0;
}
