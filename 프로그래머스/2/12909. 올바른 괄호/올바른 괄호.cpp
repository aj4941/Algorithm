#include <bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    int n = s.size();
    bool hasAns = true;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(') cnt++;
        else cnt--;
        
        if (cnt < 0)
        {
            hasAns = false;
            break;
        }
    }
    
    return hasAns && (cnt == 0);
}