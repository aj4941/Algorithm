#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> v) {
    
    multiset<int> ms;
    for (auto to : v)
    {
        char c = to[0];
        int num = stoi(to.substr(2));
        if (c == 'I')
            ms.insert(num);
        else
        {
            if (ms.size() == 0) continue;
            if (num == -1)
                ms.erase(ms.begin());
            else
                ms.erase(prev(ms.end()));
        }
    }
    vector<int> ans;
    if (ms.size() == 0) 
    {
        ans.push_back(0);
        ans.push_back(0);
    }
    else 
    {
        ans.push_back(*prev(ms.end()));
        ans.push_back(*ms.begin());
    }
    return ans;
}