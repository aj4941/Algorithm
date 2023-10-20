#include <bits/stdc++.h>
using namespace std;
const int N = 1000002;
int p[N];

int find(int x)
{
    if (p[x] == x) return x;
    else return p[x] = find(p[x]);
}

int solution(string s)
{
    vector<char> stk;
    for (auto to : s)
    {
        if (stk.size() && stk.back() == to)
            stk.pop_back();
        else
            stk.push_back(to);
    }
    
    if (stk.size()) return 0;
    else return 1;
}