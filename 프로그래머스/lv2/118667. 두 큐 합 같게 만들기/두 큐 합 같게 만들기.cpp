#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solution(vector<int> q1, vector<int> q2) 
{
    ll sum1 = 0, sum2 = 0;
    int ans = 0;
    deque<ll> dq1, dq2;
    for (auto to : q1) 
    {
        dq1.push_back(to);
        sum1 += to;
    }
    for (auto to : q2)
    {
        dq2.push_back(to);
        sum2 += to;
    }
    
    ll sz = q1.size() + q2.size();
    
    while (sum1 != sum2 && ans < sz * 2)
    {
        ll v1 = dq1.front(), v2 = dq2.front();
        if (sum1 < sum2)
        {
            dq2.pop_front(); sum2 -= v2;
            dq1.push_back(v2); sum1 += v2;
        }
        else
        {
            dq1.pop_front(); sum1 -= v1;
            dq2.push_back(v1); sum2 += v1;
        }
        ans++;
    }
    
    if (ans == sz * 2) ans = -1;
    return ans;
}