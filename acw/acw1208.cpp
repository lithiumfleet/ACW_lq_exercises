#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;
string src, dest;

void turn(int i) {
    if (src[i] == '*') src[i] = 'o';
    else src[i] = '*';
    if (src[i+1] == '*') src[i+1] = 'o';
    else src[i+1] = '*';
}

int main() {
    cin >> src >> dest;
    int ans = 0;
    for (int i = 0; i < src.size()-1; i ++) {
        if (src[i] != dest[i]) {
            turn(i);
            ans ++;
        }
    }
    cout << ans;
    return 0;
}