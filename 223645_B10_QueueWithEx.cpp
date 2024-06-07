#include <iostream>
#include <stdexcept>
using namespace std;

class Full : public exception {
public:
  const char* what() const throw() {
    return "Hang doi da day!";
  }                                                  
};

class Empty : public exception {
public:
  const char* what() const throw() {
    return "Hang doi rong!";
  }
};

template <typename T>
class Queue {
private:
  int size;
  int head;
  int tail;
  int count;
  T* data;

public:
  Queue(int s = 3) : size(s), head(0), tail(0), count(0) {
    data = new T[size];
  }

 // ~Queue() {
   // delete[] data;
  ////////////}

  void Push(T n) {
    if (count == size) {
      throw Full();
    }
    data[tail] = n;
    tail = (tail + 1) % size;
    count++;
  }

  T Pop() {
    if (count == 0) {
      throw Empty();
    }
    T temp = data[head];
    head = (head + 1) % size;
    count--;
    return temp;
  }

  void Print() {
    for (int i = head; i != tail; i = (i + 1) % size) {
      cout<<"Cac phan tu" << data[i]<< " ";
    }
    cout << endl;
  }
};

int main() {
  Queue<int> queue(3); // Queue with a capacity of 3
  int chon, value;

  do {
    queue.Print(); 
    cout << "1 - Them Phan Tu (Push)" << endl;
    cout << "2 - Lay Phan Tu (Pop)" << endl;
    cout << "0 - Thoat " << endl;
    cout << "Chon: ";
    cin >> chon;

    switch (chon) {
      case 1: {
        cout << "Nhap gia tri can them: ";
        cin >> value;
        try {
          queue.Push(value);
        } catch (const Full& e) {
          cerr << "Loi: " << e.what() << endl;
        }
        break;
      }
      case 2: {
        try {
          value = queue.Pop(); 
          cout << "Phan tu lay ra: " << value << endl;
        } catch (const Empty& e) {
          cerr << "Loi: " << e.what() << endl;
        }
        break;
      }
    } 
  } while (chon != 0); 

  return 0;
}
