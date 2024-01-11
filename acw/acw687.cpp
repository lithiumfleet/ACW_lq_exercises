#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
// 有序数组不含逆序对
// 冒泡排序每次操作都会使逆序对数量减一
// 对于每个元素,交换次数>=k1+k2.且可以取到等号
const int N = 1000010;
int n;
int h[N], tr[N];
int sum[N];
typedef long long LL;

int lowbit(int x) {
    return x & -x;
}

int query(int loc) {
    int res = 0;
    for (int i = loc; i > 0; i -= lowbit(i)) res += tr[i];
    return res;
}

void add(int loc, int v) {
    for (int i = loc; i < N; i += lowbit(i)) tr[i] += v;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) scanf("%d", &h[i]), h[i] ++;

    for (int i = 0; i < n; i ++) {
        sum[i] = query(N-1) - query(h[i]);
        add(h[i], 1);
    }

    memset(tr, 0, sizeof tr);
    for (int i = n-1; i >= 0; i --) {
        sum[i] += query(h[i]-1);
        add(h[i], 1);
    }

    LL res = 0;
    for (int i = 0; i < n; i ++) res += (LL)sum[i]*(sum[i]+1)/2;

    cout << res << endl;

    return 0;
}