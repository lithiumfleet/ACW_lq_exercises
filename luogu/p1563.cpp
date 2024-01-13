#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

typedef pair<int, string> pis;

int n,m,x,y;
pis g[100010];

int main() {
    ios::sync_with_stdio(false); // 关同步
    scanf("%d%d", &n, &m);
    for (int i=0; i < n; i ++) cin >> g[i].first >> g[i].second;

    int cur = 0;
    for (int i=0; i < m; i ++) {
        scanf("%d%d", &x, &y);
        if (g[cur].first ^ x) cur = (cur+y) % n; // 用异或判断朝向会更快一些
        else cur = (cur-y+n) % n;
    }
    cout << g[cur].second << '\n';

    return 0;
}