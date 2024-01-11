#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

// l 是选数的左边界
int N, M, l;
int used[25];
vector<int> st;

// 枚举第u个位置
void dfs(int u) {
    if (u > M) {
        for (int i : st) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    for (int i = l; i <= N; i ++) {
        if (used[i] == 0) {
            // 保证每次不选回头数
            l = i+1;
            used[i] = 1;
            st.push_back(i);
            dfs(u+1);
            st.pop_back();
            used[i] = 0;
        }
    }
}

int main() {
    cin >> N >> M;
    // 初始化选数左边界l为1
    l = 1;
    dfs(1);
    return 0;
}

// 学学y总的代码
// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #include <algorithm>

// using namespace std;

// const int N = 30;

// int n, m;
// int way[N];

// void dfs(int u, int start)
// {
//     if (u + n - start < m) return;  // 剪枝
//     if (u == m + 1)
//     {
//         for (int i = 1; i <= m; i ++ ) printf("%d ", way[i]);
//         puts("");
//         return;
//     }

//     for (int i = start; i <= n; i ++ )
//     {
//         way[u] = i;
//         dfs(u + 1, i + 1);
//         way[u] = 0; // 恢复现场
//     }
// }

// int main()
// {
//     scanf("%d%d", &n, &m);

//     dfs(1, 1);

//     return 0;
// }