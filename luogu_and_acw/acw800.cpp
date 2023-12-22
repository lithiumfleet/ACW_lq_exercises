#include <iostream>
using namespace std;
const int N = 1010;
int b[N][N];
// 若a是b的前缀和数组,则b是a的差分数组.
// 那么怎么构造差分数组? 答案是一个一个往差分数组里塞数字.

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            int x;
            scanf("%d", &x);
            b[i][j] += x;
            b[i+1][j] -= x;
            b[i][j+1] -= x;
            b[i+1][j+1] += x;
        }
    }

    while (q --) {
        int x1,x2,y1,y2,val;
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&val);
        b[x1][y1] += val;
        b[x2+1][y1] -= val;
        b[x1][y2+1] -= val;
        b[x2+1][y2+1] += val;
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
        }
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    } 


    return 0;
}