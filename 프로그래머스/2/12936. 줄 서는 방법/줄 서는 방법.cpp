#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fac[50];
vector<int> num;

vector<int> solution(int n, ll k) 
{
    fac[0] = 1;
    for (int i = 1; i <= 20; i++) fac[i] = fac[i - 1] * i;
    for (int i = 1; i <= n; i++) num.push_back(i);    
    vector<int> ans;
    
    k--;
    
    for (int i = 0; i < n; i++)
    {
        int idx = 0;
        ll val = 0;
        while (true)
        {
            if (k >= val + fac[n - 1 - i])
            {
                val += fac[n - 1 - i];
                idx++;
            }
            else
                break;
        }
        k -= val;
        ans.push_back(num[idx]);
        num.erase(num.begin() + idx);
    }
    
    return ans;
}