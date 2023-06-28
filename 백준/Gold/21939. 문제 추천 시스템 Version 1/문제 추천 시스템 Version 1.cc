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
const int N = 100002;
int cache[N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    set<pii> st;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int p, l; cin >> p >> l; // 번호 p, 난이도 l
        st.insert({ l, p }); cache[p] = l;
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++)
    {
        string s; cin >> s;
        if (s == "add")
        {
            int p, l; cin >> p >> l;
            st.insert({ l, p });
        }
        else if (s == "recommend")
        {
            int x; cin >> x;
            if (x == 1)
            {
                auto to = *prev(st.end());
                cout << to.second << "\n";
            }
            else
            {
                auto to = *st.begin();
                cout << to.second << "\n";
            }
        }
        else
        {
            int p; cin >> p;
            int l = cache[p];
            st.erase({ l, p }); cache[p] = 0;
        }
    }
}