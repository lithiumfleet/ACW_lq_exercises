#include <iostream>

using namespace std;
const int N = 10010;
int nums[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> nums[i];
    }

    int res = 0;
    for (int i = 1; i <= n; i ++) {
        int Max = nums[i];
        int Min = nums[i];
        for (int j = i; j <= n; j ++) {
            Max = max(Max, nums[j]);
            Min = min(Min, nums[j]);
            if (Max - Min == j - i) res ++;
        }
    }
    cout << res << endl;
    return 0;
}