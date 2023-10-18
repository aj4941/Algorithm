#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int solution(vector<int> p, int loc) 
{
    int n = p.size();
    queue<pii> q;
    vector<int> r;
    for (int i = 0; i < n; i++)
    {
        q.push({ p[i], i });
        r.push_back(p[i]);
    }
    sort(r.begin(), r.end());
    int ans = 0;
    while (true)
    {
        ans++;
        while (true)
        {
            auto to = q.front(); q.pop();
            if (to.first == r.back())
            {
                if (loc == to.second)
                    return ans;
                r.pop_back();
                break;
            }
            else
                q.push(to);
        }
    }
    return ans;
}