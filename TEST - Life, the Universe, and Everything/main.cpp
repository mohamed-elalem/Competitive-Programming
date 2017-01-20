#include <iostream>
using namespace std;

int main() {
  int x;
  bool write = true;
  while(cin >> x) {
    if(x == 42)
      write = false;
    if(write)
      cout << x << endl;
  }
}
