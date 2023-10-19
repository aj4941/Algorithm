#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<string>> vs;
unordered_map<string, int> mp;

int solution(vs clothes) 
{
    for (auto to : clothes) mp[to[1]]++;
    int ans = 1;
    for (auto to : mp) ans *= (to.second + 1);
    return ans - 1;
}