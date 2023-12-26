// 戳气球同款问题
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<double, double> pdd;
const int N = 1010;

int n, d; 
pdd seg[N];

int main() {
    cin >> n >> d;
    bool success = true;
    for (int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        if (y > d) {
            success = false;
            break;
        }
        double len = sqrt(d*d - y*y);
        seg[i] = {x+len, x-len};
    }

    if (!success) cout << "-1" << endl;
    else {
        sort(seg, seg+n);
        int res = 0;
        double last = -1e10;
        // 贪心, 只在气球右端点扎针
        for (int i = 0; i < n; i ++) {
            if (seg[i].second > last) {
                res ++;
                last = seg[i].first;
            }
        }
        cout << res << endl;
    }

    return 0;
}