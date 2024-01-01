#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
char map[6][6];
char bak[6][6];

bool in_bound(int x) {
    return x >= 0 && x < 5;
} 

// 模拟开关操作
void turn(int x, int y) {
    int need[5][2] = {x,y-1,x-1,y,x,y,x+1,y,x,y+1};
    for (int i = 0; i < 5; i ++) {
        if (in_bound(need[i][0]) && in_bound(need[i][1])) {
            map[need[i][0]][need[i][1]] ^= 1; // ascii中对'1''0'异或运算成立
        }
    }
}

// 每一行仅被下面一行影响, 递推更新全局.
int update() {
    int step = 0;
    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < 5; j ++) {
            if (map[i][j] == '0') {
                turn(i + 1, j);
                step ++;
            }
        }
    }
    return step;
}

bool all_lit() {
    for (int i = 0; i < 5; i ++) {
        if (map[4][i] == '0') {
            return false;
        }
    }
    return true;
}

int main() {
    int q;
    cin >> q;
    // res初始值大于6
    while (q --) {
        // 读取
        for (int i = 0; i < 5; i ++) cin >> map[i];
        int res = 100;
        for (int op = 0; op < 32; op ++) {
            memcpy(bak, map, sizeof map);
            int step = 0;
            // 枚举第一行
            for (int i = 0; i < 5; i ++) {
                // op为5位二进制串
                if (op >> i & 1) {
                    step ++;
                    turn(0,i);
                }
            }

            step += update();

            if (all_lit()) {
                res = min(res, step);
            }

            // bug点: 如果把判断res的步骤放在这里的话就会出现res=-1; res=min(res,step);的情况
            // if (res > 6) res = -1;

            memcpy(map, bak, sizeof bak);
        }
        if (res > 6) res = -1;
        cout << res << endl;
    }
    return 0;
}
// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #include <algorithm>

// using namespace std;

// const int N = 6;

// char g[N][N], backup[N][N];

// bool in_bound(int x) {
//     return x >= 0 && x < 5;
// } 

// void turn(int x, int y) {
//     int need[5][2] = {x,y-1,x-1,y,x,y,x+1,y,x,y+1};
//     for (int i = 0; i < 5; i ++) {
//         if (in_bound(need[i][0]) && in_bound(need[i][0])) {
//             g[need[i][0]][need[i][1]] ^= 1; // ascii中对'1''0'异或运算成立
//         }
//     }
// }

// bool all_lit() {
//     for (int i = 0; i < 5; i ++) {
//         if (g[4][i] == '0') {
//             return false;
//         }
//     }
//     return true;
// }

// // 每一行仅被下面一行影响, 递推更新全局.
// int update() {
//     int step = 0;
//     for (int i = 0; i < 4; i ++) {
//         for (int j = 0; j < 5; j ++) {
//             if (g[i][j] == '0') {
//                 turn(i + 1, j);
//                 step ++;
//             }
//         }
//     }
//     return step;
// }

// int main()
// {
//     int T;
//     cin >> T;
//     while (T -- )
//     {
//         for (int i = 0; i < 5; i ++ ) cin >> g[i];

//         int res = 10;
//         for (int op = 0; op < 32; op ++ )
//         {
//             memcpy(backup, g, sizeof g);
//             int step = 0;
//             for (int i = 0; i < 5; i ++ )
//                 if (op >> i & 1)
//                 {
//                     step ++ ;
//                     turn(0, i);
//                 }

//             step += update();

//             bool light = all_lit();

//             if (light) res = min(res, step);
//             memcpy(g, backup, sizeof g);
//         }

//         if (res > 6) res = -1;

//         cout << res << endl;
//     }

//     return 0;
// }