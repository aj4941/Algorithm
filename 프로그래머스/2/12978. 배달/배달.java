import java.util.*;

class Pair {
    int v, w;
    
    public Pair(int v, int w) {
        this.v = v;
        this.w = w;
    }
}

class Solution 
{
    static final int N = 100;
    ArrayList<Pair>[] g = new ArrayList[N];
    int[] dist = new int[N];
    
    public int solution(int n, int[][] edge, int k) 
    {
        for (int i = 0; i <= n; i++)
        {
            g[i] = new ArrayList<>();
            dist[i] = (int)1e9;
        }
        
        int sz = edge.length;
        
        for (int i = 0; i < sz; i++)
        {
            int u = edge[i][0], v = edge[i][1], w = edge[i][2];
            g[u].add(new Pair(v, w));
            g[v].add(new Pair(u, w));
        }
        
        
        PriorityQueue<Pair> pq = new PriorityQueue<>(
            (o1, o2) -> (o1.w < o2.w) ? -1 : 1);
        
        dist[1] = 0; pq.add(new Pair(1, 0));
        
        while (!pq.isEmpty())
        {
            int v = pq.peek().v, d = pq.peek().w; pq.poll();
            if (dist[v] != d) continue;
            for (Pair to : g[v])
            {
                int nv = to.v, w = to.w;
                if (dist[v] + w < dist[nv])
                {
                    dist[nv] = dist[v] + w;
                    pq.add(new Pair(nv, dist[nv]));
                }
            }
        }
        
        int ans = 0;
        
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] <= k)
                ans++;
        }
        
        return ans;
    }
}