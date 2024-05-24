#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, 0, 0, 0 };
int dy[4] = { 0, 1, 1, -1 };
map<char, ll> mp;
string s, t;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    mp['I'] = 1, mp['V'] = 5, mp['X'] = 10, mp['L'] = 50, mp['C'] = 100, mp['D'] = 500, mp['M'] = 1000;
    cin >> s >> t;
    ll sum = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (i + 1 < s.size() && mp[s[i]] < mp[s[i + 1]])
        {
            sum += mp[s[i + 1]] - mp[s[i]];
            i++;
        }
        else
            sum += mp[s[i]];
    }

    for (int i = 0; i < t.size(); i++)
    {
        if (i + 1 < t.size() && mp[t[i]] < mp[t[i + 1]])
        {
            sum += mp[t[i + 1]] - mp[t[i]];
            i++;
        }
        else
            sum += mp[t[i]];
    }

    cout << sum << "\n";

    ll inc = 1;
    vector<vector<string>> ans;
    ans.push_back({});

    while (sum > 0)
    {
        ll tmp = (sum % 10) * inc;
        if (1000 <= tmp)
        {
            ans.back().push_back("M");
            sum -= 1;
        }
        else if (900 == tmp)
        {
            ans.back().push_back("CM");
            sum -= 9;
        }
        else if (500 <= tmp)
        {
            ans.back().push_back("D");
            sum -= 5;
        }
        else if (400 == tmp)
        {
            ans.back().push_back("CD");
            sum -= 4;
        }
        else if (100 <= tmp)
        {
            ans.back().push_back("C");
            sum -= 1;
        }
        else if (90 == tmp)
        {
            ans.back().push_back("XC");
            sum -= 9;
        }
        else if (50 <= tmp)
        {
            ans.back().push_back("L");
            sum -= 5;
        }
        else if (40 == tmp)
        {
            ans.back().push_back("XL");
            sum -= 4;
        }
        else if (10 <= tmp)
        {
            ans.back().push_back("X");
            sum -= 1;
        }
        else if (9 == tmp)
        {
            ans.back().push_back("IX");
            sum -= 9;
        }
        else if (5 <= tmp)
        {
            ans.back().push_back("V");
            sum -= 5;
        }
        else if (4 == tmp)
        {
            ans.back().push_back("IV");
            sum -= 4;
        }
        else if (1 <= tmp)
        {
            ans.back().push_back("I");
            sum -= 1;
        }
        else
        {
            inc *= 10, sum /= 10;
            ans.push_back({});
        }
    }

    reverse(ans.begin(), ans.end());

    for (auto to : ans)
    {
        for (auto too : to)
            cout << too;
    }
}
