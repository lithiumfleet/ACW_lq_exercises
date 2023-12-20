#include <iostream>
#include <cstdio>

using namespace std;
int n, k;
const int N = 1e5;
int p[N][2];

bool check(int mid) {
    int cnt = 0;
    for (int i = 0; i < n; i ++) {
        // 统计块数, 比k大就行
        cnt += (p[i][0] / mid) * (p[i][1] / mid);
        if (cnt >= k) return true;
    }
    // 总块数比k还小, 证明切出的小巧克力块边长大了, 答案该向右移
    return false;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i ++) {
        cin >> p[i][0] >> p[i][1];
    }

    int l = 1, r = 1e5;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;

    return 0;
}