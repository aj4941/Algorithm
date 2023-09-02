#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e6 + 3;
int cnt[N], res[N];

void init()
{
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
            cnt[j]++;
    }
}

vector<int> solution(int e, vector<int> st)
{
    init();
    int mx = 0, mx_ans = -1;
    vector<int> ans;
    
    for (int i = e; i >= 1; i--)
    {
        if (mx <= cnt[i])
            mx = cnt[i], mx_ans = i;
        
        res[i] = mx_ans;
    }
    
    for (auto to : st)
        ans.push_back(res[to]);
    
    return ans;
}