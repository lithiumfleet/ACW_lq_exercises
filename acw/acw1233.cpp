// 思路是统计土地数量和被淹没的土地数量是否相等
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1010;
char g[N][N];
bool st[N][N];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n;
typedef pair<int,int> pii;

bool inmap(int x) {
    return x>=0 && x<n;
}

void bfs(int x, int y, int &total, int &bound) {
    queue<pii> q;
    q.push({x,y});
    st[x][y] = true;
    while (!q.empty()) {
        pii t = q.front();
        q.pop();
        total ++;
        bool is_bound = false;

        for (int i = 0; i < 4; i ++) {
            int a = t.first+dx[i], b = t.second+dy[i];
            if (!(inmap(a)&&inmap(b))) continue;
            if (st[a][b]) continue;
            if (g[a][b] == '.') {
                is_bound = true;
                continue;
            }
            q.push({a,b});
            st[a][b] = true;
        }
        if (is_bound) bound ++;
    }
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> g[i];

    int res = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (!st[i][j] && g[i][j] == '#') {
                int total = 0, bound = 0;
                bfs(i, j, total, bound);
                if (total == bound) res ++;
            }
        }
    }
    cout << res << endl;
    return 0;
}