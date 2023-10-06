#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solution(vector<int> a) 
{
    int n = a.size();
    vector<int> rmin(n + 1); 
    rmin[n] = 1e9 - 5;
    int lmin = 1e9 - 5;
    
    for (int i = n - 1; i >= 0; i--)
        rmin[i] = min(a[i], rmin[i + 1]);
    
    int ans = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (lmin > a[i] || rmin[i + 1] > a[i])
        {
            ans++;
            // cout << a[i] << ' ';
        }    
        
        lmin = min(lmin, a[i]);
    }
    
    return ans;
}