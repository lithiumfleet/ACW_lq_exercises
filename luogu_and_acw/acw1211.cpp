// 脑筋急转弯: 把掉头视为穿过, error向右, 则error右边向左的和左边向右的遭殃
#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int error; cin >> error;
    n --;

    int left = 0, right = 0;
    int cnt;
    while (n --) {
        cin >> cnt;
        if (error > 0) {
            if (cnt < 0 && abs(cnt) > abs(error)) right ++;
            if (cnt > 0 && abs(cnt) < abs(error)) left ++;
        } else {
            if (cnt > 0 && abs(cnt) < abs(error)) left ++;
            if (cnt < 0 && abs(cnt) > abs(error)) right ++;
        }
    }

    // 如果没传染其他蚂蚁, 直接返回1
    if (error > 0 && right == 0) left = 0; 
    if (error < 0 && left == 0) right = 0;

    cout << left + right + 1 << endl;
    return 0;
}