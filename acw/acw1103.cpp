#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int N = 210;

int n, m;
char g[N][N];
int dis[N][N];
int d[4][2] = {0,1,1,0,0,-1,-1,0};

int bfs(pii src, pii dst) {
    queue<pii> q;
    memset(dis, -1, sizeof dis);
    dis[src.first][src.second] = 0;
    q.push(src);
    while (!q.empty()) {
        pii temp = q.front();
        q.pop();
        for (int i = 0; i < 4; i ++) {
            int x = temp.first + d[i][0];
            int y = temp.second + d[i][1];
            if (x>=0 && x<n && y>=0 && y<m && g[x][y]!='#' && dis[x][y] == -1) {
                dis[x][y] = dis[temp.first][temp.second] + 1;
                if (dst.first == x && dst.second == y) return dis[x][y];
                q.push(pii(x,y));
            }
        }
    }
    return -1;
} 


int main() {
    int T; cin >> T;
    while (T --)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i ++) scanf("%s", g[i]);
        pii src, dst;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j ++) {
                if (g[i][j] == 'S') src = {i, j};
                if (g[i][j] == 'E') dst = {i, j};
            }
        }
        int distance = bfs(src, dst);
        if (distance == -1) printf("oop!\n");
        else printf("%d\n", distance);
    }
    return 0;
}

