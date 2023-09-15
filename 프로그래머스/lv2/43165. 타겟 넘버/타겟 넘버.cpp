#include <bits/stdc++.h>
using namespace std;
const int N = 100;
vector<int> a;
int prv[N];
int res = 0, n;

void dfs(int idx, int target)
{
    if (idx == a.size())
    {
        int ans = 0;
        for (int i = 0; i < a.size(); i++)
            ans += prv[i];
        
        if (ans == target)
            res++;
        
        return;
    }
    
    prv[idx] = a[idx];
    dfs(idx + 1, target);
    prv[idx] = -a[idx];
    dfs(idx + 1, target);
}

int solution(vector<int> A, int target) 
{
    n = a.size(); a = A;
    dfs(0, target);
    return res;
}