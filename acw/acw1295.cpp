// 记得重写
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
// 把X分解为它的质因数序列s.最大长度=len(s),序列个数=多重集合的排列数
typedef long long ll;

const int N = (1<<20) + 10;

int prime[N], cnt;
bool st[N];
int minp[N];

// 埃拉托斯特尼筛法
void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            minp[i] = i;
            prime[cnt ++] = i;
        }
        for (int j = 0; prime[j] * i <= n; j ++) {
            int t = prime[j] * i;
            st[t] = true;
            minp[t] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
}


int main() {
    get_primes(N-1);
    int sum[N];
    int x;
    while (scanf("%d",&x) != -1) {
        int k = 0, total = 0;
        while (x > 1) {
            int p = minp[x];
            sum[k] = 0;
            while (x % p == 0) {
                x /= p;
                sum[k] ++;
                total ++;
            }
            k ++;
        }
        ll res = 1;
        for (int i = 1; i <= total; i ++) res *= i;
        for (int i = 0; i < k; i ++) {
            for (int j = 1; j <= sum[i]; j ++) res /= j;
        }
        printf("%d %lld\n", total, res);
    }
    return 0;
}