#include <iostream>
using namespace std;

long long padding = 250LL, k;
int t;

int main() {
  cin >> t;
  while(t--) {
    cin >> k;
    cout << (k - 1) * padding + 192LL << endl;
  }
}
