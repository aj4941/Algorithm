#include <bits/stdc++.h>
using namespace std;
char cnum[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
               'A', 'B', 'C', 'D', 'E', 'F' };

vector<char> calc(int num, int n)
{
    if (num == 0) return { '0' };
    vector<char> ch;
    while (num > 0)
    {
        ch.push_back(cnum[num % n]);
        num /= n;
    }
    reverse(ch.begin(), ch.end());
    return ch;
}

string solution(int n, int t, int m, int p) 
{
    p = p - 1;
    string ans = "";
    int num = 0, turn = 0;
    while (true)
    {
        vector<char> ch = calc(num++, n);
        for (int i = 0; i < ch.size(); i++)
        {
            if (turn == p) 
            {
                ans += ch[i];
                if (ans.size() == t)
                    return ans;
            }
            turn = (turn + 1) % m;
        }
    }
}