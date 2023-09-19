#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<string, string> mp;
unordered_map<string, int> val;

vector<int> solution(vector<string> enroll,
                     vector<string> referral,
                     vector<string> seller, vector<int> amount) 
{
    int n = enroll.size(), m = seller.size();
    
    for (int i = 0; i < n; i++)
        mp[enroll[i]] = referral[i]; // 자식 -> 부모
    
    for (int i = 0; i < m; i++)
    {
        int value = amount[i] * 100;
        string s = seller[i];
        while (value > 0)
        {
            val[s] += value - (value / 10);  
            value /= 10;
            if (s == "-") break;
            s = mp[s];
        }
    }
    
    vector<int> ans;
    
    for (int i = 0; i < n; i++) 
        ans.push_back(val[enroll[i]]);
    
    return ans;
}