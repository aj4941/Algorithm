#include <bits/stdc++.h>
using namespace std;
const int N = 100002;
typedef pair<int, int> pii;

vector<int> solution(vector<int> p) 
{
    int n = p.size();
    vector<int> ans = { 0 };
    vector<pii> stk = { { p[n - 1], n - 1 } };
    
    for (int i = n - 2; i >= 0; i--)
    {
        while (stk.size() > 0)
        {
            if (stk.back().first >= p[i])
                stk.pop_back();
            else
                break;
        }
        
        if (stk.size() > 0)
            ans.push_back(stk.back().second - i);
        else
            ans.push_back(n - 1 - i);
        
        stk.push_back({ p[i], i });
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}