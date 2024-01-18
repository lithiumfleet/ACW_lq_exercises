// dp写不了一点
#include <iostream>
using namespace std;

int n,m,res;
int dp[31][31]; // dp[i][j]: 第i次传球, 第j个人手里的方法数量

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;

    dp[0][1] = 1;
    for (int i=1; i <= m; i ++) {
        // 传i次球, 更新i次
        
        for (int j=1; j <= n; j ++) {
            // 对1和n特判
            if (j == 1) dp[i][j] = dp[i-1][n] + dp[i-1][2];
            else if (j == n) dp[i][j] = dp[i-1][1] + dp[i-1][n-1];
            // 递推
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
        }

    }
    cout << dp[m][1] << endl;
    return 0;
}