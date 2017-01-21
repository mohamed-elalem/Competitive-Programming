#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

typedef long long ll;

const int MAX_SZ = 32624;

vector<int> primes;

bitset<MAX_SZ> bs;

void sieve() {
  bs.set();
  bs[0] = bs[1] = 0;

  for(int i = 2; i < MAX_SZ; i++) {
	if(bs[i]) {
	  for(int j = i * i; j < MAX_SZ; j += i)
		bs[j] = 0;
	  primes.push_back(i);
	}
  }
}

bool checkPrime(ll num) {
  if(num < MAX_SZ) {
	return bs[num];
  }
  for(int i = 0; i < primes.size(); i++) {
	if(num % primes[i] == 0) {
	  return false;
	}
  }
  return true;
}

int t;
ll a, b;

int main() {

  sieve();
  
  cin >> t;

  while(t--) {
	cin >> a >> b;
	for(ll i = a; i <= b; i++) {
	  if(checkPrime(i))
		cout << i << endl;
	}
	cout << endl;
  }
}
