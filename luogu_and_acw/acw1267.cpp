#include <cstdio>
#include <iostream>
#include <limits>

using namespace std;

const int N = 32010;
int tr[N], ans[N];
int n;

int lowbit(int x) {
    return x&-x;
}

void add(int l, int v) {
    // 本题中树状数组的范围是N,坐标的范围和n无关
    for (int i = l; i < N; i += lowbit(i)) tr[i] += v;
}

int query(int x) {
    int res = 0;
    for (int i = x; i>0; i -= lowbit(i)) res += tr[i];
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x ++;
        ans[query(x)] ++;
        add(x, 1);
    }
    for (int i = 0; i < n; i ++) {
        printf("%d\n", ans[i]);
    }
    
    return 0;
}