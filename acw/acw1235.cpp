#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 500010;
int n;
int a[N];

int main() {
    long double s;
    cin >> n >> s;
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    // 已排序, 所以接下来的贪心有效
    sort(a,a+n);
    long double res = 0, avg = s / n;
    for (int i = 0; i < n; i ++) {
        // s为剩下的人要付的钱
        // 贪心, cur为后面的人要付的平均数
        double cur = s / (n-i);
        if (a[i] < cur) cur = a[i];
        res += (cur-avg) * (cur-avg);
        s -= cur;
    }
    printf("%.4Lf\n", sqrt(res/n));
    return 0;
}