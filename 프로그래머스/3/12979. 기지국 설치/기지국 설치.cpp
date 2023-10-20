#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> st, int w)
{
    int idx = 0, ans = 0, x = 1;
    while (x <= n)
    {
        if (idx < st.size() && st[idx] - w <= x && x <= st[idx] + w)
        {
            x = st[idx] + w + 1;
            idx++;
        }
        else
        {
            ans++;
            x = x + 2 * w + 1;
        }
    }
    return ans;
}