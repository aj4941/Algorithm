#include <bits/stdc++.h>
using namespace std;
const int N = 1000002;
int dist[N];

int solution(int x, int y, int n) 
{
    int ans = 0;
    memset(dist, -1, sizeof dist);
    dist[x] = 0;
    queue<int> q; q.push(x);
    while (!q.empty())
    {
        int v = q.front(); q.pop();
        if (v + n < N)
        {
            if (dist[v + n] == -1)
            {
                dist[v + n] = dist[v] + 1;
                q.push(v + n);
            }
        }
        if (v * 2 < N)
        {
            if (dist[v * 2] == -1)
            {
                dist[v * 2] = dist[v] + 1;
                q.push(v * 2);
            }
        }
        if (v * 3 < N)
        {
            if (dist[v * 3] == -1)
            {
                dist[v * 3] = dist[v] + 1;
                q.push(v * 3);
            }
        }
    }
    
    return dist[y];
}