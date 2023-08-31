#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1002;
int cnt[N];

ll solution(vector<int> w) 
{
    ll ans = 0;
    
    for (auto to : w) cnt[to]++;
    
    for (auto to : w)
    {
        cnt[to]--;
        bool flag = false;
        ans += cnt[to];
        for (int x = 2; x <= 4; x++) for (int y = 2; y <= 4; y++)
        {
            if (x == y) continue;
            if ((to * x) % y || (to * x) / y >= N) continue;
            ans += cnt[(to * x) / y];
        }
    }
    
    return ans;
}