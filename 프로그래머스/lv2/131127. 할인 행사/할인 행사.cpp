#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
map<string, int> cnt;

bool calc()
{
    for (auto to : mp)
    {
        if (mp[to.first] != cnt[to.first])
            return false;
    }
    return true;
}

int solution(vector<string> w, vector<int> n, vector<string> d)
{
    for (int i = 0; i < w.size(); i++) mp[w[i]] = n[i];
    for (int i = 0; i < 10; i++) cnt[d[i]]++;
    int ans = 0;
    if (calc()) ans++;
    
    for (int i = 10; i < d.size(); i++)
    {
        cnt[d[i]]++;
        cnt[d[i - 10]]--;
        if (calc()) ans++;
    }
    
    return ans;
}