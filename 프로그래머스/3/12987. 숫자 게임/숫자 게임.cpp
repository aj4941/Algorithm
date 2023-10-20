#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> a, vector<int> b)
{
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());
    deque<int> dq;
    for (int i = 0; i < b.size(); i++)
        dq.push_back(b[i]);
    
    int ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (dq.back() > a[i])
        {
            ans++;
            dq.pop_back();
        }
        else
            dq.pop_front();
    }
    
    return ans;
}