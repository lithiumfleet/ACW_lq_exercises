#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int n,q;
const int N = 100000;
int nums[N];


int main() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &nums[i]);
    }

    int target;
    int resl, resr;
    for (int j = 0; j < q; j ++) {
        scanf("%d", &target);
        // 先找答案的左端点, 也就是右区间(的左)端点
        int l = 0, r = n-1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }

        if (nums[r] != target) {
            printf("-1 -1\n");
            continue;
        } else {
            resl = r;
            // 再找答案的右端点, 也就是左区间(的右)端点
            l = resl;
            r = n - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (nums[mid] <= target) l = mid;
                else r = mid - 1;
            }
            resr = l;
        }
        printf("%d %d\n", resl, resr);
    }
    
    return 0;
}