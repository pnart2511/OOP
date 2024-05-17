#include <iostream>

using namespace std;

class Airship{
	private:
		 int MaxQuantity,MaxWeight;
	public:
		Airship(){
			MaxQuantity = 0 ; MaxWeight = 0;
		}
		Airship(int mq, int mw) {
	    MaxQuantity = mq;
	    MaxWeight = mw;
	  }
		void virtual Print(){
			cout<<MaxQuantity<<""<<MaxWeight<<endl;
		}
};
class Airplane :public Airship
{
	private:
	string EngineType;
	public:
		Ariplane(){
			EngineType = "";
		}
		Airplane(string etype , int mq , int mw):Airship(mq,mw){
			EngineType = etype;
		}
		void  Print(){
			cout<<EngineType<<"";
			Airship::Print();
		}
				
};
class Balloon:public Airship{
	private:
		string FuelType;
		public:
			Balloon();
			Balloon(string fType , int mq , int mw):Airship(mq,mw){
				FuelType = fType;
			}
		void  Print(){
			
			cout<<FuelType<<" ";
			Airship::Print();
			
		}
};
int main(){
	
		Airship *a, b(120, 30000);
	a = &b;
	a->Print();
	Airplane ai("Phan luc", 100, 25000);
a = &ai;
	a->Print();
	Balloon ba("Hydrogen", 20, 200);
	a = &ba;
	a->Print();
	//return 0;
	return 0;
}
