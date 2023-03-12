#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int solution(vector<int> f, ll k) 
{
    vector<pii> v; k++;
    for (int i = 0; i < f.size(); i++)
        v.push_back({ f[i], i + 1 });
    
    sort(v.begin(), v.end());
    ll cur = 0, len = v.size();
    
    for (int i = 0; i < v.size(); i++)
    {
        ll d = v[i].first - cur;
        ll mv = d * len;
        if (k <= mv)
        {
            vector<int> res;
            for (int j = i; j < v.size(); j++)
                res.push_back(v[j].second);
            sort(res.begin(), res.end());
            return res[(k - 1) % len];
        }
        else
        {
            cur = v[i].first;
            k -= mv; len--;
        }
    }
    return -1;
}