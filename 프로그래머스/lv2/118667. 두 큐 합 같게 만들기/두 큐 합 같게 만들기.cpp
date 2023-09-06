#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> vii;
typedef vector<int> vi;
// ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
#define inf 1000000007
const int N = 700002;
bool cache[N];

int solution(vector<int> queue1, vector<int> queue2) 
{
    int ans = 0;
    ll sum1 = 0, sum2 = 0;
    deque<int> q1, q2;
    int idx = 0;
    for (auto to : queue1)
    {
        q1.push_back(to);
        sum1 += to;
    }
    for (auto to : queue2)
    {
        q2.push_back(to);
        sum2 += to;
    }
    
    while (sum1 != sum2 && ans < 2 * N)
    {
        if (sum1 < sum2)
        {
            int f = q2.front(); q2.pop_front(); sum2 -= f;
            q1.push_back(f); sum1 += f;
        }
        else
        {
            int f = q1.front(); q1.pop_front(); sum1 -= f;
            q2.push_back(f); sum2 += f;
        }
        ans++;
    }
    
    if (ans == 2 * N) ans = -1;
    return ans;
}