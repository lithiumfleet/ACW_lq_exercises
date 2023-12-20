// // 模拟题是真难写啊
// // 思路: 枚举回文串,再判断是不是合法日期
// #include <iostream>
// using namespace std;
// // 枚举回文串前四个数字从1000到9999

// int d_in_m[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

// typedef struct Date
// {
//     int y;
//     int m;
//     int d;
//     bool operator>(const Date& a) {
//         if (y < a.y) return false;
//         if (y == a.y && m > a.y) return false;
//         if (y == a.y && m == a.m && d <= a.d) return false;
//         return true;
//     } 
//     bool operator==(const Date& a) {
//         return y == a.y && m == a.m && d == a.d;
//     }
//     bool operator<(const Date& a) {
//         Date cur{y,m,d};
//         return !(cur==a || cur>a);
//     }
// } Date;

// Date d1, d2;

// Date split(int date) {
//     int year = date / 10000;
//     int month = (date - year * 10000) / 100;
//     int day = (date - year * 10000 - month * 100);
//     return Date{year, month, day};
// }

// bool check(int date) {
//     Date cur = split(date);
//     if (cur == d1 || cur == d2) return true;
//     if (cur.y < d1.y || cur.y > d2.y) return false;
//     if (cur.m > 12 || cur.m < 1) return false;
//     int max_d = d_in_m[cur.m];
//     if (cur.m == 2) {
//         int leap = cur.y % 100 && cur.y % 4 == 0 || cur.y % 400 == 0;
//         max_d += leap;
//     }
//     if (cur.d > max_d || cur.d < 1) return false;
//     return cur > d1 && cur < d2;
// }

// int main() {
//     int id1, id2;
//     cin >> id1 >> id2;
//     d1 = split(id1);
//     d2 = split(id2);

//     int res = 0;
//     int date;
//     for (int i = 1000; i < 10000; i ++) {
//         date = i;
//         int j = i;
//         while (j) {
//             date *= 10;
//             date += j % 10;
//             j /= 10;
//         }
//         if (check(date)) {
//             res ++;
//             cout << date << endl;
//         }
//     }
//     cout << res << endl;

//     return 0;
// }

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check_valid(int date)
{
    int year = date / 10000;
    int month = date % 10000 / 100;
    int day = date % 100;

    if (month == 0 || month > 12) return false;
    if (day == 0 || month != 2 && day > days[month]) return false;

    if (month == 2)
    {
        int leap = year % 100 && year % 4 == 0 || year % 400 == 0;
        if (day > 28 + leap) return false;
    }
    return true;
}

int main()
{
    int date1, date2;
    cin >> date1 >> date2;

    int res = 0;
    for (int i = 1000; i < 10000; i ++ )
    {
        int date = i, x = i;
        for (int j = 0; j < 4; j ++ ) date = date * 10 + x % 10, x /= 10;

        if (date1 <= date && date <= date2 && check_valid(date)) res ++ ;
    }

    cout << res << endl;

    return 0;
}