#include <iostream>
#include <string>
using namespace std;

// vars
string src, dest;
int res = 0;

// funs
void turn_coin(int i) { if (src[i] == 'o') src[i] = '*'; else src[i] = 'o'; }
void turn(int i) {
    // 只反转右边的硬币i
    turn_coin(i-1); turn_coin(i); 
}

void simulate() {
    for (int i=1; i < src.size(); i ++) {
        if (src[i-1] != dest[i-1]) {
            turn(i);
            res ++;
        }
    }
}

int main() {
    cin >> src >> dest;
    simulate();
    cout << res;

    return 0;
}