#include <iostream>
#include <cstdio>

using namespace std;
const int N = 100000;
int nums[N];
int presum[N];
int n, m;

void init_presum() {
    presum[0] = nums[0];
    for (int i = 1; i < n; i ++) {
        presum[i] = presum[i-1] + nums[i];
    }
}

void search(int l, int r) {
    printf("%d\n", presum[r] - presum[l-1]); // 注意这里的减一, 求闭区间上的和.
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &nums[i]);
    }
    init_presum();

    while (m --) {
        int l, r;
        scanf("%d%d", &l, &r);
        search(l - 1, r - 1);
    }

    return 0;
}