#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
int n, prv[20]; 
int cntA[1000], cntB[1000];
bool cache[20];

void calc(int idx, int c, vector<int> &a, vi &dice)
{
    if (idx == a.size())
    {
        int sum = 0;
        for (int i = 0; i < n / 2; i++)
            sum += dice[a[i]][prv[i]];
        
        if (c == 0) cntA[sum]++;
        else cntB[sum]++;
        
        return;
    }
    
    for (int i = 0; i < 6; i++)
    {
        prv[idx] = i;
        calc(idx + 1, c, a, dice);
    }
}

int ans = -1;
vector<int> ansV;

void dfs(int idx, int p, vi &dice)
{
    if (idx == n / 2)
    {
        vector<int> A, B;
        
        for (int i = 0; i < n; i++)
        {
            if (cache[i]) A.push_back(i);
            else B.push_back(i);
        }
        
        calc(0, 0, A, dice); calc(0, 1, B, dice);
        
        for (int i = 1; i <= 600; i++)
            cntB[i] += cntB[i - 1];
        
        int res = 0;
        
        for (int i = 600; i >= 1; i--)
            res += cntA[i] * cntB[i - 1];
        
        if (ans < res)
        {
            ans = res;
            ansV = A;
        }
        
        memset(cntA, 0, sizeof cntA); 
        memset(cntB, 0, sizeof cntB);
        
        return;    
    }
    
    for (int i = p; i < n; i++)
    {
        cache[i] = true;
        dfs(idx + 1, i + 1, dice);
        cache[i] = false;
    }
}

vector<int> solution(vi dice) 
{
    n = dice.size();
    dfs(0, 0, dice);
    for (auto &to : ansV) to++;
    return ansV;
}