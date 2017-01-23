#include <iostream>
using namespace std;

int a, b, c;

int main() {
  while(cin >> a >> b >> c) {
    if(a == 0 && b == 0 && c == 0)
      break;
    if(c - b == b - a) {
      cout << "AP " << c + (c - b) << endl;
    }
    else {
      if(a + b != 0) {
	cout << "GP " << c * (b + c) / (a + b) << endl;
      }
      else {
	cout << "GP " << 0 << endl;
      }
    }
  }
}
