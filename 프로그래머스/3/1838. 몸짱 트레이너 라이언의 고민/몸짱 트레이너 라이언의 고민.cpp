#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
const int N = 2002;
int cnt[N];

bool calc(int x, int y, vector<pii> &pos, int len)
{
    for (auto to : pos)
    {
        int cx = to.first, cy = to.second;
        if (abs(cx - x) + abs(cy - y) < len)
            return false;
    }
    return true;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vi a) 
{
    memset(cnt, 0, sizeof cnt);
    
    for (auto to : a)
    {
        int l = to[0], r = to[1];
        cnt[l]++, cnt[r + 1]--;
    }
    
    int mx = 0;
    
    for (int i = 600; i < N; i++) 
    {
        cnt[i] += cnt[i - 1];
        mx = max(mx, cnt[i]);
    }

    if (mx == 1) 
        return 0;
    
    for (int len = 2 * n - 2; len >= 1; len--)
    {
        for (int x = 0; x < n; x++) for (int y = 0; y < n; y++)
        {
            vector<pii> pos; pos.push_back({ x, y });
            for (int x2 = x; x2 < n; x2++) for (int y2 = 0; y2 < n; y2++)
            {
                if (x2 == x && y2 <= y) continue;
                if (calc(x2, y2, pos, len)) pos.push_back({ x2, y2 });
                if (pos.size() == mx) return len;
            }
        }
    }
    
    return 0;
}