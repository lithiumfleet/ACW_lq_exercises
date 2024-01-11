#include <iostream>
#include <cstdio>

using namespace std;

int used[10], st[9];
int res = 0;
int target;

// 区间中的数值大小
int to_num(int i, int j) {
    int l = i;
    int num = 0;
    while (l <= j) {
        num *= 10;
        num += st[l];
        l ++;
    }
    return num;
}

// 检查分割的三段是否符合要求
void check() {
    for (int i = 0; i < 7; i ++) {
        for (int j = i + 1; j < 8; j ++) {
            int a = to_num(0, i);
            int b = to_num(i + 1, j);
            int c = to_num(j + 1, 8);
            if (a * c + b == target * c) res ++;
        }
    }
}

void dfs(int u) {
    if (u == 9) {
        check();
        return;
    }

    // 全排列模板
    for (int i = 1; i <= 9; i ++) {
        if (used[i] == 0) {
            st[u] = i;
            used[i] = 1;
            dfs(u + 1);
            used[i] = 0;
        }
    }

}

int main() {
    cin >> target;
    dfs(0);
    cout << res << endl;

    return 0;
}