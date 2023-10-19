#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int solution(int len, int w, vector<int> a) 
{
    deque<pii> dq;
    int n = a.size();
    int t = 0, idx = 0, cw = 0;
    while (true)
    {
        if (dq.size() && t - dq.front().second >= len - 1)
        {
            cw -= dq.front().first;
            dq.pop_front(); 
        }
        
        if (idx < n && cw + a[idx] <= w)
        {
            // cout << a[idx] << ' ' << t + 1 << endl;
            dq.push_back({ a[idx], t + 1 });
            cw += a[idx]; idx++;
        }
        
        if (idx == n && dq.size() == 0)
            return t + 1;
        
        t++;
    }
}