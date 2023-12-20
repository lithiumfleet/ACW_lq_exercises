// 递归搜索树的实现
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int n;
vector<int> state;
vector<bool> used;

// 对第u位填入数字
void dfs(int u) {
    // 递归出口
    if (u >= n) {
        for (size_t i=0; i<state.size(); i++) {
            printf("%d ",state[i]);
        }
        puts(""); // 打印空行
    }

    for (int i=0; i<n; i++) { // 扫描used数组
        if (!used[i]) {
            state.push_back(i+1);
            used[i] = true;
            dfs(u+1);
            state.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    scanf("%d", &n);
    used.assign(n,false);
    dfs(0);
    return 0;
}