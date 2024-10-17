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
    static final int N = 102;
    ArrayList<Pair> []g = new ArrayList[N];
    int []dist = new int[N];
    
    int cmp(Pair a, Pair b)
    {
        if (a.w < b.w) return -1;
        else if (a.w == b.w) return 0;
        else return 1;
    }
    
    public int solution(int n, int[][] road, int k) 
    {
        for (int i = 1; i <= n; i++)
        {
            dist[i] = -1;
            g[i] = new ArrayList<>();
        }
        
        for (int i = 0; i < road.length; i++)
        {
            int u = road[i][0], v = road[i][1], w = road[i][2];
            g[u].add(new Pair(v, w));
            g[v].add(new Pair(u, w));
        }
        
        
        PriorityQueue<Pair> pq = new PriorityQueue<>((o1, o2) -> cmp(o1, o2));
        pq.add(new Pair(1, 0)); dist[1] = 0;
        
        while (!pq.isEmpty())
        {
            int w = pq.peek().w, v = pq.peek().v; pq.poll();
            if (dist[v] != w) continue;
            
            for (Pair p : g[v])
            {
                int nv = p.v, nw = p.w;
                if (dist[nv] == -1 || dist[v] + nw < dist[nv])
                {
                    dist[nv] = dist[v] + nw;
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