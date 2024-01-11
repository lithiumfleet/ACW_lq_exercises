#include <iostream>
#include <cstdio>

using namespace std;
const int N = 100010;
int t[N];
int n;
typedef long long ll;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) scanf("%d", &t[i]);
    

    long long res = 0;
    for (int i = 1; i+1 <= n; i ++) {
        res += max(0, t[i+1]-t[i]);
    }
    
    
    printf("%lld\n", res);

    return 0;
}