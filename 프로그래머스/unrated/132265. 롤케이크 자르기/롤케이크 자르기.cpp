#include <bits/stdc++.h>
using namespace std;
const int N = 10002;
int cntA[N], cntB[N];

int solution(vector<int> o) 
{
    int rA = 0, rB = 0;
    
    for (auto to : o) 
    {
        cntB[to]++;
        if (cntB[to] == 1)
            rB++;
    }
    
    int ans = 0;
    
    for (int i = 0; i < o.size(); i++)
    {
        cntB[o[i]]--;
        if (cntB[o[i]] == 0) rB--;
        cntA[o[i]]++;
        if (cntA[o[i]] == 1) rA++;
        
        // cout << rA << ' ' << rB << endl;
        
        if (rA == rB)
            ans++;
    }
    
    return ans;
}