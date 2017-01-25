#include <iostream>
#include <cmath>
using namespace std;

int n;

int main() {
  cin >> n;
  int ans = 0;
  for(int i = 1; i * i <= n; i++) {
    ans += n / i - i;
  }
  cout << int(ans + sqrt(n)) << endl;
}
