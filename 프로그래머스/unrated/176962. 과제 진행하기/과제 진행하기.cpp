#include <bits/stdc++.h>
using namespace std;

struct Node {
    int t, rm;
    string str;
};

bool cmp(Node &a, Node &b)
{
    return a.t < b.t;
}

Node dummy = { -1, -1, "-1" };

vector<string> solution(vector<vector<string>> plans)
{
    vector<Node> tmp;

    for (auto to : plans)
    {
        string r1 = to[0], r2 = to[1], r3 = to[2];
        // cout << r1 << ' ' << r2 << ' ' << r3 << endl;
        stringstream sr(r2);
        string w;
        vector<string> v;
        while (getline(sr, w, ':'))
            v.push_back(w);

        // cout << "ok" << endl;

        int t = stoi(v[0]) * 60 + stoi(v[1]);
        int rm = stoi(r3);
        string str = r1;
        tmp.push_back({ t, rm, str });
    }
    
    // cout << "ok" << endl;
    sort(tmp.begin(), tmp.end(), cmp);

    deque<Node> q, sq;
    
    for (auto to : tmp) 
    {
        // cout << to.t << ' ' << to.rm << ' ' << to.str << endl;
        q.push_back(to);
    }

    Node cur = dummy;
    int t = 0;

    vector<string> ans;

    while (t < 24 * 60)
    {
        // cout << t << endl;
        // cout << "current : " << cur.t << ' ' << cur.rm << ' ' << cur.str << ' ' << t << endl;
        if (cur.t != -1)
        {
            if (q.size() && t == q.front().t)
            {
                sq.push_front(cur);
                cur = q.front(); q.pop_front(); cur.rm--;
                if (cur.rm == 0)
                {
                    // cout << "case 1" << ' ' << cur.str << endl;
                    ans.push_back(cur.str);
                    cur = dummy;
                }
            }
            else
            {
                cur.rm--;
                if (cur.rm == 0)
                {
                    // cout << "cur.str : " << cur.str << endl;
                    ans.push_back(cur.str);
                    cur = dummy;
                }
            }
        }
        else
        {
            if (q.size() && t == q.front().t)
            {
                cur = q.front(); q.pop_front();
                cur.rm--;
                if (cur.rm == 0)
                {
                    // cout << "Case 2" << ' ' << cur.str << endl;
                    ans.push_back(cur.str);
                    cur = dummy;
                }
            }
            else if (sq.size())
            {
                cur = sq.front(); sq.pop_front();
                cur.rm--;
                if (cur.rm == 0)
                {
                    // cout << "case 3" << ' ' << cur.str << endl;
                    ans.push_back(cur.str);
                    cur = dummy;
                }
            }
        }
        t++;
    }
    
    // cout << "cur : " << cur.str << endl;
    
    if (cur.t != -1)
        ans.push_back(cur.str);
    
    while (sq.size())
    {
        // cout << "sq : " << sq.front().str << endl;
        ans.push_back(sq.front().str);
        sq.pop_front();
    }

    return ans;
}