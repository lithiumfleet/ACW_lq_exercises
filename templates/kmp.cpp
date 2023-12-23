// 已重写一遍:不能背
// 又写了一遍:注意下标
#include <iostream>
#include <string>

using namespace std;

// 从下标0开始计, 返回匹配位置.
int kmp(string s, string p) {
    int n = s.size(), m = p.size();
    // 特判
    if (m == 0) return 0;
    // 哨兵
    s.insert(s.begin(), ' ');
    p.insert(p.begin(), ' ');
    int next[m+1];
    // get next list
    for (int i=2, j=0; i <= m; i ++) {
        while (j && p[i] != p[j+1]) j = next[j];
        if (p[i] == p[j+1]) j ++;
        next[i] = j;
    }
    
    for (int i=1, j=0; i <= n; i ++) {
        while (j && s[i] != p[j+1]) j = next[j];
        if (s[i] == p[j+1]) j ++;
        if (j == m) return i-m;
    }
    return -1;
}

int main() {
    string a = "sadfghgjtdhsgaf";
    string b = "dhs";
    cout << kmp(a,b) << endl;
    return 0;
}