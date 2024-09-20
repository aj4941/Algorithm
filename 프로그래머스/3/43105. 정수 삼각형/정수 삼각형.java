import java.util.*;

class Solution 
{
    static final int N = 502;
    int[][] a = new int[N][N];
    int[][] dp = new int[N][N];
    int n, m;
    
    public int solve(int x, int y)
    {
        if (dp[x][y] != -1) return dp[x][y];
        if (x == n) return dp[x][y] = 0;
        dp[x][y] = a[x][y];
        int res = Math.max(solve(x + 1, y), solve(x + 1, y + 1));
        dp[x][y] += res;
        return dp[x][y];
    }
    
    public int solution(int[][] v) 
    {
        n = v.length;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < v[i].length; j++)
            {
                a[i][j] = v[i][j];
                dp[i][j] = -1;
            }
        }
        return solve(0, 0);
    }
}