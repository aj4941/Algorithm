#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 10000000;

ll calc(ll n)
{
    if (n == 1) return 0;
    ll ans = 1;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (n / i <= N)
                return n / i;
            else
                ans = max(ans, i);
        }
    }
    
    return ans;
}

vector<int> solution(ll begin, ll end) 
{
    vector<int> ans;
    
    for (ll i = begin; i <= end; i++)
        ans.push_back(calc(i));
    
    return ans;
}