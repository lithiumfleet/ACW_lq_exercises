#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

char g[105][105];
int m, n;
int cnt = 0;
int dx[] = {0,0, 1,1,1, -1,-1,-1};
int dy[] = {1,-1,-1,0,1, -1,0,1};

int main() {
    scanf("%d %d\n", &m, &n);
    for (int i=0; i < m; i ++) {
        cin >> g[i];
    }

    for (int i=0; i < m; i ++) {
        for (int j=0; j < n; j ++) {
            char out;

            if (g[i][j] == '?') {
                int boom = 0;

                for (int d=0; d < 8; d ++) {
                    int x = i+dx[d], y = j+dy[d];
                    if (x>=0 && y>=0 && x<m && y<n) {
                        if (g[x][y] == '*') {
                            boom ++;
                        }
                    }
                }

                out = '0' + boom;
            } else {
                out = g[i][j];
            }
            printf("%c", out);
        }
        printf("\n");
    }

    return 0;
}