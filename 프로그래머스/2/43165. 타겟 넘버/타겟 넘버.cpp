#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int prv[N];
vector<int> a;
int t, ans;

void dfs(int idx)
{
    if (idx == a.size())
    {
        int sum = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (prv[i] == 0) sum += a[i];
            else sum -= a[i];
        }
        
        if (sum == t)
            ans++;
        
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        prv[idx] = i;
        dfs(idx + 1);
    }
}

int solution(vector<int> numbers, int target) 
{
    a = numbers; t = target;
    dfs(0);
    
    return ans;
}