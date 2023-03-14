#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, int s) {
    
    if (n > s) return { -1 };
    
    int inc = s / n, rm = s % n;
    vector<int> ans;
    
    for (int i = 0; i < n - rm; i++)
        ans.push_back(inc);
    for (int i = 0; i < rm; i++)
        ans.push_back(inc + 1);
    
    return ans;
}