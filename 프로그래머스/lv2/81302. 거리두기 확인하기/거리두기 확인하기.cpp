#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int dist[10][10][10][10];

vector<int> solution(vector<vector<string>> places) 
{
    vector<int> ans;
    for (auto &p : places)
    {
        bool hasAns = true;
        for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++) for (int l = 0; l < 5; l++)
                dist[i][j][k][l] = 1e9;
        
        vector<pii> pos;
        
        for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++)
        {
            dist[i][j][i][j] = 0;
            if (p[i][j] == 'X') continue;
            if (p[i][j] == 'P') pos.push_back({ i, j });
            for (int k = 0; k < 4; k++)
            {
                int ni = i + dx[k], nj = j + dy[k];
                if (ni < 0 || nj < 0 || ni >= 5 || nj >= 5) continue;
                if (p[ni][nj] == 'X') continue;
                dist[i][j][ni][nj] = 1;
            }
        }
        
        for (int k1 = 0; k1 < 5; k1++) for (int k2 = 0; k2 < 5; k2++) 
        {
            for (int x1 = 0; x1 < 5; x1++) for (int y1 = 0; y1 < 5; y1++)
            {
                for (int x2 = 0; x2 < 5; x2++) for (int y2 = 0; y2 < 5; y2++)
                {
                    if (dist[x1][y1][k1][k2] == 1e9 || dist[k1][k2][x2][y2] == 1e9) continue;
                    dist[x1][y1][x2][y2]
                        = min(dist[x1][y1][x2][y2], dist[x1][y1][k1][k2] + dist[k1][k2][x2][y2]);
                }
            }
        }
    
        for (int i = 0; i < pos.size(); i++) for (int j = i + 1; j < pos.size(); j++)
        {
            int x1 = pos[i].first, y1 = pos[i].second;
            int x2 = pos[j].first, y2 = pos[j].second;
            // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
            // cout << dist[x1][y1][x2][y2] << endl;
            if (dist[x1][y1][x2][y2] <= 2) hasAns = false;
        }
    
        if (hasAns) ans.push_back(1);
        else ans.push_back(0);
    }
    
    return ans;
}