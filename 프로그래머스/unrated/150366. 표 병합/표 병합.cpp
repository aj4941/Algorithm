#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 52;
pii p[N][N];
string s[N][N];

pii find(pii x)
{
    if (p[x.first][x.second] == x)
        return x;
    else 
        return p[x.first][x.second] = find(p[x.first][x.second]);
}

string command;
int r, c, r1, c1, r2, c2;
string value, value1, value2;

int calc(string t)
{
    stringstream sr(t);
    vector<string> v;
    string w;
    while (getline(sr, w, ' '))
        v.push_back(w);
    
    command = v[0];
    if (command == "UPDATE")
    {
        if (v.size() == 4)
        {
            r = stoi(v[1]), c = stoi(v[2]);
            value = v[3];
            return 1;
        }
        else
        {
            value1 = v[1];
            value2 = v[2];
            return 2;
        }
    }
    else if (command == "MERGE")
    {
        r1 = stoi(v[1]), c1 = stoi(v[2]);
        r2 = stoi(v[3]), c2 = stoi(v[4]);
        return 3;
    }
    else if (command == "UNMERGE")
    {
        r = stoi(v[1]), c = stoi(v[2]);
        return 4;
    }
    else
    {
        r = stoi(v[1]), c = stoi(v[2]);
        return 5;
    }
}

vector<string> solution(vector<string> a) 
{
    for (int i = 1; i < N; i++) for (int j = 1; j < N; j++)
    {
        s[i][j] = "EMPTY";
        p[i][j] = pii(i, j);
    }
    
    vector<string> ans;
    
    for (auto to : a)
    {
        int cmd = calc(to);
        if (cmd == 1)
        {
            pii res = find(pii(r, c));
            r = res.first, c = res.second;
            s[r][c] = value;
        }
        else if (cmd == 2)
        {
            for (int i = 1; i < N; i++) for (int j = 1; j < N; j++)
            {
                pii res = find(pii(i, j));
                if (s[res.first][res.second] == value1)
                    s[res.first][res.second] = value2;
            }
        }
        else if (cmd == 3)
        {
            pii res1 = find(pii(r1, c1));
            pii res2 = find(pii(r2, c2));
                        
            if (res1.first == res2.first && res1.second == res2.second) continue;
            if (s[res1.first][res1.second] != "EMPTY")
                p[res2.first][res2.second] = p[res1.first][res1.second];
            else
                p[res1.first][res1.second] = p[res2.first][res2.second];
        }
        else if (cmd == 4)
        {
            pii par = find(pii(r, c));
            string par_s = s[par.first][par.second];
            cout << "par_s : " << par_s << endl;
            // cout << r << ' ' << c << endl;
            vector<pii> tmp;
            
            for (int i = 1; i < N; i++) for (int j = 1; j < N; j++)
            {
                pii res = find(pii(i, j));
                if (res.first == par.first && res.second == par.second)
                    tmp.push_back({ i, j });
            }
            
            for (auto to : tmp)
            {
                p[to.first][to.second] = to;
                s[to.first][to.second] = "EMPTY";
            }
            
            s[r][c] = par_s;
            // cout << "str : " << s[r][c] << endl;
        }
        else
        {
            pii res = find(pii(r, c));
            ans.push_back(s[res.first][res.second]);
        }
    }
    return ans;
}