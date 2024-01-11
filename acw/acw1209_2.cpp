#include <iostream>
#include <vector>
using namespace std;

vector<int> st;
bool used[10];
int res = 0;
int n;

// 分3段求和

// 求左闭右开的区间和
int sum(int l, int r) {
    int s = 0;
    for (int i=l; i < r; i ++) {
        s *= 10;
        s += st[i];
    }
    return s;
}

bool check() {
    // 区间求和写不对了...注意边界
    for (int i=1; i<8; i ++) {
        for (int j=i+1; j<9; j ++) {
            int a = sum(0,i);
            int b = sum(i,j);
            int c = sum(j,9);
            // if (n * c == a * c + b) return true;
            printf("%d %d %d", a, b, c);
        }
    }
    return false;
}


void dfs(int u) {
    if (u > 9) {
        if (check()) res ++;
        // for (auto c : st) cout << c;
        // cout << endl;
        return;
    } else {
        for (int i=1; i<=9; i ++) {
            if (!used[i]) {
                st.push_back(i);
                used[i] = true;
                dfs(u+1);
                st.pop_back();
                used[i] = false;
            }
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    cout << res << endl;
    // st = {1,2,3,4,5,6,7,8,9};
    // check();
    return 0;
}