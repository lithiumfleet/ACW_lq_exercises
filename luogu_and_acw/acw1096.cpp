#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 105;
struct point {
    int x, y, z;
};
int L, R, C;
char g[N][N][N];
int dist[N][N][N];

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

bool inmap(int num, int max_num) {
    return num>=0 && num<max_num;
}

int bfs(point src, point dst) {
    // 起始节点入队初始化 -> 队列非空循环 -> 拿到多向搜索位置 -> 判断 -> 距离++
    queue<point> q;
    q.push(src);
    dist[src.x][src.y][src.z] = 0;
    while (!q.empty())
    {
        point t = q.front();
        q.pop();
        
        for (int i = 0; i < 6; i++) {
            int a = t.x+dx[i], b = t.y+dy[i], c = t.z+dz[i];
            if (!(inmap(a,L)&&inmap(b,R)&&inmap(c,C))) continue;
            if (g[a][b][c] == '#') continue;
            if (dist[a][b][c] != -1) continue;
            dist[a][b][c] = dist[t.x][t.y][t.z] + 1;
            if (a==dst.x&&b==dst.y&&c==dst.z) return dist[a][b][c];
            q.push({a,b,c});
        }
    }
    return -1;
}

int main() {
    int n,m,z;
    while(cin >> n >> m >> z, n || m || z) {
        L = n, R = m, C = z;
        point src, dst;
        memset(dist, -1, sizeof dist);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                for (int k = 0; k < z; k ++) {
                    cin >> g[i][j][k];
                    if (g[i][j][k] == 'S') src = {i,j,k};
                    if (g[i][j][k] == 'E') dst = {i,j,k};
                }
            }
        }
        int res = bfs(src, dst);
        if (res == -1) puts("Trapped!");
        else cout << "Escaped in "  << res << " minute(s)." << endl;
    }
    return 0;
}