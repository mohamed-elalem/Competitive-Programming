#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstring>
#define MAX_SIZE 1024000
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

using namespace std;

int t, c, m, q, a, b, res;
char s;
string pirates;
int fin[MAX_SIZE];
int st[4 * MAX_SIZE];
int lazy[4 * MAX_SIZE];


void mutate(int p, int l, int r, int status) {
    switch(status) {
    case 1:
        st[p] = (r - l) + 1;
        break;
    case 2:
        st[p] = 0;
        break;
    case 4:
        st[p] = (r - l + 1) - st[p];
    }
}

int build(int p, int l, int r) {
    if(l == r) {
        return st[p] = fin[l];
    }
    return st[p] = build(p << 1, l, (l + r) >> 1) + build((p << 1) + 1, ((l + r) >> 1) + 1, r);
}

int update(int p, int l, int r, int i, int j, int status) {
    if(lazy[p]) {
//        cout << "Lazy at " << l << " " << r << endl;
//        printf("Lazy value "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(lazy[p]));
//        cout << endl;
        if(l < r) {
            if(lazy[p] == 4) {
                lazy[p << 1] ^= 4;
                lazy[(p << 1) + 1] ^= 4;
            }
            else {
                lazy[p << 1] = lazy[p];
                lazy[(p << 1) + 1] = lazy[p];
            }
        }
        while(lazy[p]) {
            mutate(p, l, r, lazy[p] & -lazy[p]);
            lazy[p] -= (lazy[p] & -lazy[p]);
        }
    }

    if(i <= l && j >= r) {
//        cout << "Updating lazy at " << l << " " << r << endl;
//        printf("Lazy value "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(lazy[p]));
//        cout << endl;
        if(status == 0 || status == 1) {
            lazy[(p << 1)] = (1 << status);
            lazy[(p << 1) + 1] = (1 << status);
        }
        else {
            lazy[p << 1] ^= 4;
            lazy[(p << 1) + 1] ^= 4;
        }
        mutate(p, l, r, 1 << status);
        return st[p];
    }
    if(i > r || j < l)
        return st[p];
    return st[p] = update(p << 1, l, (l + r) / 2, i, j, status) + update((p << 1) + 1, (l + r) / 2 + 1, r, i, j, status);
}

int sum(int p, int l, int r, int i, int j) {
    if(lazy[p]) {
//        cout << "Lazy at " << l << " " << r << endl;
//        printf("Lazy value "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(lazy[p]));
//        cout << endl;
        if(l < r) {
            if(lazy[p] == 4) {
                lazy[p << 1] ^= 4;
                lazy[(p << 1) + 1] ^= 4;
            }
            else {
                lazy[p << 1] = lazy[p];
                lazy[(p << 1) + 1] = lazy[p];
            }
        }
        while(lazy[p]) {
            mutate(p, l, r, lazy[p] & -lazy[p]);
            lazy[p] -= (lazy[p] & -lazy[p]);
        }
    }
    if(i <= l && j >= r)
        return st[p];
    if(i > r || j < l)
        return 0;
    return sum(p << 1, l, (l + r) / 2, i, j) + sum((p << 1) + 1, (l + r) / 2 + 1, r, i, j);
}

void printTree(int n) {
    for(int i = 1; i < n; i++) {
        int j = i;
        while(j) {
            cout << j << " ";
            j /= 2;
        }
        cout << ". " << st[i] << " " << lazy[i] << endl;
    }
}

int main()
{
    cin >> t;
    for(int C = 1; C <= t; C++) {
        cout << "Case " << C << ":" << endl;
        memset(lazy, 0, sizeof lazy);
        cin >> m;
        int n = 0;
        while(m--) {
            cin >> c;
            cin >> pirates;
            while(c--) {
                for(int i = 0; i < pirates.size(); i++) {
                    fin[n++] = pirates[i] - '0';
                }
            }
        }
//        cout << "Generated " << n << " length string " << endl;
        build(1, 0, n - 1);
//        printTree(4 * n);
        cin >> q;
        int answered = 0;
        while(q--) {
            cin >> s >> a >> b;
            if(s == 'F') {
                update(1, 0, n - 1, a, b, 0);
            }
            else if(s == 'E') {
                update(1, 0, n - 1, a, b, 1);
            }
            else if(s == 'I') {
                update(1, 0, n - 1, a, b, 2);
            }
            else {
                res = sum(1, 0, n - 1, a, b);
                cout << "Q" << ++answered << ": " << res << endl;
            }
//            printTree(4 * n);
        }
    }
}
