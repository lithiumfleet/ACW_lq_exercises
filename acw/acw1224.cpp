#include <iostream>
#include <cstdio>

using namespace std;
const int N = 10010;
int t[N];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) scanf("%d", &t[i]);
    
    int res = 0;
    for (int i = 1; i <= n; i ++) {
        // 每个离开自己位置的数字都属于某个组, 这个组内一定可以互相交换而不影响其他数字.
        // 从这个点出发直接交换, 一定可以回到原来位置.
        while (t[i] != i)
        {
            swap(t[i], t[t[i]]);
            res ++;
        }
    }
    
    cout << res << endl;
    
    return 0;
}