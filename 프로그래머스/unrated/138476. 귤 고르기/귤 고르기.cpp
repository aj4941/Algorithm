#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 10000002;
map<int, int> mp;
vector<int> v;

int solution(int k, vector<int> a) 
{
    int ans = 0;
    int n = a.size();
    for (int i = 0; i < n; i++) mp[a[i]]++;
    for (auto to : mp)
        v.push_back(to.second);
    
    sort(v.rbegin(), v.rend());
    
    for (auto to : v)
    {
        k -= to; ans++;
        if (k <= 0)
            return ans;
    }
    
    return ans;
}