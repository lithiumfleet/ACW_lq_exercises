#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

vector<string> map = {
    "                    ",
    "  +++ +             ",
    "  +++++++           ",
    "   ++   +           ",
    "       +++          ",
    "        +           ",
    "        +           ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    "
};
vector<string> newmap(map);
int dx[] = {1,1,1,0,0,-1,-1,-1};
int dy[] = {1,0,-1,1,-1,1,0,-1};

inline int limit(int x, int maxi) {
    if (x < 0) return x % maxi + maxi;
    return x % maxi;
}

int main() {
    while (true)
    {
        for (int i = 0; i < map.size(); i ++) {
            for (int j = 0; j < map[0].size(); j ++) {
                int cnt = 0;
                for (int n = 0; n < 8; n ++) {
                    int x = limit(i+dx[n],map.size()), y = limit(j+dy[n], map[0].size());
                    if (map[x][y] == '+') cnt ++;
                }
                if (map[i][j] == '+' && cnt < 2 || cnt > 3) newmap[i][j] = ' ';
                if (map[i][j] == ' ' && cnt >= 3) newmap[i][j] = '+';
            }
        }
        system("cls");
        for (int i = 0; i < map.size(); i ++) {
            cout << newmap[i] << endl;
        }
        map.assign(newmap.begin(),newmap.end());
        system("powershell sleep 0.5 > null");
    }
    return 0;
}