// 终于tm过了
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int A[N], B[N], C[N];
int n;

int lcnt(int* nums, int target) {
    int l = 0;
    int r = n+1;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (nums[mid] < target) l = mid;
        else r = mid - 1;
    }
    return l;
}

int rcnt(int *nums, int target) {
    int l = 0;
    int r = n+1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (nums[mid] > target) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i ++) scanf("%d", &B[i]);
    for (int i = 1; i <= n; i ++) scanf("%d", &C[i]);
    A[n+1] = 1e5+5;
    C[n+1] = 1e5+5;

    sort(A, A+n+1);
    sort(C, C+n+1);

    // 枚举B
    long long res = 0;
    for (int j = 1; j <= n; j ++) {
        // 转二分
        int resa = lcnt(A, B[j]);
        int resc = n-rcnt(C, B[j])+1;
        if (resa == 0) resa = 0;
        if (resc == n+1) resc = 0;
        res += (long long)resa * (long long)resc;
    }
    cout << res << endl;

    return 0;
}