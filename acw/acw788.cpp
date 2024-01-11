#include <iostream>
#include <cstdio>

using namespace std;
int help[100010];
long long res = 0;

void merge_sort(int l, int r, int nums[]) {
    // 边界
    if (l >= r) return;
    int mid = l + r >> 1;
    merge_sort(l, mid, nums), merge_sort(mid+1, r, nums);
    // 有序填入help数组
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (nums[i] <= nums[j]) {
            help[k++] = nums[i++];
        } else {
            res += mid - i + 1;
            help[k++] = nums[j++];
        }
    }
    // 填入剩下的数组
    while (i <= mid) help[k++] = nums[i++];
    while (j <= r) help[k++] = nums[j++];
    // 利用help数组更新原数组的l,r
    for (int i = l, j = 0; i <= r; i ++, j ++) nums[i] = help[j];
}
// void merge_sort(int l, int r, int nums[])
// {
//     if (l >= r) return;
//     int mid = l + r >> 1;
//     merge_sort(l, mid, nums), merge_sort(mid + 1, r, nums);
//     int i = l, j = mid + 1,k = 0;

//     while (i <= mid && j <= r)
//     {
//         if (nums[i] <= nums[j])
//         {
//             help[k ++] = nums[i ++];
//         }
//         else
//         {
//             res += mid - i + 1;
//             help[k ++] = nums[j ++];
//         }
//     }

//     while (i <= mid) help[k ++] = nums[i ++];
//     while (j <= r) help[k ++] = nums[j ++];

//     for (int i = l, j = 0; i <= r; i ++, j ++) nums[i] = help[j];
// }


int main() {
    int n; cin >> n;
    int nums[n];
    for (int i = 0; i < n; i ++) scanf("%d", &nums[i]);
    merge_sort(0, n-1, nums);
    cout << res << endl;

    return 0;
}