#include <bits/stdc++.h>
using namespace std;

int solution(string s) 
{
    int ans = 1e9;
    
    for (int len = 1; len <= s.size(); len++)
    {
        // if (s.size() % len) continue;
        int idx = 0, cnt = 0, val = 0;
        string res = "";
        
        while (true)
        {
            if (idx + len - 1 >= s.size())
            {
                val += s.substr(idx).size();
                break;
            }
            
            string tmp = s.substr(idx, len);
            // cout << res << ' ' << tmp << endl;
            if (res == tmp) cnt++;
            else 
            {
                if (cnt > 1)
                    val += to_string(cnt).size();
                val += res.size();
                res = tmp; cnt = 1;
            }
            idx += len;
        }
        
        // cout << cnt << ' ' << len << endl;
        
        if (cnt > 1)
            val += to_string(cnt).size();
        
        val += res.size();
        ans = min(ans, val);
    }

    return ans; 
}