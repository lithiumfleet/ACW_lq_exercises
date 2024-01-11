#include <iostream>
#include <string>
#include <cmath>
using namespace std;

char s[100010];
int cnt = 0;

void show(int n) {
    int a = 0, b = 0;
    for (int i=0; i < cnt; i ++) {
        if (s[i] == 'W') a ++;
        if (s[i] == 'L') b ++;
        if ((a>=n || b>=n) && abs(a-b)>=2) {
            cout << a << ":" << b << endl;
            a = b = 0;
        }
    }
    cout << a << ":" << b << endl;
}


int main() {
    char c;
    while (cin >> c && c != 'E') {
        if (c == 'W' || c == 'L') s[cnt ++] = c;
    }
    
    show(11);
    cout << endl;
    show(21);

    return 0;
}