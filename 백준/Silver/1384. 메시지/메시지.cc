#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int g = 1;
    while (true)
    {
        vector<int> v[100];
        vector<string> tmp;
        int n; cin >> n;
        if (n == 0) break;
        for (int i = 0; i < n; i++)
        {
            string s; cin >> s;
            tmp.push_back(s);
            for (int j = 0; j < n - 1; j++)
            {
                char ch; cin >> ch;
                if (ch == 'P') v[i].push_back(0);
                else v[i].push_back(1);
            }
        }

        vector<pair<string, string>> ans;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                if (v[i][j] == 1)
                {
                    int ni = (i - (j + 1) + n) % n;
                    ans.push_back({ tmp[ni], tmp[i] });
                }
            }
        }

        // sort(ans.begin(), ans.end());
        cout << "Group " << g++ << "\n";

        if (ans.size() == 0)
        {
            cout << "Nobody was nasty" << "\n";
            cout << "\n";
            continue;
        }
        for (auto to : ans)
        {
            cout << to.first << ' ';
            cout << "was nasty about ";
            cout << to.second << "\n";
        }

        cout << "\n";
    }
}