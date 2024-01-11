// 记得重写一遍
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 2500010;
struct Sum {
    int c, d, s;
    // 重载<使two_square_sums[N]有序
    bool operator< (const Sum &t) const {
        if (t.s != s) return s < t.s;
        if (t.c != c) return c < t.c;
        return d < t.d;
    }

}two_square_sums[N];

int m = 0, n;

int main() {
    cin >> n;
    for (int c = 0; c*c <= n; c ++) {
        for (int d = c; c*c+d*d <= n; d ++) {
            two_square_sums[m ++] = {c, d, c*c+d*d};
        }
    } 
    sort(two_square_sums, two_square_sums+m);

    for (int a = 0; a*a < n; a ++) {
        for (int b = a; a*a+b*b < n; b ++) {
            // 这里的二分操作代替了哈希表
            int l = 0, r = m-1;
            int target = n - a*a - b*b;
            while (l < r) {
                int mid = l + r >> 1;
                if (two_square_sums[mid].s >= target) r = mid;
                else l = mid + 1;
            }
            // 有多个答案时输出字典序最小的, 然后直接退出.
            if (two_square_sums[l].s == target) {
                int c = two_square_sums[l].c;
                int d = two_square_sums[l].d;
                printf("%d %d %d %d\n", a, b ,c, d);
                return 0;
            }
        }
    }
    return 0;
}