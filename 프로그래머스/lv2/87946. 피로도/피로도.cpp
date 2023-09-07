#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;

int solution(int k, vi d) 
{
    int n = d.size();
    vector<int> p(n);
    int ans = 0;
    for (int i = 0; i < n; i++) p[i] = i;
    do {
        int sk = k;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int need = d[p[i]][0], cost = d[p[i]][1];
            if (sk >= need)
            {
                cnt++;   
                sk -= cost;
            }
        }
        
        ans = max(ans, cnt);
    } while (next_permutation(p.begin(), p.end()));
    
    return ans;
}