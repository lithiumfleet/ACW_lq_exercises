#include <iostream>
#include <string>
using namespace std;

int comp(string a, string b) {
    if (a.size() > b.size()) return 1;
    else if (a.size() == b.size()) return 0;
    else return 0;
}

string add(string str1, string str2) {
    int len1 = str1.size(), len2 = str2.size();
    // 补0
    if (len1 < len2) str1 = string(len2-len1,'0') + str1;
    else str2 = string(len1-len2,'0') + str2;
    len1 = str1.size(), len2 = str2.size();

    int cf=0; // 进位
    int temp;
    string ans;
    for (int i=len1-1; i >= 0; i --) {
        temp = str1[i]-'0' + str2[i]-'0' + cf;
        cf = temp/10;
        temp %= 10;
        ans = char(temp+'0') + ans;
    }
    if (cf != 0) ans = char(cf+'0') + ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    string a, b;
    while (cin >> a >> b) cout << add(a,b) << endl;
    return 0;
}