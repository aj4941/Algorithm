#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> p;
unordered_map<string, int> cnt;
map<pair<string, string>, int> mp;

vector<string> parse(string s)
{
    stringstream sr(s);
    vector<string> v;
    string w;
    while (getline(sr, w, ' '))
        v.push_back(w);
    
    return v;
}

int solution(vector<string> f, vector<string> gifts) 
{
    for (auto to : gifts)
    {
        vector<string> v = parse(to);
        p[v[0]]++; p[v[1]]--;
        mp[{ v[0], v[1] }]++;
    }
    
    int ans = 0;
    
    for (int i = 0; i < f.size(); i++)
    {
        for (int j = i + 1; j < f.size(); j++)
        {
            string a = f[i], b = f[j];
            if (mp[{ a, b }] > mp[{ b, a }])
                cnt[a]++;
            else if (mp[{ a, b }] < mp[{ b, a }])
                cnt[b]++;
            else
            {
                if (p[a] > p[b]) cnt[a]++;
                else if (p[a] < p[b]) cnt[b]++;
            }
            
            ans = max(ans, max(cnt[a], cnt[b]));
        }
    }
    
    return ans;
}