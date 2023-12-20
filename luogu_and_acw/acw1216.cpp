#include <cstdio>

using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int res = n;
    while (n >= 3) {
        res += n / 3;
        n = n % 3 + n / 3;
    }
    printf("%d", res);
}