#include <bits/stdc++.h>
using namespace std;
vector<pair<char, int>> v;
vector<pair<int, char>> a;
map<char, int> mp;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int x, n; cin >> x >> n;
    for (int i = 0; i < n; i++)
    {
        char ch; cin >> ch;
        int num; cin >> num;
        if (x <= 20 * num)
            v.push_back({ ch, num });
    }

    for (auto to : v)
    {
        for (int num = 1; num <= 14; num++)
        {
            a.push_back({ to.second / num, to.first });
            mp[to.first] = 0;
        }
    }

    sort(a.rbegin(), a.rend());

    for (int i = 0; i < 14; i++)
        mp[a[i].second]++;

    for (auto to : mp)
        cout << to.first << ' ' << to.second << "\n";
}