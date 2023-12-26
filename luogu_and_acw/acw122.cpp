// 这下是真看不懂了
// #include <iostream>
// #include <numeric>
// #include <algorithm>

// using namespace std;

// typedef long long LL;

// const int N = 1e6 + 10;

// int n;
// int c[N];
// LL s[N], a[N];

// long long calc(int c[], int n)
// {
//     int avg = accumulate(c + 1, c + n + 1, 0ll) / n;
//     for (int i = 1; i <= n; i ++ ) a[i] = c[i] - avg;
//     for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + a[i];
//     sort(s + 1, s + n + 1);
//     long long res = 0;
//     for (int i = 1; i <= n; i ++ ) res += abs(s[i] - s[(n + 1) / 2]);
//     return res;
// }
// int main() {
//     scanf("%d", &n);
//     for (int i = 1; i <= n; i ++ ) scanf("%d", &c[i]);
//     printf("%lld\n", calc(c, n));
//     return 0;
// }