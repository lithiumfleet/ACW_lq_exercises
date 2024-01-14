#include <iostream>
#include <string>
using namespace std;

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

string mut(string str1, string str2) {
    string ans;
    int len1 = str1.size(), len2 = str2.size();
    string tempstr;
    for (int i=len2-1; i >= 0; i --) {
        tempstr = "";
        int temp = str2[i]-'0';
        int t = 0;
        int cf = 0;
        if (temp != 0) {
            for (int j = 1; j <= len2-i-1; j ++) tempstr += "0";
            for (int j = len1-1; j >= 0; j --) {
                t = temp*(str1[j]-'0') + cf;
                cf = t / 10;
                t %= 10;
                tempstr = char(t+'0') + tempstr;
            }
            if (cf != 0) tempstr = char(cf+'0') + tempstr;
        }
        ans = add(ans, tempstr);
    }
    ans.erase(0, ans.find_first_not_of('0'));
    if (ans.size() == 0) ans = "0";
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    string a, b;
    while (cin >> a >> b) cout << mut(a,b) << endl;
    return 0;
}