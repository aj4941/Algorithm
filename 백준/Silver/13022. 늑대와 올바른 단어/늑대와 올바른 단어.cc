#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char ch[3] = { 'o', 'l', 'f' };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;
    int idx = 0;
    while (true)
    {
        if (idx == s.size())
            break;

        int cnt = 0;
        while (s[idx] == 'w') cnt++, idx++;
        
        if (cnt == 0)
        {
            cout << 0;
            return 0;
        }
        
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < cnt; k++)
            {
                if (idx == s.size() || ch[j] != s[idx++])
                {
                    cout << 0;
                    return 0;
                }
            }
        }
    }

    cout << 1;
}