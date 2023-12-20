#include <iostream>

using namespace std;
const int N = 1005;
int nums[N];
// 1,r间最长子序列
int dp[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> nums[i]; 
    }

    int res = 0;
    // 枚举最右边位置i
    for (int i = 1; i <= n; i ++) {
        dp[i] = 1;
        for (int j = 1; j < i; j ++) {
            // i符合条件的情况下, 选i和不选i
            if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }
    cout << res << endl;
    return 0;
}

// #include <iostream>
// using namespace std;
// const int N = 1005;
// // 子问题: 从i到j区间中的最大长度(虽然但是可以改成一维dp)
// int nums[N];
// long long dp[N][N];
// // 子问题最优解: max(枚举每个位置k, 检查可不可以带nums[j])

// int main() {
//     int n; cin >> n;
//     for (int i = 1; i <= n; i ++) {
//         cin >> nums[i];
//     }

//     for (int i = 1; i <= n; i ++) {
//         for (int j = i; j <= n; j ++) {
//             dp[i][j] = 1;
//             for (int k = i; k < j; k ++) {
//                 if (nums[k] < nums[j]) {
//                     dp[i][j] = max(dp[i][j], dp[i][k]+1);
//                 }
//             }
            
//         }
//     }

//     long long res = 0;
//     for (int i = 1; i <= n; i ++) {
//         // 如果是二维dp的话, 答案可能是在dp[i][j]里面.
//         for (int j = 1; j <= n; j ++) {
//             res = max(res, dp[1][i]);
//         }
//     }
//     cout << res << endl;
    
//     return 0;
// }