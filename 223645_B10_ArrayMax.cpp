#include <iostream>
using namespace std;

template <typename T>
T ArrayMax(T array[], int n) {
	if(n<=0)
		throw string("Kich thuoc n > 0 ");
  T max = array[0];
  for (int i = 1; i < n; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
} 

int main() {
	try{
		int arr1[] = {3, 7, 11, 9};
		double arr2[] = {3.5, 4.0, 8.0, 6.0, 5.0};
		cout << ArrayMax(arr1, 4) << endl;
		cout << ArrayMax(arr2, 5) << endl;
	}
	catch(string e){
		cout<<e<<endl;
	}

return 0;
}
