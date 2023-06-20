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
vector<int> v;

bool cmp(int &a, int &b)
{
    if (a % 2 && b % 2 == 0) return false;
    if (a % 2 == 0 && b % 2) return true;
    return a < b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int A, B, C; cin >> A >> B >> C;
    v.push_back(A); v.push_back(B); v.push_back(C);
    v.push_back(A * B); v.push_back(A * C); v.push_back(B * C);
    v.push_back(A * B * C);

    sort(v.begin(), v.end(), cmp);

    cout << v.back();
}