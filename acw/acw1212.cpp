// // 写不了一点
// #include <iostream>

// using namespace std;

// const int N = 55, mod = 1e9+7;

// int n, m, k;
// int w[N][N]; // 存地图
// int dp[N][N][13][14];

// int main() {
//     cin >> n >> m >> k;
//     for (int i = 1; i <= n; i ++) {
//         for (int j = 1; j <= m; j ++) {
//             cin >> w[i][j];
//             w[i][j] ++; // 给特判留位置
//         }
//     }

//     // 初始化条件: 1.取第一个位置 2.不取
//     dp[1][1][1][w[1][1]] = 1;
//     dp[1][1][0][0] = 1;

//     for (int i = 1; i <= n; i ++) {
//         for (int j = 1; j <= m; j ++) {
//             if (i == 1 && j == 1) continue;
//             for (int u = 0; u <= k; u ++) {
//                 // 枚举在当前位置可能取到的max val
//                 for (int v = 0; v <= 13; v ++) {
//                     // 不取当前位置物体, 从左边或者上面转移过来
//                     int &val = dp[i][j][u][v];
//                     val = (val + dp[i-1][j][u][v]) % mod;
//                     val = (val + dp[i][j-1][u][v]) % mod;
//                     // 如果条件满足(u>0并且当前价值等于c), 取当前位置物体
//                     if (u > 0 && v == w[i][j]) {
//                         for (int c = 0; c < v; c ++) {
//                             val = (val + dp[i][j-1][u-1][c]) % mod;
//                             val = (val + dp[i-1][j][u-1][c]) % mod;
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     int res = 0;
//     for (int i = 0; i <= 13; i ++) {
//         res = (res + dp[n][m][k][i]) % mod;
//     }
//     cout << res << endl;
//     return 0;
// }

#include <iostream>
using namespace std;
int map[55][55];
const int mod = 1000000007;
int dp[55][55][14][14];
// 子问题: 不拿 / 有条件拿
// dp[i][j][cnt][maxv] 在第i,j位置,手上有cnt件物品,拿完之后手上最大价值是maxv(可枚举)



int main() {
    int n, m, K;
    cin >> n >> m >> K;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> map[i][j];
            map[i][j] ++;
        }
    }

    // 初始化
    dp[1][1][0][0] = 1;
    dp[1][1][1][map[1][1]] = 1;

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) { // j <= m找了40min...以后记得直接用ac代码适配然后删减debug
            if (i == 1 && j == 1) continue;
            for (int k = 0; k <= K; k ++) {
                for (int v = 0; v <= 13; v ++) {
                    // 不拿
                    int &val = dp[i][j][k][v];
                    val = (val + dp[i-1][j][k][v]) % mod;
                    val = (val + dp[i][j-1][k][v]) % mod;
                    // 看条件拿
                    if (k>0 && v == map[i][j]) {
                        for (int c = 0; c < v; c ++) {
                            val = (dp[i-1][j][k-1][c] + val) % mod;
                            val = (dp[i][j-1][k-1][c] + val) % mod;
                        }
                    }
                }
            }
        }
    }

    int res = 0;
    for (int i = 0; i <= 13; i ++) {
        res = (res + dp[n][m][K][i]) % mod;
    }
    cout << res << endl;


    return 0;
}