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
vector<int> v;

bool calc(ll num)
{
    if (num == 1) // 1을 제외시켜야 함
        return false;
    for (ll i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k) 
{
    while (n > 0)
    {
        v.push_back(n % k);
        n /= k;
    }
    reverse(v.begin(), v.end()); // 뒤집어준 상태로 접근
    ll ans = 0, num = 0;
    for (auto to : v)
    {
        if (to == 0)
        {
            if (num == 0) continue;
            if (calc(num)) ans++;
            num = 0;
        }
        else
            num = num * 10 + to; // 앞에서부터 더해나갈 때 테크닉
    }
    if (num > 0 && calc(num)) ans++; // 마지막 처리
    return ans;
}