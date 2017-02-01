#include <iostream>
using namespace std;

int t;
string s;

bool check_palin(string s) {
  for(int i = 0; i < s.size() - i; i++) {
    if(s[i] != s[s.size() - i - 1])
      return false;
  }
  return true;
}

string getNext(string s, int k, int diff) {
  while(k >= 0 && s[k] == '9') {
    s[k] = s[k + diff] = '0';
    k--;
    diff += 2;
  }
  if(k == -1) {
    s[0] = '1';
    s += "1";
  } else {
    s[k] = s[k + diff] = s[k] + 1;
  }
  return s;
}

string getAns(string s) {
  int k = (s.size() - 1) / 2;
  int diff = 1 - s.size() % 2;

  if(check_palin(s)) {
    return getNext(s, k, diff);
  }
  else {
    int tk = k;
    int tdiff = diff;
    bool smaller = true;
    string ts = s;
    for(int i = 0; i < ts.size() - i; i++) {
      ts[i] = ts[s.size() - i - 1] = ts[i];
    }
    if(ts.compare(s) < 0)
      return getNext(ts, k, diff);
    else
      return ts;
  }
  
}

int main() {
  cin >> t;
  while(t--) {
    cin >> s;
    cout << getAns(s) << endl;
  }
}
