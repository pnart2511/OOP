#include <iostream>
using namespace std;

class CMyString {
private:
    string Str;
public:
    CMyString(string str = "") {
        Str = str;
    }

    friend CMyString operator+(const CMyString& c1, const CMyString& c2) { 
        CMyString kq;
        kq.Str = c1.Str + c2.Str;
        return kq;
    }

    CMyString& operator=(const CMyString& c) { 
        this->Str = c.Str;
        return *this;
    }

    friend istream& operator>>(istream& is, CMyString& c) {
        cout << "Nhap:";
        is >> c.Str;
        return is;
    }

    
    friend ostream& operator<<(ostream& os, const CMyString& c) { 
        os << c.Str << endl;
        return os;
    }

    
    friend bool operator==(const CMyString& c1, const CMyString& c2) {
        return c1.Str == c2.Str;
    }

    friend bool operator>=(const CMyString& c1, const CMyString& c2) {
        return c1.Str >= c2.Str;
    }

    friend bool operator<=(const CMyString& c1, const CMyString& c2) {
        return c1.Str <= c2.Str;
    }

    friend bool operator>(const CMyString& c1, const CMyString& c2) {
        return c1.Str > c2.Str;
    }

    friend bool operator<(const CMyString& c1, const CMyString& c2) {
        return c1.Str < c2.Str;
    }

    friend bool operator!=(const CMyString& c1, const CMyString& c2) {
        return c1.Str != c2.Str;
    }
};

int main() {

    CMyString c1, c2, c3;
    cin >> c1;
    cin >> c2;
    c3 = c1 + c2;
    cout << c1 << "+" << c2 << "=" << c3 << endl;
	if (c1 == c2) { // S?a toán t? gán = thành toán t? so sánh ==
        cout << c1 << "==" <<c2 << endl;
    }  if(c1 != c2) {
        cout << c1 << "!=" << c2 << endl;
    } 
     if(c1 >= c2) {
        cout << c1 << ">=" << c2 << endl;
    } 
      if(c1 <= c2) {
        cout << c1 << "<=" << c2 << endl;
    }
      if(c1 < c2) {
        cout << c1 << "<" << c2 << endl;
    }
     if(c1 > c2) {
        cout << c1 << ">" << c2 << endl;
    }
    return 0;
}
