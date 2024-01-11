// 写写注释....
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int n;
int used[10];
int cnt;
vector<int> st;

void dfs(int i) {
    // 递归出口: 选位置到n了
    if (i > n) {
        for (int k = 0; k < n; k ++) {
            printf("%d ", st[k]);
        }
        printf("\n");
        return;
    }

    // FIXME: 位运算状压?? //&& cnt == (cnt&-cnt)
    for (int j = 1; j <= n; j ++) {
        if (used[j] == 0 ) { 
            used[j] = 1;
            // cnt ^= (1 << j);
            st.push_back(j);
            dfs(i + 1); 
            used[j] = 0;
            // cnt ^= (1 << j);
            st.pop_back();
        }
    }
}

int main() {
    for (int i = 0; i < 10; i ++) {
        used[i] = 0;
    }
    // scanf("%d", &n);
    n = 3;
    cnt = 0;

    dfs(1);

    return 0;
}