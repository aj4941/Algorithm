#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> num;
vector<char> op;
char ch[3] = { '+', '-', '*' };

void parse(string s)
{
    ll val = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if ('0' <= s[i] && s[i] <= '9')
            val = val * 10 + (s[i] - '0');
        else
        {
            num.push_back(val);
            op.push_back(s[i]);
            val = 0;
        }
    }
    num.push_back(val);
}

ll calc(ll x, ll y, char c)
{
    if (c == '-') return x - y;
    if (c == '+') return x + y;
    if (c == '*') return x * y;
}

ll solution(string exp) 
{
    ll ans = 0; parse(exp);
    vector<int> p = { 0, 1, 2 };

    do {
        vector<ll> s_num = num;
        vector<char> s_op = op;
        ll res = 0;
        for (int k = 0; k < 3; k++)
        {
            for (int i = 0; i < s_op.size(); i++)
            {
                if (s_op[i] == ch[p[k]])
                {
                    ll val = calc(s_num[i], s_num[i + 1], s_op[i]);
                    s_num.erase(s_num.begin() + i + 1);
                    s_num.erase(s_num.begin() + i);
                    s_num.insert(s_num.begin() + i, val);
                    s_op.erase(s_op.begin() + i);
                    i--;
                }
            }
        }
        ans = max(ans, abs(s_num[0]));
        
    } while(next_permutation(p.begin(), p.end()));
    
    return ans;
}