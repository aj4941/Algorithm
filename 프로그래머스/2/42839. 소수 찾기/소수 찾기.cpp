#include <bits/stdc++.h>
using namespace std;
bool cache[10];
string s;
int ans = 0;
map<int, bool> chk;

void calc(string tmp)
{
    int val = stoi(tmp);
    if (chk.count(val) || val <= 1) return;
    chk[val] = true;
    for (int i = 2; i * i <= val; i++)
    {
        if (val % i == 0) 
            return;
    }
    ans++;
}

void dfs(string res)
{
    if (res != "") calc(res);
    for (int i = 0; i < s.size(); i++)
    {
        if (cache[i]) continue;
        cache[i] = true;
        dfs(res + s[i]);
        cache[i] = false;
    }
}

int solution(string number) 
{
    s = number;
    dfs("");
    return ans;
}