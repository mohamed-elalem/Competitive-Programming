#include <cstdio>
#include <algorithm>
#define MULL -1e9
using namespace std;

struct Node {
    int best;
    int bestLeft;
    int bestRight;
    int total;
};

Node st[4 * 50050];
int arr[50050];
int n, q;

void build(int p, int l, int r) {
    if(l == r) {
        st[p].best = st[p].bestLeft = st[p].bestRight = st[p].total = arr[l];
    }
    else {
        int ls = p << 1, rs = (p << 1) + 1;
        build(ls, l, (l + r) / 2);
        build(rs, (l + r) / 2 + 1, r);
        st[p].total = st[ls].total + st[rs].total;
        st[p].bestLeft = max(st[ls].bestLeft, st[ls].total + st[rs].bestLeft);
        st[p].bestRight = max(st[rs].bestRight, st[rs].total + st[ls].bestRight);
        st[p].best = max(max(max(st[p].total, st[p].bestLeft), max(st[ls].best, st[rs].best)), max(st[p].bestRight, st[ls].bestRight + st[rs].bestLeft));
    }
}

Node query(int p, int l, int r, int i, int j) {
    if(i > r || j < l) {
        Node nu;
        nu.best = MULL;
        return nu;
    }
    else if(i <= l && j >= r) {
        return st[p];
    }
    int ls = p << 1, rs = (p << 1) + 1;
    Node ln = query(ls, l, (l + r) / 2, i, j);
    Node rn = query(rs, (l + r) / 2 + 1, r, i, j);
    if(ln.best == MULL) {
        return rn;
    }
    else if(rn.best == MULL) {
        return ln;
    }
    Node b;
    b.total = ln.total + rn.total;
    b.bestLeft = max(ln.bestLeft, ln.total + rn.bestLeft);
    b.bestRight = max(rn.bestRight, rn.total + ln.bestRight);
    b.best = max(max(max(b.total, b.bestLeft), max(ln.best, rn.best)), max(b.bestRight, ln.bestRight + rn.bestLeft));
    return b;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    build(1, 0, n - 1);
    scanf("%d", &q);
    int a, b;
    while(q--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", query(1, 0, n - 1, a - 1, b - 1).best);
    }
}
