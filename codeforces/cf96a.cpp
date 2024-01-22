#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int cnt1 = 1;
    int cnt0 = 1;
    string in;
    cin >> in;
    for (char c : in) {
        if (cnt0 > 7 || cnt1 > 7) { break; }
        if (c == '0') {
            cnt0 ++;
            cnt1 = 1;
        } else {
            cnt1 ++;
            cnt0 = 1;
        }
    }
    if (cnt0 > 7 || cnt1 > 7) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}