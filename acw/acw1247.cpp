#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i ++) {
        int x = i;
        while (x) {
            int t = x % 10;
            x /= 10;
            if (t == 2 || t == 0 || t == 1 || t == 9) {
                res += i;
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}
