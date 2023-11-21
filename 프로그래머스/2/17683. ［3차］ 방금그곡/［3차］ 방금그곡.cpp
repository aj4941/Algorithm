#include <bits/stdc++.h>
using namespace std;
unordered_map<string, char> mp;
vector<string> str = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#",
                     "A", "A#", "B" };
void init() 
{
    for (int i = 0; i < str.size(); i++)
        mp[str[i]] = (char)(i + 'a');
}

string fix(string s)
{
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (mp.count(s.substr(i, 2)))
        {
            res += mp[s.substr(i, 2)];
            i++;
            
            // cout << "s : " << mp[s.substr(i, 2)] << endl;
        }
        else
        {
            res += mp[string("") + s[i]];
        }
    }
    return res;
}

vector<string> parse(string s)
{
    stringstream sr(s);
    vector<string> v;
    string w;
    while (getline(sr, w, ','))
        v.push_back(w);
    
    return v;
}

int calc(string a, string b)
{
    int t1 = stoi(a.substr(0, 2)) * 60 + stoi(a.substr(3));
    int t2 = stoi(b.substr(0, 2)) * 60 + stoi(b.substr(3));
    return t2 - t1 + 1;
}

string solution(string m, vector<string> v) 
{
    init();
    int mx_d = -1;
    m = fix(m);
    cout << "m : " << m << endl;
    string ans = "";
    for (auto to : v) // 100
    {
        vector<string> res = parse(to);
        int d = calc(res[0], res[1]);
        string info = fix(res[3]);
        string tmp = "";
        for (int i = 0; i < d; i++) // 1000
            tmp += info[i % info.size()];
        
        int mlen = m.size();
        bool flag = false;
        
        for (int i = 0; i < tmp.size(); i++) // 1000
        {
            string s = tmp.substr(i, mlen); // 1000
            if (s == m)
            {
                flag = true;
                break;
            }
        }
        
        if (flag)
        {
            // cout << mx_d << ' ' << d << endl;
            if (mx_d < d)
            {
                mx_d = d;
                ans = res[2];
            }
        }
    }

    if (mx_d == -1)
        return "(None)";
    
    return ans;
}