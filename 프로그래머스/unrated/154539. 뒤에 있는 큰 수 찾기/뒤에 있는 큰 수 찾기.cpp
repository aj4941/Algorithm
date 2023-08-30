#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1000002;
int val[N], n;

vector<int> solution(vector<int> a) 
{
    n = a.size();
    vector<int> ans(n);
    vector<pii> tmp;
    
    for (int i = 0; i < n; i++)
    {
        val[i] = a[i];
        tmp.push_back({ a[i], i });
    }
    
    sort(tmp.rbegin(), tmp.rend());
    set<int> s;
    
    int j = 0;
    
    for (int i = 0; i < tmp.size(); i++)
    {
        auto it = s.lower_bound(tmp[i].second);
        if (it == s.end()) ans[tmp[i].second] = -1;
        else ans[tmp[i].second] = val[*it];
        if (i < (int)tmp.size() - 1)
        {
            if (tmp[i].first != tmp[i + 1].first)
            {
                for (int k = j; k <= i; k++)
                    s.insert(tmp[k].second);
                
                j = i + 1;
            }
        }
    }
    
    return ans;
}