#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 987654321
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
#define INF 1000000007
const int N = 2000001;
string S, T;
int Z[N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    getline(cin, S); getline(cin, T);
    string s = T + '$' + S;
    int L = 0, R = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if (i > R)
        {
            L = R = i;
            while (R < s.size() && s[R] == s[R - L]) R++;
            Z[i] = R - L; R--;
        }
        else
        {
            if (Z[i - L] + i <= R) Z[i] = Z[i - L];
            else
            {
                L = i;
                while (R < s.size() && s[R] == s[R - L]) R++;
                Z[i] = R - L; R--;
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i < s.size(); i++)
    {
        if (Z[T.size() + i + 1] == T.size())
            ans.push_back(i + 1);
    }
    cout << ans.size() << "\n";
    for (int it : ans) cout << it << " ";
}