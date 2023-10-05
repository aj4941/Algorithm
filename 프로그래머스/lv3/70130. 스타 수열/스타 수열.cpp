#include <bits/stdc++.h>
using namespace std;
const int N = 500002;
vector<int> res[N];

int solution(vector<int> a) 
{
    int n = a.size();
    for (int i = 0; i < n; i++)
        res[a[i]].push_back(i);
    
    int ans = 0;
    
    for (int num = 0; num < n; num++)
    {
        int l = -1, tmp = 0;
        for (int i = 0; i < res[num].size(); i++)
        {
            int x = res[num][i];
            if (x - 1 == l)
            {
                if (i + 1 < res[num].size() && x + 1 == res[num][i + 1])
                {
                    l = x;
                    continue;
                }
                if (x + 1 == n)
                    continue;
                tmp += 2;
                l = x + 1;
            }
            else
            {
                tmp += 2;
                l = x;
            }
        }
        ans = max(ans, tmp);
    }
    
    return ans;
}