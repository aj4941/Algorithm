#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple <ll, ll, ll, ll, ll> tl;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
string a, b;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> a >> b;
    sort(a.begin(), a.end()); sort(b.rbegin(), b.rend());
    int n = a.size();
    a = a.substr(0, (n + 1) / 2); b = b.substr(0, n / 2);
    deque<char> l, r;

    for (auto to : a) l.push_back(to);
    for (auto to : b) r.push_back(to);

    vector<char> lv, rv;
    int turn = 0;

    while (l.size() || r.size())
    {
        if (turn == 0)
        {
            if (r.size() == 0)
            {
                lv.push_back(l.front());
                l.pop_front();
            }
            else
            {
                if (l.front() < r.front())
                {
                    lv.push_back(l.front());
                    l.pop_front();
                }
                else
                {
                    rv.push_back(l.back());
                    l.pop_back();
                }
                turn = 1 - turn;
            }
        }
        else
        {
            if (l.size() == 0)
            {
                lv.push_back(r.front());
                r.pop_front();
            }
            else
            {
                if (r.front() > l.front())
                {
                    lv.push_back(r.front());
                    r.pop_front();
                }
                else
                {
                    rv.push_back(r.back());
                    r.pop_back();
                }
                turn = 1 - turn;
            }
        }
    }

    reverse(rv.begin(), rv.end());

    for (auto to : lv) cout << to;
    for (auto to : rv) cout << to;
}