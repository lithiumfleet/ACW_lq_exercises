#include <iostream>
using namespace std;

const int N = 6;
int g[N][N];

int main() {
    int r, c;
    for (int i=1; i <= 5; i ++) {
        for (int j=1; j <= 5; j ++) {
            cin >> g[i][j];
            if (g[i][j] == 1) r = i, c = j;
        }
    }
    cout << abs(r-3)+abs(c-3) << endl;
    return 0;
}