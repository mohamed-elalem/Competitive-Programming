#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int multiply(int left[], int right[], int res[], int n, int m) {
  
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= m; j++) {
      res[i + j] += left[j] * right[i];
      res[i + j + 1] += (res[i + j]) / 10;
      res[i + j] %= 10;
    }
  }

  return n + m + 1;
}

int t, n;

int main() {

  int fac[101][1000];
  int endOfNumber[101] = {0};

  memset(fac, 0, sizeof fac);

  fac[0][0] = fac[1][0] = 1;
  endOfNumber[0] = endOfNumber[1] = 0;

  int base[3] = {0};
  
  for(int i = 0; i <= 9; i++) {
    base[1] = i;
    for(int j = (i == 0 ? 2 : 0); j <= 9; j++) {
      base[0] = j;
      endOfNumber[i * 10 + j] = multiply(base, fac[(i * 10 + j) - 1], fac[(i * 10 + j)], endOfNumber[(i * 10 + j) - 1], i > 0);
    }
  }
  base[0] = base[1] = 0;
  base[2] = 1;
  endOfNumber[100] = multiply(base, fac[99], fac[100], endOfNumber[99], 2);

  
  cin >> t;
  while(t--) {
    cin >> n;
    bool write = false;
    for(int i = endOfNumber[n]; i >= 0; i--) {
      if(fac[n][i] != 0)
	write = true;
      if(write)
	cout << fac[n][i];
    }
    cout << endl;
  }
  
}
