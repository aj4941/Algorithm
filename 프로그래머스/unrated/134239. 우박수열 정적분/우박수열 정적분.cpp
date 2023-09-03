#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<pii> v;

double calc(pii a, pii b)
{
    int x1 = a.first, y1 = a.second;
    int x2 = b.first, y2 = b.second;
    return (double)(y1 + y2) * abs(x1 - x2) / 2;
}

vector<double> solution(int k, vector<vector<int>> r) 
{
    int x = 0, y = k;
    while (true)
    {
        v.push_back({ x, y });
        if (y == 1) break;
        x++;
        if (y % 2 == 0) y /= 2;
        else y = y * 3 + 1;
    }
    
    int n = v.size();
    vector<double> psum(n);
    for (int i = 1; i < n; i++)
    {
        double res = calc(v[i], v[i - 1]);
        psum[i] = psum[i - 1] + res;
    }
    
    vector<double> ans;
    
    for (auto to : r)
    {
        int a = to[0], b = to[1];
        if (b <= 0) b = (n - 1) + b; 
        if (a > b) ans.push_back(-1);
        else ans.push_back(psum[b] - psum[a]);
    }
    
    return ans;
}