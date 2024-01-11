#include <iostream>
#include <string>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q --) {
        string a;
        cin >> a;
        if (a.size() <= 10) printf("%s\n",a.c_str()); // sb不看题
        else printf("%c%d%c\n",a[0],a.length()-2,a[a.length()-1]);
    }
    return 0;
}