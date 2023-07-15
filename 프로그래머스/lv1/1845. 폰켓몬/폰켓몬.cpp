#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> a)
{
    set<int> st;
    for (auto to : a) st.insert(to);
    return min(a.size() / 2, st.size());
}