#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<pii> pos[30];
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

bool calc1(int x1, int y1, int x2, int y2, int bit, vector<string> &s)
{
    bit -= (1 << (s[x1][y1] - 'A'));
    while (true)
    {
        if (s[x1][y1] == '*') return false;
        if (s[x1][y1] != '.')
        {
            int num = s[x1][y1] - 'A';
            if (bit & (1 << num))
                return false;
        }
        if (x1 < x2) x1++;
        else if (x1 > x2) x1--;
        if (x1 == x2) break;
    }
    while (true)
    {
        if (s[x1][y1] == '*') return false;
        if (s[x1][y1] != '.')
        {
            int num = s[x1][y1] - 'A';
            if (bit & (1 << num))
                return false;
        }
        if (y1 < y2) y1++;
        else if (y1 > y2) y1--;
        if (y1 == y2) break;
    }
    return true;
}

bool calc2(int x1, int y1, int x2, int y2, int bit, vector<string> &s)
{
    bit -= (1 << (s[x1][y1] - 'A'));
    while (true)
    {
        if (s[x1][y1] == '*') return false;
        if (s[x1][y1] != '.')
        {
            int num = s[x1][y1] - 'A';
            if (bit & (1 << num))
                return false;
        }
        if (y1 < y2) y1++;
        else if (y1 > y2) y1--;
        if (y1 == y2) break;
    }
    while (true)
    {
        if (s[x1][y1] == '*') return false;
        if (s[x1][y1] != '.')
        {
            int num = s[x1][y1] - 'A';
            if (bit & (1 << num))
                return false;
        }
        if (x1 < x2) x1++;
        else if (x1 > x2) x1--;
        if (x1 == x2) break;
    }
    return true;
}

string solution(int m, int n, vector<string> s) 
{   
    int bit = 0;
    for (int i = 0; i < 30; i++) pos[i].clear();
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
    {
        if (s[i][j] == '*' | s[i][j] == '.') continue;
        int num = s[i][j] - 'A';
        pos[num].push_back({ i, j });
        bit |= (1 << num);
    }
    
    string ans = "";
    
    while (true)
    {
        bool flag = false;
        if (bit == 0) break;
        for (int i = 0; i < 26; i++)
        {
            if (bit & (1 << i))
            {
                int x1 = pos[i][0].first, y1 = pos[i][0].second;
                int x2 = pos[i][1].first, y2 = pos[i][1].second;
                if (calc1(x1, y1, x2, y2, bit, s) || calc2(x1, y1, x2, y2, bit, s))
                {
                    ans += (i + 'A');
                    bit -= (1 << i);
                    flag = true;
                    break;
                }
            }
        }
        
        if (!flag)
            break;
    }
    
    if (bit > 0) return "IMPOSSIBLE";
    else return ans;
}