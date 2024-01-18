#include <iostream>
#include <string>
using namespace std;

int n;
string op;

int main() {
    cin >> n;
    int res = 0;
    while (n --) {
        cin >> op;
        if (op[1] == '-') res --;
        else res ++;
    }
    cout << res << endl;
    return 0;
}