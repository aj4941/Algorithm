#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

struct Node {
    ll g, s, w, t;
};

bool cmp(Node &a, Node &b) {
    return a.t < b.t;
}

ll solution(int a, int b, vi g, vi s, vi w, vi t) 
{
    int n = g.size();
    vector<Node> v;
    for (int i = 0; i < n; i++)
        v.push_back({ g[i], s[i], w[i], t[i] });
    
    ll l = -1, r = 1e15;
    
    while (l + 1 < r)
    {
        ll mid = (l + r) / 2;
        ll gA = 0, gB = 0, sum = 0;
        
        for (int i = 0; i < n; i++)
        {
            ll cnt = mid / (v[i].t * 2);
            if (mid % (v[i].t * 2) >= v[i].t) cnt++;
            ll tmpA = min(cnt * v[i].w, v[i].g); 
            ll tmpB = min(cnt * v[i].w, v[i].s);
            gA += tmpA, gB += tmpB, sum += min(v[i].g + v[i].s, cnt * v[i].w);
        }
        
        if (gA >= a && gB >= b && sum >= a + b) r = mid;
        else l = mid;
    }
    
    return r;
}