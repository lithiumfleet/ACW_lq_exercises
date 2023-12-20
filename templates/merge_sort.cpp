#include <iostream>
#include <cstdio>

using namespace std;
int help[100010];

void merge_sort(int l, int r, int nums[]) {
    // 边界
    if (l >= r) return;
    // 递归
    int mid = l + r >> 1;
    merge_sort(l, mid, nums), merge_sort(mid+1, r, nums);
    // 有序填入help数组
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (nums[i] <= nums[j]) help[k++] = nums[i++];
        else help[k++] = nums[j++];
    }
    // 把剩下的填完
    while (i <= mid) help[k++] = nums[i++];
    while (j <= r) help[k++] = nums[j++];
    // 利用help数组更新原数组的[l,r]
    for (int i = l, j = 0; i <= r; i ++, j ++) nums[i] = help[j];
}

int main() {
    int n; cin >> n;
    int nums[n+10];
    for (int i = 1; i <= n; i ++) scanf("%d", &nums[i]);
    merge_sort(1, n, nums);

    return 0;
}