#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int dx[8] = { -1, 1, 0, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
const int N = 20;
int n, m;
vector<int> a;
unordered_map<string, int> mp;
string s;

bool calc(string s)
{
    vector<int> v;
    int cnt = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
            cnt++;
        else
        {
            v.push_back(cnt);
            cnt = 1;
        }
    }
    v.push_back(cnt);

    return (a == v);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        s += (x + '0');
    }

    for (int i = 0; i < m; i++)
    {
        int x; cin >> x;
        a.push_back(x);
    }

    queue<string> q; q.push(s); mp[s] = 0;

    while (!q.empty())
    {
        string s = q.front(); q.pop();
        int d = mp[s];
        if (calc(s))
        {
            cout << mp[s];
            return 0;
        }

        for (int i = 1; i < s.size(); i++)
        {
            swap(s[i], s[i - 1]);
            if (!mp.count(s))
            {
                mp[s] = d + 1;
                q.push(s);
            }
            swap(s[i], s[i - 1]);
        }
    }
}