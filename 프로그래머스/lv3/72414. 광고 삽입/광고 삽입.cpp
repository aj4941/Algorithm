#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500002;
ll cnt[N];
ll psum[N];

int calc(string tmp)
{
    stringstream sr(tmp);
    vector<string> v;
    string w;
    while (getline(sr, w, ':'))
        v.push_back(w);
    
    int h = stoi(v[0]), m = stoi(v[1]), s = stoi(v[2]);
    return h * 3600 + m * 60 + s;
}

string rcalc(int res)
{
    int t = res / 3600; res %= 3600;
    int m = res / 60; res %= 60;
    int s = res;
    string ans = "";
    if (t < 10) ans += "0";
    ans += to_string(t), ans += ":";
    if (m < 10) ans += "0";
    ans += to_string(m), ans += ":";
    if (s < 10) ans += "0";
    ans += to_string(s);
    return ans;
}
string solution(string play_time, string adv_time, vector<string> logs) 
{
    int ed = calc(play_time), term = calc(adv_time);
    for (auto to : logs)
    {
        string ls = to.substr(0, 8);
        string rs = to.substr(9);
        int l = calc(ls), r = calc(rs);
        cnt[l]++; cnt[r]--;
    }
    
    for (int i = 1; i <= ed; i++) 
        cnt[i] += cnt[i - 1];
    
    for (int i = 1; i <= ed; i++)
        psum[i] = cnt[i] + psum[i - 1];
    
    int mx_time = -1;
    ll mx = -1;
    
    for (int i = term - 1; i <= ed; i++)
    {
        ll res = (i == term - 1) ? psum[i] : psum[i] - psum[i - (term - 1) - 1];
        if (mx < res)
        {
            mx = res;
            mx_time = i - (term - 1);
        }
    }
    
    return rcalc(mx_time);
}