#include <iostream>
using namespace std;

int lastDigit(int a, long long b) {
  if(b == 0)
    return 1;
  if(b == 1)
    return a;
  int x = (lastDigit(a, b / 2)) % 10;
  return ((x * x) % 10 * (b & 1 ? a : 1) % 10) % 10;
}

int t, a, b;

int main() {
  cin >> t;
  while(t--) {
    cin >> a;
    cin >> b;
    cout << lastDigit(a, b) << endl;
  }
}
