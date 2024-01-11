#include <iostream>
#include <cstdio>

using namespace std;
const int N = 100010;
int n, m;
int a[N], tr[N];


int lowbit(int x) {
    return x&-x;
}

void add(int locate, int val) {
    // 一路向上跳, i的父节点是i+lowbit(i)
    for (int i = locate; i <= n; i += lowbit(i)) tr[i] += val;
}

int query(int x) {
    // 查询sum[1,x]
    int res = 0;
    // 一路向下跳
    for (int i = x; i > 0; i -= lowbit(i)) res += tr[i];
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++) add(i, a[i]);

    while (m --) {
        int k, x, y;
        scanf("%d%d%d", &k, &x, &y);
        if (k == 0) printf("%d\n", query(y) - query(x-1)); // 即sum[1,y] - sum[1,x-1]
        else add(x,y);
    }

    return 0;
}