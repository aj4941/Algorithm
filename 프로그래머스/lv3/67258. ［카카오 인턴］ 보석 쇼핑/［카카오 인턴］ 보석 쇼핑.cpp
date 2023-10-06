#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
int ans_len = 1e9, ans_l = -1, ans_r = -1;
set<string> st;

vector<int> solution(vector<string> gems) 
{
    int n = gems.size();
    for (int i = 0; i < n; i++) st.insert(gems[i]);
    
    int total = st.size();
    int l = 0, r = 0; mp[gems[0]] = 1;
    int cnt = 1;
    
    while (true)
    {
        if (cnt == total)
        {
            // cout << l << ' ' << r << endl;
            int len = r - l + 1;
            if (len < ans_len)
            {
                ans_len = len;
                ans_l = l, ans_r = r;
            }
            if (mp[gems[l]] == 1) cnt--;
            mp[gems[l]]--; l++;
            
            if (l > r)
            {
                if (l == n) break;
                r = l; 
                mp[gems[r]] = 1; cnt = 1;
            }
        }
        else
        {
            if (r + 1 == n) break;
            r++;
            mp[gems[r]]++;
            if (mp[gems[r]] == 1) cnt++;
        }
    }
    
    return { ans_l + 1, ans_r + 1 };
}