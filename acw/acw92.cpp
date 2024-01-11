#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

// 状态: 0(未选) 1(选) 2(不选)
int used[16]; 

void dfs(int i, int n) {
    // 递归出口
    if (i > n) {
        // 扫描状态
        for (int k = 1; k <= n; k ++) {
            if (used[k] == 1) {
                printf("%d ", k);
            }
        }
        puts("");
        return;
    }

    // 递归左子树
    used[i] = 1;
    dfs(i + 1, n);
    used[i] = 0;

    // 递归右子树
    used[i] = 2;
    dfs(i + 1, n);
    used[i] = 0;
}



int main() {
    for (int i = 1; i < 16; i ++) {
        used[i] = 0;
    }
    
    int n;
    scanf("%d", &n);
    
    dfs(1, n);
    
    return 0;
}