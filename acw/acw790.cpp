#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    double n; // 1e-8比float精度高
    scanf("%lf", &n); // "%lf"表示double (long float)
    
    double l = -10000, r = 10000; // 考虑到答案可能在[0,n]外面(比如0.001 -> 0.1), 所以初始化为大区间
    while (r - l > 1e-8) {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= n) r = mid;
        else l = mid; // 靠差值控制终止, 所以不用考虑增量.
    }
    printf("%lf", r);
    return 0;
}