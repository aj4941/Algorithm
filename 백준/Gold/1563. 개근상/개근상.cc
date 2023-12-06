#include <stdio.h>
#include <string.h>
using namespace std;
 
int n;
int dp[1001][3][4];
 
int func(int day, int c1, int c2) {
    if (c1 >= 2 || c2 >= 3)
        return 0;
 
    if (day == n)
        return 1;
 
    int& ref = dp[day][c1][c2];
    if (ref != -1)
        return ref;
 
    return ref = 
        (func(day + 1, c1, 0) + 
        func(day + 1, c1 + 1, 0) + 
        func(day + 1, c1, c2 + 1)) % 1000000;
}
 
int main() {
    scanf("%d", &n);
 
    memset(dp, -1, sizeof(dp));
 
    printf("%d", func(0, 0, 0));
 
    return 0;
}
