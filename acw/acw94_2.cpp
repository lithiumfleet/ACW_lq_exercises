#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> st;
bool used[15];

void dfs(int x) {
    if (x > n) {
        for (int i = 0; i < st.size(); i ++) cout << st[i] << " ";
        cout << endl;
    } else {
        for (int i = 1; i <= n; i ++) {
            if (!used[i]) {
                used[i] = true;
                st.push_back(i);
                dfs(x+1);
                st.pop_back();
                used[i] = false;
            }
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}