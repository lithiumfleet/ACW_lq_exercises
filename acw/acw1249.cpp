#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200010;
int n, m;
int a[N];

int main() {
    scanf("%d%d", &n, &m);
    int k = n+m+1;
    for (int i=0; i < k; i ++) scanf("%d", &a[i]);
    long long res = 0;
    if (m == 0) {
        // 没有减号时直接返回数组的和就行
        for (int i=0; i < k; i ++) res += a[i];
    } else {
        sort(a, a+k);
        res = a[k-1] - a[0];
        // 后缀表达式: (a)-(b), 所以只要有>=1个负号就能把它当[1,n+m]个负号用
        for (int i=1; i < k-1; i ++) res += abs(a[i]);
    }
    printf("%lld\n", res);
    return 0;
}