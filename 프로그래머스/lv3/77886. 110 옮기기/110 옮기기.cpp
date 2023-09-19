#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> s) 
{
    vector<string> ans;
    for (auto st : s)
    {
        int n = st.size(), cnt = 0;
        vector<bool> cache(n, true);
        vector<int> v;
        
        for (int i = 0; i < n; i++)
        {
            if (st[i] == '0')
            {
                if (v.size() < 2)
                    v.clear();
                else
                {
                    cnt++;
                    cache[i] = cache[v[v.size() - 1]] = cache[v[v.size() - 2]] = false;
                    v.pop_back(); v.pop_back();
                }
            }
            else // '1'
                v.push_back(i);
        }
        
        string tmp = "";
        for (int i = 0; i < n; i++)
        {
            if (cache[i])
                tmp += st[i];
        }
        
        n = tmp.size();
        int idx = n;
        for (int i = 0; i < n - 1; i++)
        {
            if (tmp[i] == '1' && tmp[i + 1] == '1')
            {
                idx = i;
                break;
            }
        }
        
        if (idx == n)
        {
            if (tmp.back() == '1')
                idx = n - 1;
        }

        string res = "";
        for (int i = 0; i < idx; i++) res += tmp[i];
        for (int i = 0; i < cnt; i++) res += "110";
        for (int i = idx; i < n; i++) res += tmp[i];
        
        ans.push_back(res);
    }
    
    return ans;
} 