#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N];

// gcd: 前大后小,如果b为0就返回a, 不为0就把a%b
int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    int n; cin >> n;
    for (int i=0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a, a+n);
    int d = 0;
    for (int i=0; i < n; i ++) {
        d = gcd(d, a[i]-a[0]);
    }

    if (d != 0) cout << (a[n-1]-a[0])/d+1 << endl;
    else cout << n << endl;

    return 0;
}

