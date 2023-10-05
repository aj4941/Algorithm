#include <bits/stdc++.h>
using namespace std;

string calc(int num)
{
    string res = "";
    while (num > 0)
    {
        res += (num % 2) + '0';
        num /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

vector<int> solution(string s) 
{
    vector<int> ans;
    int r = 0, cnt = 0;
    while (s != "1")
    {
        r++;
        int len = 0;
        for (auto to : s)
        {
            if (to == '0') cnt++;
            else len++;
        }
        if (len == 1) break;
        s = calc(len);
    }
    return { r, cnt };
}