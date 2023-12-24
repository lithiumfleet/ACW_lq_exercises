// 得再写一遍
#include <iostream>

using namespace std;

const int N = 100010;

// kid记录当前第k个插入的数
int head, kid, node[N], ne[N];

void init() {
    head = -1;
}

void add_head(int x) {
    node[kid] = x;
    ne[kid] = head;
    head = kid++;
}

void add_k(int k, int x) {
    node[kid] = x;
    ne[kid] = ne[k];
    ne[k] = kid ++;
}

void remove(int k) {
    ne[k] = ne[ne[k]];
}

int main() {
    init();

    int m;
    cin >> m;
    while (m -- )
    {
        char op;
        int k, x;
        cin >> op;
        if (op == 'H')
        {
            cin >> x;
            add_head(x);
        }
        else if (op == 'I')
        {
            cin >> k >> x;
            add_k(k - 1, x);
        }
        else
        {
            cin >> k;
            if (!k) head = ne[head];
            else remove(k - 1);
        }
    }

    for (int i = head; i != -1; i = ne[i]) cout << node[i] << ' ';
    cout << endl;

    return 0;
}