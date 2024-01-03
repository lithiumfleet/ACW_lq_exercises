// 第二遍没写出来...这里要枚举全图状态而不是第一列状态
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

// vars
typedef pair<int, int> PII;
const int N = 5;
char g[N][N], bak[N][N];
vector<PII> res;

// funs, 都能写出来
int get(int x, int y) { return x * 4 + y; }
void turn_one(int i, int j) { if (g[i][j] == '-') g[i][j] = '+'; else g[i][j] = '-'; }
void turn_all(int i, int j) { for (int r = 0; r < 4; r ++) { turn_one(i, r); turn_one(r, j); } turn_one(i, j); }


int main() {

    for (int i = 0; i < 4; i ++) cin >> g[i];

    // 枚举全图状态
    for (int op = 0; op < 1 << 16; op ++) {
        memcpy(bak, g, sizeof g);
        vector<PII> temp;
        for (int i = 0; i < 4; i ++) {
            for (int j = 0; j < 4; j ++) {
                if (op >> get(i, j) & 1) {
                    temp.push_back({i, j});
                    turn_all(i, j);
                }
            }
        }

        // check all lit
        bool all_lit = true;
        for (int i = 0; i < 4; i ++) {
            for (int j = 0; j < 4; j ++) {
                if (g[i][j] == '+') all_lit = false;
            }
        }

        if (all_lit == true) {
            if (res.empty() || res.size() > temp.size()) res = temp;
        }

        memcpy(g, bak, sizeof bak);
    }

    cout << res.size() << endl;
    for (PII p : res) cout << p.first+1 << ' ' << p.second+1 << endl;

    return 0;
}