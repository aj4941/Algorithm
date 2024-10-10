#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef tuple<ll, ll, ll> tll;
const int N = 10;
vector<vector<int>> v;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    v.push_back({});
    v.push_back({ 4, 5 }); v.push_back({}); v.push_back({ 4, 5 }); v.push_back({ 2, 3 });
    v.push_back({ 8 }); v.push_back({ 2, 3 }); v.push_back({ 8 }); v.push_back({ 6, 7 });

    int tc = 1;
    while (true)
    {
        string s; cin >> s;
        if (s == "0") return 0;
        if (s.front() != '1' || s.back() != '2')
        {
            cout << tc << ". " << "NOT" << "\n";
            tc++;
            continue;
        }
        bool hasAns = true;
        for (int i = 1; i < s.size(); i++)
        {
            bool flag = false;
            int idx = s[i - 1] - '0';
            for (auto to : v[idx])
            {
                if (to == s[i] - '0')
                    flag = true;
            }

            if (!flag)
            {
                hasAns = false;
                break;
            }
        }

        if (hasAns)
            cout << tc << ". " << "VALID" << "\n";
        else
            cout << tc << ". " << "NOT" << "\n";

        tc++;
    }
}