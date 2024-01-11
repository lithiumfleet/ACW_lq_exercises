#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100010;
struct log
{
    int ts, id;
    bool operator<(const log &b) const {
        if (ts == b.ts) return id < b.id;
        return ts < b.ts;
    }
} logs[N];

int cnt[N];
bool hot[N];


int main() {
    int n,d,k;
    cin >> n >> d >> k;
    for (int i = 0; i < n; i ++) {
        int ts, id;
        scanf("%d%d", &ts, &id);
        logs[i] = {ts, id};
    }

    sort(logs,logs+n);

    for (int i = 0, j = 0; i < n; i ++) {
        int id = logs[i].id;
        cnt[id] ++;
        while (logs[i].ts - logs[j].ts >= d) {
            cnt[logs[j].id] --;
            j ++;
        }
        if (cnt[id] >= k) hot[id] = true;
    }
    for (int i = 0; i < N; i ++) {
        if (hot[i]) printf("%d\n", i);
    }

    return 0;
}