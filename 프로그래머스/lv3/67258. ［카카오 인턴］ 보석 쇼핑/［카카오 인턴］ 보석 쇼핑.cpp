#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
map<string, bool> cache;

vector<int> solution(vector<string> s) {
    
    int n = s.size();
    int sz = 0;
    for (auto to : s)
    {
        if (!cache[to]) sz++;
        cache[to] = true;
    }
    int l = 0, r = 0, cnt = 1; mp[s[l]]++;
    int ans = 1e9, ans_l = -1, ans_r = -1;
    while (r < n)
    {
        if (cnt == sz)
        {
            if (r - l + 1 < ans)
            {
                ans = r - l + 1;
                ans_l = l, ans_r = r;
            }
            mp[s[l]]--;
            if (mp[s[l]] == 0) cnt--;
            l++;
        }
        else
        {
            r++;
            if (r < n) 
            {
                mp[s[r]]++;
                if (mp[s[r]] == 1)
                    cnt++;
            }
        }
    }
    
    vector<int> answer = { ans_l + 1, ans_r + 1 };
    return answer;
}