#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow) 
{
    int sum = brown + yellow;
    for (int x = 3; x <= sum; x++)
    {
        if (sum % x) continue;
        int y = sum / x;
        if (y < 3) continue;
        if ((x - 2) * (y - 2) == yellow)
            return { max(x, y), min(x, y) };
    }
}