#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> p, vector<int> s) 
{
    int n = p.size();
    vector<int> ans;
    int l = 1, idx = 0;
    bool flag = true;
    while (flag)
    {
        flag = false;
        int cnt = 0;
        for (int i = idx; i < n; i++)
        {
            int val = p[i] + s[i] * l;
            if (val >= 100) cnt++;
            else
            {
                flag = true;
                idx = i;
                break;
            }
        }
        if (cnt > 0)
            ans.push_back(cnt);
        
        l++;
    }
    
    return ans;
}