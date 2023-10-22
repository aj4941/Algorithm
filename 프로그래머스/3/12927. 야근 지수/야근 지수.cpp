#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solution(int n, vector<int> works) 
{
    priority_queue<int> pq;
    for (auto to : works) pq.push(to);
    
    ll ans = 0;
    
    while (pq.size() && n > 0)
    {
        auto to = pq.top(); pq.pop();
        to--; n--;
        if (to > 0) pq.push(to);
    }
    
    while (!pq.empty())
    {
        auto to = pq.top(); pq.pop();
        ans += to * to;
    }
    
    return ans;
}