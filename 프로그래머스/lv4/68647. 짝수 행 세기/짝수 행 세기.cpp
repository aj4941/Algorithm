#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 305;
const ll inf = 10000019;
int n, m, col[N];
ll dp[N][N], comb[N][N];

ll nCr(int n, int r)
{
    ll &ret = comb[n][r];
    if (ret != -1) return ret;
    if (n == r || r == 0) return ret = 1;
    return ret = (nCr(n - 1, r) + nCr(n - 1, r - 1)) % inf;
}

ll solve(int idx, int cnt)
{
    if (idx == m) 
    {
        if (cnt == n) return 1;
        else return 0;
    }
    ll &ret = dp[idx][cnt];
    if (ret != -1) return ret;
    ret = 0;
    for (int k = 0; k <= col[idx]; k++)
    {
        // A : 짝수행 선택 개수, B : 홀수행 선택 개수
        int A = k, B = col[idx] - k;
        if (cnt - A >= 0 && (n - cnt) - B >= 0) // 남은 짝수행, 남은 홀수행이 모두 >= 0
        {
            ll res = nCr(cnt, A) * nCr(n - cnt, B) % inf;
            res *= solve(idx + 1, cnt - A + B) % inf;
            ret += res; ret %= inf;
        }
    }
    return ret;
}

int solution(vector<vector<int>> a) {
    memset(dp, -1, sizeof dp);
    memset(comb, -1, sizeof comb);
    n = a.size(), m = a[0].size();
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
            col[j] += a[i][j];
    }
    
    return solve(0, n);
}