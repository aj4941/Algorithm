#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

vector<int> solution(int e, vector<int> v) 
{
    vector<int> cnt(e + 1);
    for (int i = 1; i <= e; i++)
    {
        for (int j = i; j <= e; j += i)
            cnt[j]++;
    }
    vector<int> res;
    int mx = 0, mx_val = -1;
    for (int i = e; i >= 1; i--) // e개
    {
        if (mx <= cnt[i])
        {
            mx = cnt[i];
            mx_val = i;
        }
        res.push_back(mx_val);
    }
    reverse(res.begin(), res.end());
    vector<int> ans;
    for (int s : v)
        ans.push_back(res[s - 1]);
    
    return ans;
}