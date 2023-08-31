#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int per[4] = { 10, 20, 30, 40 };

struct Node {
    int p, price;
};

Node res[10];
int ans_pl = -1, ans_value = -1;

void dfs(int idx, vector<vector<int>> &a, vector<int> &e)
{
    if (idx == e.size())
    {
        int pl = 0, value = 0; 
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            int up = a[i][0], uprice = a[i][1];
            int uvalue = 0;
            for (int j = 0; j < e.size(); j++)
            {
                if (up <= res[j].p)
                    uvalue += res[j].price;
            }
            
            if (uvalue >= uprice) pl++;
            else value += uvalue;
        }
        
        if (ans_pl < pl)
        {
            ans_pl = pl;
            ans_value = value;
        }
        else if (ans_pl == pl)
        {
            if (ans_value < value)
                ans_value = value;
        }
        return;
    }
    
    for (int i = 0; i < 4; i++)
    {
        res[idx].p = per[i];
        res[idx].price = e[idx] * (100 - per[i]) / 100;
        dfs(idx + 1, a, e);
    }
}

vector<int> solution(vector<vector<int>> a, vector<int> e) 
{
    dfs(0, a, e);
    return { ans_pl, ans_value };
}