#include <iostream>
#include <cstring>
using namespace std;

const int N = 5;
char map[N][N];
char bak[N][N];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool in_bound(int x) {
    return x>=0 && x < 5;
}

void turn(int r, int c) {
    map[r][c] ^= 1;
    for (int i = 0; i < 4; i ++) {
        if (in_bound(r+dx[i]) && in_bound(c+dy[i])) 
            map[r+dx[i]][c+dy[i]] ^= 1;
    }
}

int update() {
    int ans = 0;
    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < 5; j ++) {
            if (map[i][j] == '0') {
                turn(i+1, j); // 艹,原来是这里
                ans ++;
            }
        }
    }
    return ans;
}

bool all_lit() {
    for (int j = 0; j < 5; j ++) {
        if (map[4][j] == '0') return false;
    }
    return true;
}


int main() {
    int tm;
    cin >> tm;
    while (tm --) {
        int res = 1000;
        for (int i = 0; i < 5; i ++) cin >> map[i];
        for (int op = 0; op < 32; op ++) {
            int ans = 0;
            memcpy(bak,map,sizeof bak);
            for (int o = 0; o < 5; o ++) {
                if (op >> o & 1) {
                    turn(0,o);
                    ans ++;
                }
            }
            ans += update();
            if (all_lit()) res = min(res, ans);
            memcpy(map,bak,sizeof bak);
        }
        if (res > 6) res = -1;
        cout << res << endl;
    }
    return 0;
}