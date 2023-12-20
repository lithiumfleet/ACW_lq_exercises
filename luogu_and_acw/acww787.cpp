// 写不了一点
#include <iostream>
#include <cstdio>

using namespace std;
int n;
const int N = 100010;
int nums[N], help[N];

void srt(int l, int r) {
    if (l >= r) return;
    int mid = l + r >> 1;
    srt(l, mid);
    srt(mid+1, r);
    // 双指针i,j
    int i = l;
    int j = mid + 1;
    int k = 0;
    // 在归并数组没用完之前进行合并操作
    while (i <= mid && j <= r) {
        if (nums[i] < nums[j]) help[k++] = nums[i++];
        else help[k++] = nums[j++];
    }
    // 把剩下的数组并进去
    while (i <= mid) help[k++] = nums[i++];
    while (j <= r) help[k++] = nums[j++];
    // help数组用到k=i+j个空间,填回到nums[i:r]区间内
    for (int i = l, k = 0; i <= r; i ++, k ++) nums[i] = help[k];
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        scanf("%d", &nums[i]);
    }
    srt(0, n-1);
    for (int i = 0; i < n; i ++) printf("%d ", nums[i]);
    return 0;
}