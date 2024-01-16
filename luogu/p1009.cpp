// ......高精度真的麻烦, 代码不能ac
#include <iostream>
#include <string>
using namespace std;

int n;

string add(string a, string b) {
    if (a.size() < b.size()) a = string(b.size()-a.size(), '0') + a;
    else b = string(a.size()-b.size(),'0') + b;
    
    int cf = 0;
    string res;
    for (int i=a.size()-1; i >= 0; i --) {
        int temp;
        temp = a[i]-'0' + b[i]-'0' + cf;
        cf = temp / 10;
        temp %= 10;
        res = char(temp+'0') + res;
    }
    if (cf != 0) res = char(cf+'0') + res;
    return res;
}

string mut(string a, string b) {
    string res;
    for (int i=b.size()-1; i >= 0; i --) {
        string temps = "";
        int cf = 0;
        if (b[i] != '0') {
            temps += string(b.size()-i-1, '0'); // 后向补零
            for (int j=a.size()-1; j >= 0; j --) {
                int temp = (b[i]-'0') * (a[j]-'0') + cf;
                cf = temp / 10;
                temp %= 10;
                temps = char(temp+'0') + temps;
            }
            if (cf != 0) temps = char(cf+'0') + temps;
        }
        res = add(res, temps);
    }
    res.erase(0, res.find_first_not_of('0'));
    if (res.size() == 0) res = "0";
    return res;
}

string fact(int n) {
    string res = "1";
    for (int i=1; i <= n; i ++) {
        res = mut(res, string{char('0'+i)});
    }
    return res;
}

string nfact(int n) {
    string res = "1";
    string temp = "";
    for (int i=1; i <= n; i ++) {
        temp = mut(res, string{char('0'+i)});
        res = add(temp, res);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    while (true) {
        cin >> n;
        cout << nfact(n) << endl;
    }
    return 0;
}