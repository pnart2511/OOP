#include <iostream>
using namespace std;
template <typename TYPE>
TYPE GetAverage(TYPE array[], int n){
	if(n<=0)
		throw string("Kich thuoc mang phai lon hon 0 ;))");
		TYPE sum = 0;
  for (int i = 0; i < n; i++) {
    sum += array[i];
  }
  return sum / n;
  
}

int main() {
  int arr1[] = {1, 2, 3, 4, 5, 6};
  long arr2[] = {1L, 2L, 3L, 4L, 5L, 6L};
  double arr3[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  char arr4[] = {1, 2, 3, 4, 5, 6};
  short arr5[6];
try{
	cout << GetAverage(arr1, 6) << endl;
	  cout << GetAverage(arr2, 6) << endl;
	  cout << GetAverage(arr3, 6) << endl;
	  cout << GetAverage(arr4, 6) << endl;
	  cout << GetAverage(arr5, 0) << endl; 
	}
	catch(string e){
		cout<<e<<endl;
		
	}
	
  

  return 0;
}
