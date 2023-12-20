// #include <iostream>

// using namespace std;
// const int R = 105, C = 105;
// // 记录从1,1到i,j路线的最大值
// int dp[R][C];
// int m[R][C];
// // dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

// int main() {
//     int t, r, c;
//     cin >> t;
//     while(t --) {
//         cin >> r >> c;
//         for (int i = 1; i <= r; i ++) {
//             for (int j = 1; j <= c; j ++) {
//                 cin >> m[i][j];
//             }
//         }

//         for (int i = 1; i <= r; i ++) {
//             for (int j = 1; j <= c; j ++) {
//                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + m[i][j];
//             }
//         }
//         cout << dp[r][c] << endl;
//     }
//     return 0;
// }

#include <iostream>
using namespace std;
int map[105][105];
// 拆子问题: 从起点走到i,j处可以摘到最大花生数
int dp[105][105];
// 子问题最优解: max(上面的最优, 左边的最优) + map[i][j]


int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t ++) {
        int R, C;
        cin >> R >> C;
        for (int i = 1; i <= R; i ++) {
            for (int j = 1; j <= C; j ++) {
                cin >> map[i][j];
            }
        }

        for (int i = 1; i <= R; i ++) {
            for (int j = 1; j <= C; j ++) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + map[i][j];
            }
        }

        int res = dp[R][C];
        cout << res << endl;
    }

    return 0;
}