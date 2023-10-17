#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 10;
int cache[N], prv[N];
vector<int> a;
int n;
set<int> st;

bool calc(int num)
{
    // cout << num << endl;
    
    if (num == 0 || num == 1)
        return false;
    
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0) 
            return false;
    }
    return true;
}

void dfs(int idx)
{
    if (idx == n)
    {
        vector<pii> tmp;
        for (int i = 0; i < n; i++)
        {
            if (prv[i] == -1) continue;
            tmp.push_back({ prv[i], a[i] });
        }
        
        if (tmp.size() > 0)
        {
            sort(tmp.begin(), tmp.end());
            int val = 0;
            for (auto to : tmp)
                val = val * 10 + to.second;
            
            if (calc(val))
                st.insert(val);
        }
        return;
    }
    
    prv[idx] = -1;
    dfs(idx + 1);
    
    for (int i = 0; i < n; i++)
    {
        if (cache[i]) continue;
        cache[i] = 1; prv[idx] = i;
        dfs(idx + 1);
        cache[i] = 0; prv[idx] = -1; 
    }
}

int solution(string number) 
{
    for (auto to : number) a.push_back(to - '0');
    n = a.size(); dfs(0);
    return st.size();
}