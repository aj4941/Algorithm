#include <bits/stdc++.h>
using namespace std;

vector<int> parse(string s)
{
    stringstream sr(s);
    vector<int> v;
    string w;
    while (getline(sr, w, ' '))
        v.push_back(stoi(w));
    return v;
}

string solution(string s) 
{
    vector<int> v = parse(s);
    sort(v.begin(), v.end());
    string ans = "";
    ans += to_string(v.front()); ans += " ";
    ans += to_string(v.back());
    return ans;
}