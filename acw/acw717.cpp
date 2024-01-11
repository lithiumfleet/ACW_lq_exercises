#include <iostream>
#include <cstdio>

using namespace std;

int nums[50];

int main() {
    nums[0] = 0;
    nums[1] = 1;
    
    int n = 5;
    // scanf("%d", &n);
    
    int i = 0;
    while (n --) {
        if (i >= 2) {
            nums[i] = nums[i-2] + nums[i-1];
        }
        printf("%d ", nums[i]);
        i ++;
    }
    return 0;
}