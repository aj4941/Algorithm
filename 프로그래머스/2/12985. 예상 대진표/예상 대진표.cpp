#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int ans = 0;
    while (true)
    {
        ans++;
        a = (a + 1) / 2, b = (b + 1) / 2;
        if (a == b)
            return ans;
    }
}