#include <bits/stdc++.h>
using namespace std;
const int N = 500002;
vector<int> v[N];
int n;

int solution(vector<int> a) {
    
    n = a.size();
    for (int i = 0; i < N; i++)
        v[i].push_back(-1);
    
    for (int i = 0; i < n; i++)
        v[a[i]].push_back(i);
    
    for (int i = 0; i < N; i++)
        v[i].push_back(n);
    
    int ans = 0;
    
    for (int i = 0; i < N; i++)
    {
        int res = 0, last = -1e9;
        int len = v[i].size();
        for (int j = 1; j < len - 1; j++)
        {
            int cv = v[i][j];
            int lv = v[i][j - 1], rv = v[i][j + 1];
            if (abs(cv - lv) != 1 && cv - 1 != last)
            {
                last = cv - 1;
                res++;
            }
            else if (abs(cv - rv) != 1 && cv + 1 != last)
            {
                last = cv + 1;
                res++;
            }
        }
        
        ans = max(ans, res * 2);
    }
    
    return ans;
}