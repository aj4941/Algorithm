class Solution 
{
    public static final int N = 300;
    int[] p = new int[N];
    int n;
    
    public int find(int x)
    {
        if (p[x] == x) return x;
        else return p[x] = find(p[x]);
    }
    
    public int solution(int N, int[][] edge) 
    {
        n = N;
        for (int i = 1; i <= n; i++) p[i] = i;
        
        int sz = edge.length;
        
        for (int i = 0; i < sz; i++) for (int j = 0; j < sz; j++)
        {
            if (edge[i][j] == 1)
            {
                int u = i + 1, v = j + 1;
                u = find(u); v = find(v);
                if (u == v) continue;
                p[u] = v;
            }
        }
        
        int ans = 0;
        
        for (int i = 1; i <= n; i++)
        {
            if (p[i] == i)
                ans++;
        }
        
        return ans;
    }
}