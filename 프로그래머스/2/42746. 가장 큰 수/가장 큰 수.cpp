#include <bits/stdc++.h>
using namespace std;

bool cmp(string &a, string &b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) 
{
    string ans = "";
    vector<string> v;
    for (auto to : numbers) v.push_back(to_string(to));
    sort(v.begin(), v.end(), cmp);
    for (auto to : v) ans += to;
    reverse(ans.begin(), ans.end());
    while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;
}