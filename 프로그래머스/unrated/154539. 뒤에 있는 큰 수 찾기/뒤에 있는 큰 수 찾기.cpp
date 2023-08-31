#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n;

vector<int> solution(vector<int> a) 
{
    n = a.size();
    vector<int> ans(n);
    deque<int> dq;
    for (int i = n - 1; i >= 0; i--)
    {
        if (dq.size() == 0)
        {
            ans[i] = -1;
            dq.push_front(a[i]);
        }
        else
        {
            while (dq.size())
            {
                if (a[i] < dq.front())
                {
                    ans[i] = dq.front();
                    dq.push_front(a[i]);
                    break;
                }
                else
                    dq.pop_front();
            }
            
            if (dq.size() == 0)
            {
                ans[i] = -1;
                dq.push_front(a[i]);
            }
        }
    }
    
    return ans;
}