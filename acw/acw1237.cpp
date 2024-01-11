#include <iostream>
using namespace std;
/*找规律可以发现每层的右上角点所需步数为为4k2
求任意一个点的dis首先找到这个点所在的层数

如果在该层的左或上则减去该点到右上角曼哈顿距离，
如果在该层的右或下则加上该点到右上角曼哈顿距离；*/
// int main() {
//     int m,n;
//     cin >> m >> n;
//     long long k = max(abs(m), abs(n));
//     long long res;
//     if (m >= n) res = 4*k*k + abs(m-k) + abs(n-k);
//     else res = 4*k*k - abs(m-k) - abs(n-k);
//     cout << res << endl;
//     return 0;
// }
int main() {
    int x, y;
    cin >> x >> y;
    long long k = max(abs(x), abs(y));
    if (x > y) cout << 4*k*k + (abs(k-x)+abs(k-y));
    else cout << 4*k*k - (abs(k-x)+abs(k-y));
    return 0;
}