// 主要是排列组合字典序字串三个任务
// 体现在used数组不同和扫描used数组下标不同
#include <iostream>
#include <vector>
using namespace std;

// vars
int n = 5;
int m = 3;
int l = 1;
vector<bool> used(n+5,false);
vector<int> st;
vector<int> iused(n+5,0);

// funs
void dfs_a(int u) {
    // 1-5的全排列
    if (u > n) { 
        for (auto c : st) cout << c;
        cout << endl; 
        return;
    } else {
        for (int i=1; i <= n; i ++) {
            if (!used[i]) {
                st.push_back(i);
                used[i] = true;
                dfs_a(u+1);
                st.pop_back();
                used[i] = false;
            }
        }
    }
}

void dfs_b(int u) {
    // 输出1-5的所有字串
    if (u > n) { 
        for (int i=1; i <= n; i ++) {
            if (iused[i] == 1) cout << i;
        }
        cout << endl; 
        return;
    } else {
        // 这里没有循环
        if (iused[u] == 0) {
            iused[u] = 1;
            dfs_b(u+1);
            // 省略iused[i] = 0;
            iused[u] = 2;
            dfs_b(u+1);
            iused[u] = 0;
        }
    }
}


void dfs_c(int u) {
    // 组合Cnm (无意冒犯...)
    if (u > m) { 
        for (auto c : st) cout << c;
        cout << endl; 
        return;
    } else {
        for (int i=l; i <= n; i ++) {
            if (!used[i]) {
                l = i+1;
                st.push_back(i);
                used[i] = true;
                dfs_c(u+1);
                st.pop_back();
                used[i] = false;
            }
        }
    }
}




int main() {
    // dfs_a(1);
    // dfs_b(1);
    return 0;
}