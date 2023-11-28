#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
int dp[N][3][53][53];
int n;

int solve(int i, int j, int t, int ht, int &ct, int &t1, int &t2, int &a, int &b, vector<int> &v)
{
    int &ret = dp[i][j][t][ht];
    if (ret != -1) return ret;
    ret = 1e9;
    if (i == n) return ret = 0;
    if (v[i] == 1 && (t < t1 || t > t2))
        return ret;
    if (j == 0)
    {
        if (t < ct) t++;
        else if (t > ct) t--;
        ret = min(ret, solve(i + 1, 0, t, 0, ct, t1, t2, a, b, v));
        for (int nht = 0; nht <= 50; nht++)
            ret = min(ret, solve(i + 1, 1, t, nht, ct, t1, t2, a, b, v));
    }
    else
    {
        int cost = (t == ht) ? b : a;
        if (t < ht) t++;
        else if (t > ht) t--;
        ret = min(ret, solve(i + 1, 0, t, 0, ct, t1, t2, a, b, v) + cost);
        for (int nht = 0; nht <= 50; nht++)
            ret = min(ret, solve(i + 1, 1, t, nht, ct, t1, t2, a, b, v) + cost);
    }
    return ret;
}

int solution(int ct, int t1, int t2, int a, int b, vector<int> v) 
{
    n = v.size();
    memset(dp, -1, sizeof dp);
    ct += 10, t1 += 10, t2 += 10;
    int ans = solve(0, 0, ct, 0, ct, t1, t2, a, b, v);
    for (int ht = 0; ht <= 50; ht++)
        ans = min(ans, solve(0, 1, ct, ht, ct, t1, t2, a, b, v));
    
    return ans;
}