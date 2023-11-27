#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int H = 60 * 60;
const int M = 60;

pii calc(int a, int b)
{
    return pii(a % b, b);
}

bool cmp(ll r, ll a, ll b)
{
    bool c1 = (r % a) * b <= (r % b) * a;
    bool c2 = ((r % a) + 1) * b > ((r % b) + 1) * a;
    return c1 && c2;
}

bool equal(pii a, pii b)
{
    return a.first * b.second == b.first * a.second;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) 
{
    int r1 = h1 * H + m1 * M + s1;
    int r2 = h2 * H + m2 * M + s2;
    int ans = 0;
    
    while (r1 < r2)
    {
        if (cmp(r1, 60, 60 * 60)) ans++;
        if (cmp(r1, 60, 60 * 60 * 12)) ans++;
        if (r1 == 0 || r1 == 60 * 60 * 12) ans--;
        r1++;
    }
    
    pii s = calc(r2, 60), m = calc(r2, 60 * 60), h = calc(r2, 60 * 60 * 12); 
    if (equal(s, m) || equal(s, h)) ans++;
    
    return ans;
}