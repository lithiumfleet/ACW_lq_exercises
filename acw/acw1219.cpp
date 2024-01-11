#include <iostream>

using namespace std;
const int N = 10005;
int w;

int getx(int m) {
    return m / w;
}

int gety(int m) {
    if ((m / w) % 2 == 0) return m % w;
    else return w - m % w - 1; 
}

int main() {
    int m, n;
    cin >> w >> m >> n;
    m --;
    n --;
    int dis = abs(getx(m) - getx(n)) + abs(gety(m) - gety(n));
    cout << dis << endl;
    return 0;
}