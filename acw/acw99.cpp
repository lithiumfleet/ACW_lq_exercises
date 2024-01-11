// 再写一遍
#include <iostream>
#include <cstdio>

using namespace std;
const int N = 5010;
int r;
int s[N][N];

int main() {
    int cnt;
    cin >> cnt >> r;
    r = min(5001, r);
    int max_r = r, max_c = r;
    while (cnt --) {
        int i, j, v;
        cin >> i >> j >> v;
        s[i+1][j+1] += v;
        max_r = max(max_r, i+1);
        max_c = max(max_c, j+1);
    }

    for (int i = 1; i <= max_r; i ++) {
        for (int j = 1; j <= max_c; j ++) {
            s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
        }
    }

    int max_v = 0;
    for (int i = r; i <= max_r; i ++) {
        for (int j = r; j <= max_c; j ++) {
            int cur_v = s[i][j] - s[i][j-r] - s[i-r][j] + s[i-r][j-r];
            max_v = max(max_v, cur_v);
        }
    }

    cout << max_v << endl;
    return 0;
}