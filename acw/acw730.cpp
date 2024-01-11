#include <iostream>
#include <cstdio>

using namespace std;
const int N = 1e5+5;
int h[N];
int n;

// check函数: 递推式就是m*2-h[i]
bool check(int m) {
    for (int i = 1; i <= n; i ++) {
        m = 2 * m - h[i];
        if (m < 0) return false;
        if (m >= N) return true;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", h + i);
    }

    int l = 0, r = N;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", r);
    return 0;
}