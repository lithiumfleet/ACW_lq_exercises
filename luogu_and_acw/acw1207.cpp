// 求树的直径: 随便找一点然后找到它的最远点, 再从最远点出发找到最远点的最远点, 这就是直径
// 推导见oiwiki:https://oi-wiki.org/graph/tree-diameter/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
const int N = 100010;
int n;
struct Edge { int id, w; };
vector<Edge> h[N];
int dist[N];

void dfs(int u, int father, int distance) {
    dist[u] = distance;
    for (auto node : h[u]) {
        if (node.id != father) dfs(node.id, u, distance + node.w);
    }
}

int main() {
    // 储存图
    cin >> n;
    for (int i = 0; i < n-1; i ++) {
        int a,b,c;
        scanf("%d%d%d", &a, &b, &c);
        h[a].push_back({b,c});
        h[b].push_back({a,c});
    }

    // 从1点开始找到直径端点
    dfs(1,-1,0);
    int u = 1;
    for (int i = 1; i <= n; i ++) {
        if (dist[i] > dist[u]) u = i;
    }
    // 此时u为直径端点

    memset(dist, 0, sizeof dist);
    dfs(u,-1,0);
    // 此时dist数组里存了从u开始到任意节点距离
    for (int i = 1; i <= n; i ++) {
        if (dist[i] > dist[u]) u = i;
    }

    int s = dist[u];

    printf("%lld\n", s*10+s*(s+1ll)/2);
    
    return 0;
}