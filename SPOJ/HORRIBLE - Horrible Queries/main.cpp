#include <iostream>
#include <vector>
#include <cstring>
#define LEFT(x) (x << 1)
#define RIGHT(x) ((x << 1) + 1)
using namespace std;

long long lazy[1000500], st[1000500];

void init() {
  memset(st, 0LL, sizeof st);
  memset(lazy, 0LL, sizeof lazy);
}

long long query(int p, int l, int r, int i, int j) {
  if(lazy[p]) {
    st[p] += 1LL * (r - l + 1) * lazy[p];
    lazy[LEFT(p)] += lazy[p];
    lazy[RIGHT(p)] += lazy[p];
    lazy[p] = 0;
  }
  if(i <= l && j >= r) {
    return st[p];
  }
  else if(i > r || j < l) {
    return 0;
  }
  return query(LEFT(p), l, (l + r) / 2, i, j) + query(RIGHT(p), (l + r) / 2 + 1, r, i, j);
}

long long update(int p, int l, int r, int i, int j, long long v) {
  if(lazy[p]) {
    st[p] += 1LL * (r - l + 1) * lazy[p];
    lazy[LEFT(p)] += lazy[p];
    lazy[RIGHT(p)] += lazy[p];
    lazy[p] = 0;
  }

  if(i <= l && j >= r) {
    st[p] += 1LL * (r - l + 1) * v;
    lazy[LEFT(p)] += v;
    lazy[RIGHT(p)] += v;
    return st[p];
  }
  else if(i > r || j < l) {
    return st[p];
  }
  else {
    return st[p] = update(LEFT(p), l, (l + r) / 2, i, j, v) + update(RIGHT(p), (l + r) / 2 + 1, r, i, j, v);
  }
}


int t, n, q, o, a, b, v;

int main() {
  cin >> t;
  while(t--) {
    cin >> n >> q;

    init();

    while(q--) {
      cin >> o >> a >> b;
      a--;
      b--;
      if(o == 0) {
        cin >> v;
        update(1, 0, n - 1, a, b, v);
      }
      else {
        cout << query(1, 0, n - 1, a, b) << endl;
      }
    }
  }
}
