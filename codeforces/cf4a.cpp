#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    if (n % 2 == 0 && n > 2) printf("YES\n"); // sb你自己想想n=2的时候
    else printf("NO\n");
    return 0;
}