#include <iostream>
#include <cmath>
using namespace std;

int t, x, y;

int main() {
  cin >> t;
  while(t--) {
    cin >> x >> y;
    if(x == y) {
      if(x == 1)
	cout << 1 << endl;
      else
	cout << 2 * x - (x & 1) << endl;
    }
    else if(x - y == 2) {
      cout << 2 * x - 2 - (x & 1) << endl;
    }
    else {
      cout << "No Number" << endl;
    }
  }
}
