// 本题在acw上记为1240,实际上是1242
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 100010;
int a[N];
int n;

int main() {
    // 读取
    cin >> n;
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);

    // 初始化边界
    long long maxs = -1e18;
    int depth = 0;
    
    // 循环, d为层数, i为到目前为止节点数量
    for (int d = 1, i = 1; i <= n; i *= 2, d ++) {
        // 本层val
        long long s = 0;
        // 完全二叉树: 当前层节点数量=(1<<d) d从0开始
        for (int j = i; j < i + (1 << d-1) && j <= n; j ++) s += a[j];
        // 判断
        if (s > maxs) {
            maxs = s;
            depth = d;
        }
    }
    cout << depth << endl;

    return 0;
}

// #include <iostream>

// using namespace std;

// const int N = 100010;
// int a[N];
// int main() {
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);

//     long long maxs = -1e18;
//     int depth = 0;
//     for (int d = 1, i = 1; i <= n; i *= 2, d ++) {
//         long long s = 0;
//         for (int j = i; j < i+(1<<d-1) && j <= n; j ++) s += a[i]; // tm找了一个小时
//         if (s > maxs)  {
//             maxs = s;
//             depth = d;
//         }
//     }
//     cout << depth << endl;
//     return 0;
// }