#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans = 0;
string s;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    while (true)
    {
        string ns = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                ans++;
                continue;
            }
            ns += s[i];
        }

        reverse(ns.begin(), ns.end());
        while (ns.size() && ns.back() == '0') ns.pop_back();
        reverse(ns.begin(), ns.end());

        if (ns.size() == 0)
            break;

        ll num = stoll(ns); num--;
        ns = to_string(num); ans++;

        if (ns == "0")
            break;

        s = ns;
    }

    cout << ans;
}