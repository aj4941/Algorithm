#include <bits/stdc++.h>
using namespace std;
vector<string> user, banned;
bool cache[10];
int res[10];
int N, M;
set<vector<int>> s;

bool calc(string a, string b)
{
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i] && b[i] != '*')
            return false;
    }
    return true;
}


void dfs(int cnt)
{
    if (cnt == M)
    {
        vector<int> v;
        bool hasAns = true;
        for (int i = 0; i < cnt; i++)
        {
            if (!calc(user[res[i]], banned[i]))
                hasAns = false;
            v.push_back(res[i]);
        }
        if (hasAns)
        {
            sort(v.begin(), v.end());
            s.insert(v);
        }
        return;
    }
    
    for (int i = 0; i < N; i++)
    {
        if (cache[i]) continue;
        cache[i] = true; res[cnt] = i;
        dfs(cnt + 1);
        cache[i] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    
    user = user_id, banned = banned_id;
    N = user.size(); M = banned.size();
    dfs(0);
    return s.size();
}