#include <bits/stdc++.h>
using namespace std;
string t = "AEIOU";
char prv[10];
vector<string> ans;

void calc(int idx)
{
    string res = "";
    for (int i = 0; i <= idx; i++)
        res += prv[i];
    
    // cout << res << endl;
    ans.push_back(res);
}

void dfs(int idx)
{
    if (idx == 5) return;
    for (int i = 0; i < 5; i++)
    {
        prv[idx] = t[i];
        calc(idx);
        dfs(idx + 1);
    }    
}

int solution(string w) 
{
    dfs(0);
    sort(ans.begin(), ans.end());
    
    for (int i = 0; i < ans.size(); i++)
    {
        // cout << ans[i] << ' ' << w << endl;
        if (ans[i] == w)
            return i + 1;
    }
}