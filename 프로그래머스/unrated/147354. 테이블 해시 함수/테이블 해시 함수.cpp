#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
int n, m, col;

bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[col - 1] != b[col - 1])
        return a[col - 1] < b[col - 1];
    
    return a[0] > b[0];
}

int solution(vi a, int c, int s, int e)
{
    int ans = 0;
    n = a.size(), m = a[0].size(); col = c;
    sort(a.begin(), a.end(), cmp);
    
    for (int k = s - 1; k <= e - 1; k++)
    {
        vector<int> v = a[k];
        int res = 0;
        for (int i = 0; i < m; i++)
            res += v[i] % (k + 1);
        
        ans ^= res;
    }
    return ans;
}