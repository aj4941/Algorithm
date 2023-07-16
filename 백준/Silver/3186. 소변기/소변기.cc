#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int k, l, n; cin >> k >> l >> n;
    string s; cin >> s;
    int cur_k = 0, cur_l = l;
    bool use = false;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (!use)
        {
            if (s[i] == '1') cur_k++;
            else cur_k = 0;

            if (cur_k == k)
            {
                cur_k = 0;
                use = true;
            }
        }
        else
        {
            if (s[i] == '1') cur_l = l;
            else cur_l--;

            if (cur_l == 0)
            {
                ans.push_back(i + 1);
                cur_l = l;
                use = false;
            }
        }
    }

    if (use)
        ans.push_back(n + cur_l);

    if (ans.size() == 0) cout << "NIKAD";
    else for (auto to : ans) cout << to << "\n";
}