#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
#define INF 10987654321

int CCW(pii p1, pii p2, pii p3)
{
    int r1 = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    int r2 = p1.second * p2.first + p2.second * p3.first + p3.second * p1.first;
    if (r1 - r2 > 0) return 1; // 반시계
    if (r1 - r2 == 0) return 0; // 평행
    if (r1 - r2 < 0) return -1; // 시계
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    pii p1, p2, p3;
    cin >> p1.first >> p1.second;
    cin >> p2.first >> p2.second;
    cin >> p3.first >> p3.second;
    cout << CCW(p1, p2, p3);
}