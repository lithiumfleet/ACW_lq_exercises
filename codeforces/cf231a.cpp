#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int res = 0;
    while (n --) {
        int a=0, b;
        cin >> b; a += b;
        cin >> b; a += b;
        cin >> b; a += b;
        if (a >= 2) res ++;
    }
    cout << res << endl;
    return 0;
}