#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

const int N = 100010;
int n,m;
int w[N];
// 线段树节点
struct Node
{
    int l,r;
    int maxv;
} tr[N*4];

// 更新操作
void pushup(int u) {
    tr[u].maxv = max(tr[u<<1].maxv, tr[u<<1|1].maxv);
}

// 建树
void build(int u, int l, int r) {
    // 递归出口
    if (l == r) tr[u] = {l, r, w[r]};
    else {
        tr[u] = {l, r};
        // 这里的区间中点和query不同
        int mid = l + r >> 1;
        build(u<<1, l, mid), build(u<<1|1, mid+1, r);
        pushup(u);
    }
}

int query(int u, int l, int r) {
    // 这里的l,r实际上就是个限幅数字,不参与线段树实际计算.
    //  这个区间如果在[l,r]范围内,直接返回.
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].maxv;
    int mid = tr[u].l + tr[u].r >> 1;
    int maxv = INT_MIN;
    // ??? 这里赋个INT_MIN在干嘛? 会被覆盖的.
    if (l <= mid) maxv = query(u<<1, l, r);
    if (r > mid) maxv = max(maxv, query(u<<1|1, l, r));
    return maxv;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);

    build(1, 1, n);
    int l, r;
    while (m --)
    {
        scanf("%d%d", &l, &r);
        printf("%d\n", query(1, l, r));
    }
    
    return 0;
}