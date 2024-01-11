#include <iostream>
#include <vector>
using namespace std;

const int N = 100010;
vector<int> nums(N);
int n, q;

int main() {
    nums[0] = -1;
    cin >> n >> q;
    for (int i=1; i <= n; i ++) cin >> nums[i];
    nums[n+1] = 10005;
    while (q --) {
        int target; cin >> target;
        int ansl=0, ansr=0;
        int l=0, r=n+1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (nums[l] != target) {
            cout << -1 << " " << -1 << endl;
            continue;
        }
        ansl = l-1;
        r = n+1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        ansr = l-1;
        cout << ansl << " " << ansr << endl;
    }
    return 0;
}