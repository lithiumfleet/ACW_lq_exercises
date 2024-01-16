#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int x, prex;
    int cnt = 0;
    while (n --) {
        prex = x;
        cin >> x;
        if (cnt >= k && prex != x) break;
        if (x == 0) { cout << cnt << endl; return 0; }
        cnt ++;
    }
    cout << cnt << endl;
    return 0;
}