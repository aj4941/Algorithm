#include <bits/stdc++.h>
using namespace std;
const int N = 3000;
int psum[N];
unordered_map<int, int> mp;

int solution(vector<int> v) 
{
    int n = v.size();
    for (int i = 1; i <= n; i++)
    {
        psum[i] = psum[i - 1] + v[i - 1];
        mp[psum[i]] = 1;
    }  
    
    int ans = 0;
    
    for (int l = 1; l <= n; l++)
    {
        for (int i = l; i <= n; i++)
        {
            int Sum = psum[i] - psum[l - 1];
            if (mp.count(psum[l - 1] + 2 * Sum))
                ans = max(ans, Sum);
        }
    }
    
    return ans;
}