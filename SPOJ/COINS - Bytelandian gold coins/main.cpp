#include <iostream>
#include <map>
using namespace std;

map<long long, long long> dp;

long long maxCoins(long long coins) {
  if(coins == 0) {
    return coins;
  }

  if(dp.find(coins) != dp.end()) {
    return dp[coins];
  }
  return dp[coins] = max(dp[coins], max(coins, (maxCoins(coins / 2) + maxCoins(coins / 3) + maxCoins(coins / 4))));
}

long long n;

int main() {
  while(cin >> n, !cin.eof()) {
    cout << maxCoins(n) << endl;
  }
}
