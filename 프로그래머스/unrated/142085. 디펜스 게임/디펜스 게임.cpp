#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solution(int n, int k, vector<int> e)
{
    priority_queue<int> pq;
    for (int i = 0; i < e.size(); i++)
    {
        n -= e[i];
        pq.push(e[i]);
        if (n < 0)
        {
            while (n < 0 && k > 0 && pq.size())
            {
                n += pq.top();
                pq.pop(); k--;
            }
            
            if (n < 0)
                return i;
        }
    }
    
    return e.size();
}