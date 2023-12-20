#include <iostream>

using namespace std;
// 测试数组, 加入了边界, 所以真实数组为nums[1:20]左闭右开
int nums[21] = {INT_MIN,1,2,3,4,5,6,7,8,9,10,10,10,10,10,10,16,17,18,19,INT_MAX};

void lsearch(int *a, int target) {
    int l = 0;
    int r = 21;
    while (l < r) {
        int mid = l + r >> 1;
        if (nums[mid] > target) r = mid; // r = mid: 从右往左数, 最后一个满足该条件的位置
        else l = mid + 1;                // l = mid: 从左往右数, 最后一个满足该条件的位置
    }
    // l == r
    printf("l=%d r=%d\n%d   %d\n", l, r, nums[l], nums[r]);
}

int main() {
    while (1) {
        int t; cin >> t;
        lsearch(nums, t);
    }
    return 0;
}