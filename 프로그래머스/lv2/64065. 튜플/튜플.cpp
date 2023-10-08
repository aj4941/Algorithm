#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
map<int, int> mp;

vector<int> solution(string s) 
{
    vector<int> ans;
    string tmp = "";
    for (int i = 0; i < s.size(); i++)
    {
        if ('0' <= s[i] && s[i] <= '9')
            tmp += s[i];
        else
        {
            if (tmp == "") continue;
            mp[stoll(tmp)]++;
            tmp = "";
        }
    }
    
    vector<pii> res;
    for (auto to : mp)
        res.push_back({ to.second, to.first });
    
    sort(res.rbegin(), res.rend());
    
    for (auto to : res)
        ans.push_back(to.second);
    
    return ans;
}