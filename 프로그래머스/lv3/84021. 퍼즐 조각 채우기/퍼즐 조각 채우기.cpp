#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
bool Acache[100][100], Bcache[100][100];
int n, m;

void calc(vi &v, bool cache[100][100], vector<vector<pii>> &res, int val)
{
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        if (v[i][j] == val && !cache[i][j])
        {
            queue<pii> q; q.push({ i, j });
            cache[i][j] = true;
            res.push_back({}); res.back().push_back({ i, j });
            while (!q.empty())
            {
                auto to = q.front(); q.pop();
                int x = to.first, y = to.second;
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if (v[nx][ny] == 1 - val || cache[nx][ny]) continue;
                    res.back().push_back({ nx, ny });
                    q.push({ nx, ny }); cache[nx][ny] = true;
                }
            }
            
        }
    }
}

void delValue(vector<vector<pii>> &v)
{
    for (auto &to : v)
    {
        int mx = 1e9, my = 1e9;
        for (auto too : to)
        {
            int x = too.first, y = too.second;
            mx = min(mx, x), my = min(my, y);
        }
        for (auto &too : to)
            too.first -= mx, too.second -= my;
        
        sort(to.begin(), to.end());
    }
}

bool solve(vector<pii> &a, vector<pii> &b)
{
    int Mx = -1, My = -1;
    for (auto to : b)
        Mx = max(Mx, to.first), My = max(My, to.second);
    
    for (int i = 0; i < 4; i++)
    {
        for (auto &to : b)
        {
            int x = to.first, y = to.second;
            int nx = y, ny = Mx - x;
            to.first = nx, to.second = ny;
        }
        
        int mx = 1e9, my = 1e9;
        for (auto to : b)
            mx = min(mx, to.first), my = min(my, to.second);
        
        for (auto &to : b)
            to.first -= mx, to.second -= my;
        
        sort(b.begin(), b.end());
        
        if (a == b)
            return true;
    }
    return false;
}

int solution(vi a, vi b) 
{
    n = a.size(), m = a[0].size();
    vector<vector<pii>> A, B;
    calc(a, Acache, A, 0); calc(b, Bcache, B, 1);
    delValue(A); delValue(B);

    vector<bool> cache(B.size(), false);
    
    int ans = 0;
    
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            if (cache[j]) continue;
            if (solve(A[i], B[j]))
            {
                cache[j] = true;
                ans += A[i].size();
                break;
            }
        }
    }
    
    return ans;
}