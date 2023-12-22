#include <iostream>
#include <cstdio>
using namespace std;
//输入时将原数组转化成差分数组，
//直接在其上进行差分操作，最后求前缀和得到处理后的原数组
int n, m;
const int N = 100010;
int nums[N];


int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) scanf("%d", &nums[i]);
    // 后一项减前一项
    for (int i = n; i > 0; i --) nums[i] -= nums[i-1];

    while (m --) {
        int l, r, val;
        scanf("%d%d%d", &l, &r, &val);
        // 这里对差分数组的单点修改等价于对原数组的区域修改.
        nums[l] += val;
        nums[r+1] -= val;
    }

    for (int i = 1; i <= n; i ++) nums[i] += nums[i-1];
    for (int i = 1; i <= n; i ++) printf("%d ", nums[i]);
    cout << endl;
    
    return 0;
}