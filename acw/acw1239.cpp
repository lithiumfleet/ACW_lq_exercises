#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 100010, mod = 1000000009;
int n, k;
int a[N];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    sort(a, a+n);
    int res = 1;
    int l = 0, r = n-1;
    int sign = 1;
    // 特判: k为奇数, 转成偶数
    if (k % 2) {
        res = a[r--];
        k --;
        // 输入全是负数的情况
        if (res < 0) sign = -1;
    }
    while (k) {
        ll x = (ll)a[l] * a[l+1], y = (ll)a[r-1] *a[r];
        if (x * sign > y * sign) {
            res = x % mod * res % mod;
            l += 2;
        } else {
            res = y % mod * res % mod;
            r -= 2;
        }
        k -= 2;
    }
    printf("%d\n", res);
    return 0;
}