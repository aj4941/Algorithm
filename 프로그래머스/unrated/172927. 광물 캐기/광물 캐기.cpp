#include <bits/stdc++.h>
using namespace std;
int cost[3][3] = { { 1, 1, 1 }, 
                   { 5, 1, 1 },
                   { 25, 5, 1 } };

unordered_map<string, int> mp = { { "diamond", 0 }, { "iron", 1 }, { "stone", 2 } };

int ans = 1e9;

void dfs(int idx, vector<int> &picks, vector<string> &minerals, int sum)
{
    if (idx == minerals.size() || (picks[0] == 0 && picks[1] == 0 && picks[2] == 0))
    {
        ans = min(ans, sum);
        return;
    }
    
    for (int i = 0; i < 3; i++)
    {
        if (picks[i] == 0) continue;
        picks[i]--;
        int res = 0;
        for (int j = idx; j < min((int)minerals.size(), idx + 5); j++)
            res += cost[i][mp[minerals[j]]];
        
        dfs(min((int)minerals.size(), idx + 5), picks, minerals, sum + res);
        picks[i]++;
    }
}

int solution(vector<int> picks, vector<string> minerals)
{
    dfs(0, picks, minerals, 0);
    return ans;
}