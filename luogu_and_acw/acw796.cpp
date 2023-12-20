#include <iostream>
#include <cstdio>

using namespace std;
int n, m, q;
const int N = 1005;

int nums[N][N];

int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> nums[i][j];
        }
    }

    for (int i = 2; i <= n; i ++) {
        nums[i][1] += nums[i-1][1];
    }
    for (int j = 2; j <= m; j ++) {
        nums[1][j] += nums[1][j-1];
    }
    for (int i = 2; i <= n; i ++) {
        for (int j = 2; j <= m; j ++) {
            nums[i][j] += nums[i-1][j] + nums[i][j-1] - nums[i-1][j-1];
        }
    }

    while (q --) {
        int a, b, c, d;
        cin >> a >> b >> c >>d;
        cout << nums[c][d] - nums[a-1][d] - nums[c][b-1] + nums[a-1][b-1] << endl;
    }

    return 0;
}