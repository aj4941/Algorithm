#include <bits/stdc++.h>
using namespace std;
string ans;
char ch[5] = { 'A', 'E', 'I', 'O', 'U' };
int cnt = 0, ans_cnt = 0;

void dfs(string tmp)
{
    if (tmp == ans)
    {
        ans_cnt = cnt;
        return;
    }
    
    if (tmp.size() == 5)
        return;
    
    for (int i = 0; i < 5; i++)
    {
        cnt++;
        dfs(tmp + ch[i]);
    }
}

int solution(string w) 
{
    ans = w; dfs("");
    return ans_cnt;
}