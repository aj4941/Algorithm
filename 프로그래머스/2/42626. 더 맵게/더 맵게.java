import java.util.*;

class Solution 
{
    int cmp(int v1, int v2)
    {
        if (v1 < v2) return -1;
        else if (v1 == v2) return 0;
        else return 1;
    }
    
    public int solution(int[] a, int k) 
    {
        int n = a.length;
        int ans = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(
            (o1, o2) -> cmp(o1, o2));
        
        for (int i = 0; i < n; i++)
            pq.add(a[i]);
        
        while (true)
        {
            if (pq.peek() >= k) return ans;
            if (pq.size() <= 1) return -1;
            
            int v1 = pq.peek(); pq.poll();
            int v2 = pq.peek(); pq.poll();
            ans++; pq.add(v1 + v2 * 2);
        }
    }
}