#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
set<pii> s;

string solution(string num, int k) 
{
    int n = num.size();
    int rm = n - k, ed = -1e9;
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        int x = num[i] - '0';
        s.insert({ -x, i });
        if (rm == n - i)
        {
            while (true)
            {
                pii tmp = *s.begin(); s.erase(s.begin());
                if (tmp.second < ed) continue;
                else
                {
                    ans += -tmp.first + '0';
                    ed = tmp.second;
                    break;
                }
            }
            rm--;
        }
    }
    
    return ans;
}