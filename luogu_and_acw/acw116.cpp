#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 5;

char g[N][N], bak[N][N];

int get(int x, int y) {
    return x * 4 + y;
}

void turn_one(int i, int j) {
    if (g[i][j] == '-') g[i][j] = '+';
    else g[i][j] = '-';
}

void turn_all(int i, int j) {
    for (int r = 0; r < 4; r ++) {
        turn_one(i, r);
        turn_one(r, j);
    }
    turn_one(i, j);
}

int main() {
    for (int i = 0; i < 4; i ++) cin >> g[i];

    // 枚举所有状态
    vector<PII> res;
    for (int op = 0; op < 1 << 16; op ++) {
        vector<PII> temp;
        memcpy(bak, g, sizeof g);

        for (int i = 0; i < 4; i ++) {
            for (int j = 0; j < 4; j ++) {
                if (op >> get(i, j) & 1) {
                    temp.push_back({i, j});
                    turn_all(i, j);
                }
            }
        }

        bool all_lit = false;
        for (int i = 0; i < 4; i ++) {
            for (int j = 0; j < 4; j ++) {
                if (g[i][j] == '+') all_lit = true;
            }
        }

        if (all_lit == false) {
            if (res.empty() || res.size() > temp.size()) res = temp;
        }

        memcpy(g, bak, sizeof bak);
    }

    cout << res.size() << endl;
    for (PII p : res) cout << p.first+1 << ' ' << p.second+1 << endl;

    return 0;
}