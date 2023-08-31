#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll N = 100;
int bit[N];

vector<int> solution(vector<ll> numbers) 
{
    vector<int> ans;
    
    for (auto to : numbers)
    {
        int cnt = 0;
        ll sto = to;
        
        while (sto > 0)
        {
            sto /= 2;
            cnt++;
        }
        
        int b = 0;
        
        while ((1ll << b) - 1 < cnt) b++;
        ll sz = (1ll << b) - 1;
        // cout << "sz : " << sz << endl;
        for (ll i = 0; i < sz; i++)
        {
            if (to & (1ll << ((sz - 1) - i)))
                bit[i] = 1;
            else
                bit[i] = 0;
            
            // cout << i << ' ' << bit[i] << endl;
        }
        
        vector<int> v;
        
        for (int i = 0; i < sz; i += 2)
            v.push_back(i);
        
        bool hasAns = true;
        
        while (v.size() > 1) 
        {
            int idx = 0;
            vector<int> nv;
            
            while (idx < v.size())
            {
                int l = v[idx], r = v[idx + 1];
                int p = (l + r) / 2;
                
                // cout << l << ' ' << r << ' ' << bit[l] << ' ' << bit[r] << endl;
                if (bit[l] == 0 && bit[r] == 0)
                    nv.push_back(p);
                else
                {
                    if (bit[p] == 0)
                    {
                        // cout << "false : " << p << endl;
                        hasAns = false;
                        break;
                    }
                    else
                        nv.push_back(p);
                }
                
                idx += 2;
            }
            
            v = nv;
            
            if (!hasAns)
                break;
        }
        
        if (hasAns) ans.push_back(1);
        else ans.push_back(0);
    }
    
    return ans;
}