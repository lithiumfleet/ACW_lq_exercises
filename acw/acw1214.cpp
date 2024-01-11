// 没懂
#include <iostream>
using namespace std;
const int N = 1010;
int dp[N][N];
const int mod = 1e9+7;
int xmody(int x, int y) {
    return (x % y + y) % y;
}
int main() {
    int n, s, a, b;
    cin >> n >> s >> a >> b;
    dp[0][0] = 1;
    for (int i = 1; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            dp[i][j] = (dp[i-1][xmody(j-a*(n-i),n)] + dp[i-1][xmody(j+b*(n-i),n)]) % mod;
        }
    }

    return 0;
}