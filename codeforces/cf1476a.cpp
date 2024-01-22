#include <iostream>
using namespace std;

int q;
int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin >> q;
    while (q--) {
        cin >> n >> k;
        int c = n / k;
        if (n % k != 0) c += 1;
        int sum = k*c; // 找到第一个大于等于k的sum
        if (sum % n == 0) cout << sum / n << endl;
        else cout << sum/n + 1 << endl;
    }
    return 0;
}