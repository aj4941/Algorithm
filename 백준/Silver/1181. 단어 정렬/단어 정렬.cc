#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    vector<pair<int, string>> v;
    set<string> s;
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        string st; cin >> st;
        auto iter = s.find(st);
        if(iter == s.end())
            v.push_back({ st.size(), st });
        s.insert(st);
    }
    sort(v.begin(), v.end());
    int size = v.size();
    for(int i = 0; i < size; i++)
        cout << v[i].second << "\n";
}