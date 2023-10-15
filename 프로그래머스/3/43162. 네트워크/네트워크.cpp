#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
const int N = 300;
int p[N];

int find(int x)
{
    if (p[x] == x) return x;
    else return p[x] = find(p[x]);
}

int solution(int n, vi a) 
{
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
    {
        if (a[i][j] == 1)
        {
            int u = find(i + 1), v = find(j + 1);
            p[u] = v;
        }
    }
    
    int ans = 0;
    
    for (int i = 1; i <= n; i++)
    {
        if (p[i] == i)
            ans++;
    }
    
    return ans;
}