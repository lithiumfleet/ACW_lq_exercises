// #include <iostream>

// using namespace std;
// const int N = 1010;
// int weight[N], value[N];
// int dp[N][N];

// int main() {
//     int n, v;
//     cin >> n >> v;
//     for (int i = 1; i <= n; i ++) {
//         cin >> weight[i] >> value[i];
//     }
//     for (int i = 1; i <= n; i ++) {
//         for (int j = 0; j <= v; j ++) {
//             dp[i][j] = dp[i-1][j];
//             if (j >= weight[i]) {
//                 dp[i][j] = max(dp[i][j], dp[i-1][j-weight[i]] + value[i]);
//             }
//         }
//     }
//     cout << dp[n][v] << endl;
//     return 0;
// }

#include <iostream>
using namespace std;
const int N = 1005, V = 1005;
int dp[N][V]; // dp[i][j] 属性是总价值, i是第i次选择, j是剩余容量.
int wei[N], val[N];
// dp[i][j] = max(枚举j和不拿)

int main() {
    int n, v;
    cin >> n >> v;
    for (int i = 1; i <= n; i ++) {
        cin >> wei[i] >> val[i];
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= v; j ++) {
            dp[i][j] = dp[i-1][j];
            if (j >= wei[i]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-wei[i]] + val[i]);
            }
        }
    }

    int res = 0;
    for (int i = 0; i <= v; i ++) {
        res = max(dp[n][i], res);
    }
    cout << res << endl;

    return 0;
}