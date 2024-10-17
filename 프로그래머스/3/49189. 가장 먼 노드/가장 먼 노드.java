import java.util.*;

class Solution 
{
    static final int N = 20002;
    ArrayList<Integer>[] g = new ArrayList[N];
    int[] dist = new int[N];
    
    public int solution(int n, int[][] edge) 
    {
        for (int i = 1; i <= n; i++)
        {
            dist[i] = -1;
            g[i] = new ArrayList<>();
        }
        
        int ans = 0;
        int len = edge.length;
        for (int i = 0; i < len; i++)
        {
            int u = edge[i][0], v = edge[i][1];
            g[u].add(v); g[v].add(u);
        }
        
        Queue<Integer> q = new LinkedList<>(); 
        q.add(1); dist[1] = 0;
        while (!q.isEmpty())
        {
            int v = q.peek(); q.poll();
            for (int nv : g[v])
            {
                if (dist[nv] == -1)
                {
                    dist[nv] = dist[v] + 1;
                    q.add(nv);
                }
            }
        }
        
        int mx = -1, cnt = 0;
        for (int v = 1; v <= n; v++)
        {
            if (mx < dist[v])
            {
                mx = dist[v];
                cnt = 1;
            }
            else if (mx == dist[v])
                cnt++;
        }
        
        return cnt;
    }
}