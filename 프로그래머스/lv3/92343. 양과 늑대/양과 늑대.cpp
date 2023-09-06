#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> vii;
typedef vector<int> vi;
// ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
#define inf 1000000007
const int N = 19;
pii dp[1 << N];
vector<int> g[N];

int solution(vector<int> info, vector<vector<int>> edges) 
{
    int n = info.size();
    for (int bit = 0; bit < (1 << n); bit++)
        dp[bit] = pii(-1, -1);
    
    if (info[0] == 1) return 0;
    dp[1] = pii(1, 0);
    
    for (auto to : edges)
    {
        int x = to[0], y = to[1];
        g[x].push_back(y); g[y].push_back(x);
    }
    
    int ans = 1;

    for (int bit = 0; bit < (1 << n); bit++) 
    {
        for (int i = 1; i < n; i++) 
        {
            if (bit & (1 << i))
            {
                for (int ni : g[i])
                {
                    if (bit & (1 << ni)) 
                    {
                        int nbit = bit - (1 << i);
                        int x = dp[nbit].first, y = dp[nbit].second;
                        if (x == -1) continue;
                        int nx = x + (info[i] == 0 ? 1 : 0);
                        int ny = y + (info[i] == 1 ? 1 : 0);
                        if (nx <= ny) continue;
                        if (dp[bit].first < nx)
                            dp[bit] = pii(nx, ny);
                        
                        ans = max(ans, dp[bit].first);
                    }
                }
            }
        }
    }
    int bit = (1 << 0) + (1 << 1) + (1 << 8);
    cout << dp[bit].first << ' ' << dp[bit].second << endl;
    return ans;
}