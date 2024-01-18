#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const ll inf = 1000000007;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
unordered_map<string, bool> cache;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        string t = "";
        for (int j = 0; j < s.size(); j++)
        {
            t.push_back(s[j]);
            cache[t] = true;
        }
    }
    
    int ans = 0;
    
    for (int i = 0; i < m; i++)
    {
        string s; cin >> s;
        if (cache.count(s)) ans++;
    }
    
    cout << ans;
}