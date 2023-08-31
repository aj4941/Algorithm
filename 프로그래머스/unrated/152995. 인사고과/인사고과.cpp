#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n;

struct Node {
    int x, y, idx;
};

bool cmp(Node &a, Node &b)
{
    if (a.x != b.x)
        return a.x < b.x;
    
    return a.y < b.y;
}

int solution(vector<vector<int>> v) 
{
    vector<Node> tmp;
    multiset<int> ms;
    n = v.size();
    
    for (int i = 0; i < v.size(); i++)
    {
        int x = v[i][0], y = v[i][1];
        tmp.push_back({ x, y, i });
        ms.insert(y);
    }
    
    sort(tmp.begin(), tmp.end(), cmp);
    int j = 0;
    
    vector<pii> res;
    
    for (int i = 0; i < n; i++)
    {
        while (j < n && tmp[i].x == tmp[j].x)
        {
            auto it = ms.find(tmp[j].y);
            ms.erase(it);
            j++;
        }
        
        if (ms.size() == 0)
        {
            while (i < n)
            {
                res.push_back({ tmp[i].x + tmp[i].y, tmp[i].idx });
                i++;
            }
            break;
        }
        
        int mx = *prev(ms.end());
        
        if (tmp[i].y < mx)
        {
            if (tmp[i].idx == 0) 
                return -1;
            continue;
        }
        
        res.push_back({ tmp[i].x + tmp[i].y, tmp[i].idx });
    }
    
    sort(res.rbegin(), res.rend());
    
    int rank = 1;
    
    for (int i = 0; i < res.size(); i++)
    {
        // cout << i << ' ' << res[i].first << endl;
        int idx = res[i].second;
        if (i > 0) 
        {
            if (res[i - 1].first != res[i].first)
                rank = i + 1;
        }
        
        if (idx == 0)
            return rank;
    }
}