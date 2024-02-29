#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> a, vector<int> b)
{
    sort(a.begin(), a.end()); sort(b.rbegin(), b.rend());
    int ans = 0;
    for (int i = 0; i < a.size(); i++)
        ans += a[i] * b[i];
    
    return ans;
}