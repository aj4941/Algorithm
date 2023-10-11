#include <bits/stdc++.h>
using namespace std;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
const int N = 1002;
const int MAX = 500;
bool cache[N][N][5];
unordered_map<char, int> mp;

int solution(string d) 
{
    mp['U'] = 0, mp['R'] = 1, mp['D'] = 2, mp['L'] = 3;
    int x = 0, y = 0;
    int ans = 0;

    for (auto to : d)
    {
        int k = mp[to];
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < -5 || ny < -5 || nx > 5 || ny > 5) continue;
        if (!cache[x + MAX][y + MAX][k] && !cache[nx + MAX][ny + MAX][(k + 2) % 4])
            ans++;
        
        cache[x + MAX][y + MAX][k] = true;
        cache[nx + MAX][ny + MAX][(k + 2) % 4] = true;
        
        x = nx, y = ny;
    }

    return ans;
}