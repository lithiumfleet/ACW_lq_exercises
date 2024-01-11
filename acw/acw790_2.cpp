#include <iostream>
using namespace std;

const double N = 1e-8;
const double L = -10000.0;
const double R = +10000.0;

int main() {
    double l = L, r = R;
    double t; 
    scanf("%lf", &t); // lf: long float
    while (r - l > N) {
        double mid = (l + r) / 2; // 注意所有的变量都应该是double
        if (mid*mid*mid >= t) r = mid;
        else l = mid;
    }
    printf("%lf", r);
    return 0;
}