#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> sc, int K) 
{
    priority_queue<int> pq;
    for (auto to : sc) pq.push(-to);
    int ans = 0;
    while (true)
    {
        if (-pq.top() >= K) return ans;
        if (pq.size() == 1) return -1;
        int v1 = -pq.top(); pq.pop();
        int v2 = -pq.top(); pq.pop();
        int nv = (v1 + v2 * 2);
        pq.push(-nv); ans++;
    }
    
    return ans;
}