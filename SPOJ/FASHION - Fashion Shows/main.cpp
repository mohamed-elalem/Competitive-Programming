#include <iostream>
#include <algorithm>
using namespace std;

int t, n;

int man[1010], woman[1010];

int main() {
  cin >> t;
  while(t--) {
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++) {
      cin >> man[i];
    }
    for(int i = 0; i < n; i++) {
      cin >> woman[i];
    }
    sort(man, man + n);
    sort(woman, woman + n);
    for(int i = 0; i < n; i++) {
      sum += man[i] * woman[i];
    }
    cout << sum << endl;
  }
}
