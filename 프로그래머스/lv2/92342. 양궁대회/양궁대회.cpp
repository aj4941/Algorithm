#include <bits/stdc++.h>
using namespace std;
const int N = 11;
vector<int> sel(N, 0), ans(N, -1);
int diff = 0;

bool calc(vector<int> &a, vector<int> &b) // a < b ?
{
    for (int i = 10; i >= 0; i--)
    {
        if (b[i] > a[i])
            return true;
        else if (b[i] < a[i])
            return false;
    }
    return false;
}

void dfs(int idx, int rm, vector<int> &info)
{
    if (idx == 11) // end (idx : 0 ~ 10)
    {
        int a = 0, b = 0;
        for (int i = 0; i <= 10; i++)
        {
            if (info[i] == 0 && sel[i] == 0) continue;
            int value = 10 - i;
            if (info[i] < sel[i]) b += value;
            else a += value;
        }
        if (a < b)
        {
            if (diff < (b - a))
            {
                ans = sel;
                diff = b - a;
            }
            else if (diff == (b - a)) 
            {
                if (calc(ans, sel))
                    ans = sel;
            }
        }
        return;
    }
    if (idx == 10)
    {
        sel[idx] = rm;
        dfs(idx + 1, rm, info);
    }
    else 
    {
        for (int c = 0; c <= rm; c++)
        {
            sel[idx] = c;
            dfs(idx + 1, rm - c, info);
        }
    }
}

vector<int> solution(int n, vector<int> info) 
{
    dfs(0, n, info);
    if (ans[0] == -1) return { -1 };
    return ans;
}

// 11Hn (dfs)