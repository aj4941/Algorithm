import java.util.*;

class Solution 
{
    public static final int N = 20002;
    ArrayList<Integer>[] g = new ArrayList[N];
    int[] dist = new int[N];
    int mx = -1, ans = 0;
    
    public int solution(int n, int[][] edge) 
    {
        for (int i = 1; i <= n; i++) 
        {
            dist[i] = -1;
            g[i] = new ArrayList<>();
        }
        
        for (int i = 0; i < edge.length; i++)
        {
            int u = edge[i][0], v = edge[i][1];
            g[u].add(v);
            g[v].add(u);
        }
        
        dist[1] = 0;
        Queue<Integer> q = new LinkedList<>(); q.add(1);

        while (!q.isEmpty())
        {
            int v = q.poll();
            if (mx < dist[v])
            {
                mx = dist[v];
                ans = 1;
            }
            else if (mx == dist[v])
                ans++;
            
            for (int nv : g[v])
            {
                if (dist[nv] != -1) continue;
                dist[nv] = dist[v] + 1;
                q.add(nv);
            }
        }
        
        return ans;
    }
}