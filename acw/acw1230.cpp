// 重写, 没写明白
#include <iostream>

using namespace std;

int n, k;
const int N = 1e5+10;
int s[N];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) {
        cin >> s[i];
        s[i] += s[i-1];
    }

    int res = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = i; j <= n; j ++) {
            long long cur = s[j] - s[i-1];
            if (cur % k == 0) res ++;
        }
    }
    cout << res << endl;
    return 0;
}