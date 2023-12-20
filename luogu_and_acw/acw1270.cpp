#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

const int N = 100010;
int n,m;
int w[N];
struct Node
{
    int l,r;
    int maxv;
} tr[N*4];

void pushup(int u) {
    tr[u].maxv = max(tr[u<<1].maxv, tr[u<<1|1].maxv);
}

void build(int u, int l, int r) {
    if (l == r) tr[u] = {l, r, w[r]};
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u<<1, l, mid), build(u<<1|1, mid+1, r);
        pushup(u);
    }
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].maxv;
    int mid = tr[u].l + tr[u].r >> 1;
    int maxv = INT_MIN;
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