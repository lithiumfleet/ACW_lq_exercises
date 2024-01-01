#include <iostream>
#include <vector>
using namespace std;

int n;
int used[17];

void dfs(int i) {
    if (i > n) {
        for (int j = 1; j <= n; j ++) {
            if (used[j] == 1) cout << j << " ";
        }
        cout << endl;
    } else {
        if (used[i] == 0) {
            used[i] = 1;
            dfs(i+1);
            used[i] = 2;
            dfs(i+1);
            used[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}