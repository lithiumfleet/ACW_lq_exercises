#include <iostream>
using namespace std;
using namespace std;

int nums[50];

int main() {
    int n;
    cin >> n;
    nums[0] = 0, nums[1] = 1;
    for (int i = 2; i < n; i ++) {
        nums[i] = nums[i-1] + nums[i-2];
    }
    for (int i = 0; i < n; i ++) {
        cout << nums[i] << " ";
    }

    return 0;
}