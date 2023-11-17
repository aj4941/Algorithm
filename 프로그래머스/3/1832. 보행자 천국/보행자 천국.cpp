#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
const ll inf = 20170805;
int dp[502][502][4];
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };
int M, N;

int solve(int x, int y, int c, vi &a)
{
    int &ret = dp[x][y][c];
    if (ret != -1) return ret;
    ret = 0;
    if (x == M - 1 && y == N - 1)
        return ret = 1;

    for (int i = 0; i < 2; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= M || ny >= N || a[nx][ny] == 1) continue;
        if (a[x][y] == 2 && c == i)
            ret += solve(nx, ny, i, a) % inf;
        else if (a[x][y] == 0)
            ret += solve(nx, ny, i, a) % inf;
        ret %= inf;
    }
    
    return ret % inf;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vi city_map) // m * n 
{
    M = m, N = n;
    memset(dp, -1, sizeof dp);
    return solve(0, 0, 0, city_map) % inf;
}