#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> op) 
{
    priority_queue<int> mn, mx;
    int sz = 0;
    for (auto to : op)
    {
        char c = to[0];
        int num = stoi(to.substr(2));
        if (c == 'I')
        {
            sz++;
            mx.push(num); mn.push(-num);
        }
        else
        {
            if (sz == 0) continue;
            if (num == 1) mx.pop();
            else if (num == -1) mn.pop();
            sz--;
            
            if (sz == 0)
            {
                while (mx.size()) mx.pop();
                while (mn.size()) mn.pop();
            }
        }
    }
    
    if (mn.size() == 0) 
        return { 0, 0 };
    else 
        return { mx.top(), -mn.top() };
}