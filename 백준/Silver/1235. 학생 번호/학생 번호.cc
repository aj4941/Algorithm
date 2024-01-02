#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int dx[8] = { -1, 1, 0, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
const int N = 2000;
string s[N];
int main(void)
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        reverse(s[i].begin(), s[i].end());
    }

    int l = -1, r = s[0].size() - 1;
    while (l + 1 < r) // (l, r]
    {
        int mid = (l + r) / 2;
        map<string, bool> mp;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            string tmp = "";
            for (int j = 0; j <= mid; j++)
                tmp += s[i][j];
            if (mp.count(tmp))
                flag = false;
            mp[tmp] = true;
        }

        if (flag) r = mid;
        else l = mid;
    }

    cout << r + 1;
}