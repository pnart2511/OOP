#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
 static const int size = 10;
  int head;
  int tail;
  T data[size];

public:
  Queue() :  head(0), tail(0) ,data(){
    //data = new T[size];
  }


  void Push(T n) {
    data[tail] = n;
    tail = (tail + 1) % size;
  }

  T Pop() {
    T temp = data[head];
    head = (head + 1) % size;
    return temp;
  }

  void Print() {
    for (int i = head; i != tail; i = (i + 1) % size) {
      cout << data[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  Queue<char> queue;
  queue.Push('D');
  queue.Push('N');
  	queue.Push('C');
	queue.Print();

	queue.Push('C');
  	queue.Push('T');
  	queue.Push('U');
  	queue.Print();
  cout << queue.Pop() << endl;
  cout << queue.Pop() << endl;
  cout << queue.Pop() << endl;
	queue.Print();
  return 0;
}
