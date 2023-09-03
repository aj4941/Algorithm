#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> order) 
{
    deque<int> dq;
    int ans = 0, idx = 0;
    
    for (int i = 1; i <= order.size(); i++)
    {
        if (dq.size() && dq.front() == order[idx])
        {
            // cout << "1" << endl;
            dq.pop_front(); idx++; i--;
            ans++;
        }
        else if (order[idx] == i)
        {
            // cout << "2" << endl;
            idx++; ans++;
        }
        else
        {
            // cout << 3 << endl;
            dq.push_front(i);
        }    
    }
    
    while (dq.size() && dq.front() == order[idx])
    {
        ans++; idx++;
        dq.pop_front();
    }
    
    return ans;
}