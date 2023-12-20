#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int max_d[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
typedef struct Date {
    int y, m, d;
} Date;
Date s[5]; 

int cmp(const Date& a, const Date& b) {
    if (a.y != b.y) return a.y < b.y;
    if (a.m != b.y) return a.m < b.m;
    if (a.d != b.d) return a.d < b.d;
    return 0;
}

bool eq(const Date& a, const Date& b) {
    return a.y==b.y && a.m==b.m;
}

int cnt = 0;
void get(int y, int m, int d) {
    if (y >= 60) y += 1900;
    else y += 2000;
    if (m == 0 || m > 12 || d == 0) return;
    if (m == 2) {
        int leap = y%100!=0 && y%4==0 || y%400==0;
        if (d > 28 + leap) return;
    } else {
        if (d > max_d[m]) return;
    }
    s[cnt++] = {y,m,d};
}

int main() {
    int y, m, d;
    scanf("%d/%d/%d", &y, &m, &d);
    get(y,m,d);
    get(d,m,y);
    get(d,y,m);
    sort(s, s+cnt, cmp);
    for (int i = 0; i < cnt; i ++) {
        if (i && eq(s[i],s[i-1])) continue;
        printf("%d-%02d-%02d\n",s[i].y,s[i].m,s[i].d);
    }
    return 0;
}