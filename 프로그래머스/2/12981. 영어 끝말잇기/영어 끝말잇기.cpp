#include <bits/stdc++.h>
using namespace std;
unordered_map<string, bool> mp;

vector<int> solution(int n, vector<string> words) 
{
    int num = 1, turn = 1;
    string cur = words[0]; mp[cur] = true;
    for (int i = 1; i < words.size(); i++)
    {
        if (mp.count(words[i]) || (cur.back() != words[i].front()))
            return { num + 1, turn };
        
        mp[words[i]] = true; cur = words[i];
        num = (num + 1) % n;
        if (num == 0) turn++;
    }
    
    return { 0, 0 };
}