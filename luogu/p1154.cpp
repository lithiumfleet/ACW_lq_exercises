#include <iostream>
using namespace std;

int n;
int g[5005];
bool dif[1000001];

void mark() {
    for (int i=1; i <= n; i ++) {
        for (int j=1; j <= n; j ++) {
            dif[abs(g[i]-g[j])] = true;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i <= n; i ++) cin >> g[i];

    mark();
    
    for (int i=1; i < 1000001; i ++) {
        bool pass = true;
        for (int j=i; j < 1000001; j += i) {
            if (dif[j]) {
                pass = false;
                break;
            }
        }
        if (pass) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}