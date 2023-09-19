#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll calc(ll num)
{   
    ll idx = -1;
    
    for (ll i = 0; i < 60; i++)
    {
        if ((num & (1ll << i)) == 0) 
        {
            num += (1ll << i);
            idx = i;
            break;
        }
    }   
    
    for (ll i = idx - 1; i >= 0; i--)
    {
        if (num & (1ll << i))
        {
            num -= (1ll << i);
            return num;
        }
    }
}

vector<ll> solution(vector<ll> numbers) 
{
    vector<ll> ans;
    for (auto to : numbers)
        ans.push_back(calc(to));
    
    return ans;
}