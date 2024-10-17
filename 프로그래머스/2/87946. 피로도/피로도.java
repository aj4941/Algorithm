import java.util.*;

class Solution 
{
    int[][] g = new int[10][5];
    boolean[] cache = new boolean[10];
    int k = -1, n = -1;
    int ans = 0;
    
    void dfs(int cur, int cnt)
    {
        ans = Math.max(ans, cnt);
        for (int i = 0; i < n; i++)
        {
            if (cache[i]) continue;
            if (cur >= g[i][0])
            {
                cache[i] = true;
                dfs(cur - g[i][1], cnt + 1);
                cache[i] = false;
            }
        }
    }
    
    public int solution(int K, int[][] d) 
    {
        k = K; n = d.length;
        for (int i = 0; i < n; i++) for (int j = 0; j < 2; j++)
            g[i][j] = d[i][j];
    
        for (int i = 0; i < n; i++)
        {
            if (k >= g[i][0])
            {
                cache[i] = true;
                dfs(k - g[i][1], 1);
                cache[i] = false;
            }
        }
        
        return ans;
    }
}