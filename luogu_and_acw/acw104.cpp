#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100010;
int w[N];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) scanf("%d", &w[i]);
    // 所有店铺到某点距离和最小
    sort(w, w+n);

    // 最优解一定在中位数处
    // https://www.acwing.com/solution/content/5382/
    int c = w[n/2];
    long long res = 0;
    for (int i = 0; i < n; i ++) res += abs(w[i] - c);
    cout << res << endl;


    return 0;
}