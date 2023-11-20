#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;

string calc(string s)
{
    for (auto &to : s)
    {
        if ('A' <= to && to <= 'Z')
            to = to - 'A' + 'a';
    }
    return s;
}

int solution(int sz, vector<string> a) 
{
    int n = a.size();
    reverse(a.begin(), a.end());
    int ans = 0, cnt = 0, idx = 0;
    
    for (int i = 0; i < n; i++)
    {
        string s = calc(a[i]);
        if (mp[s] == 0)
        {
            if (cnt + 1 > sz)
                break;
            cnt++;
        }
        mp[s]++; idx = i + 1;
    }
    
    for (int i = 0; i < n; i++)
    {
        string s = calc(a[i]);
        if (mp[s] == 1) cnt--;
        mp[s]--;
        
        while (idx < n && cnt < sz)
        {
            string ns = calc(a[idx]);
            if (mp[ns] == 0)
            {
                if (cnt + 1 > sz)
                    break;
                cnt++;
            }
            mp[ns]++; idx++;
        }
        
        if (mp[s] > 0) ans++;
        else ans += 5;
    }
    
    return ans;
}