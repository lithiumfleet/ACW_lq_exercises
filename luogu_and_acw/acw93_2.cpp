#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 30;
bool used[N];
vector<int> st;
int m,n,l=1;

void dfs(int u) {
    if (u > n) {
        for (auto i : st) cout << i << " ";
        cout << endl;
    } else {
        for (int i=l; i <= m; i ++) {
            if (!used[i]) {
                l = i+1; // 没想出来,这里保证不选回头数
                st.push_back(i);
                used[i] = true;
                dfs(u + 1);
                st.pop_back();
                used[i] = false;
            }
        }
    }
}

int main() {
    cin >> m >> n;
    memset(used, false, sizeof used);
    dfs(1);
    return 0;
}