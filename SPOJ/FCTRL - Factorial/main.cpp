#include <iostream>
using namespace std;

int t;
long long n;

int main() {
  cin >> t;
  while(t--) {
    cin >> n;
    int res = 0;
    int base = 5;
    while(base <= n) {
      res += n / base;
      base *= 5;
    }
    cout << res << endl;
  }
}
