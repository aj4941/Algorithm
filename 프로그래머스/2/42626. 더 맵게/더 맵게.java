import java.util.*;

class Value {
    int val;
    public Value(int val) {
        this.val = val;
    }
}

class Solution 
{
    boolean cmp(int v1, int v2) {
        return v1 < v2;
    }
    
    PriorityQueue<Value> pq = new PriorityQueue<>(
        (o1, o2) -> cmp(o1.val, o2.val) ? -1 : 1);
    
    public int solution(int[] sc, int K) 
    {
        int ans = 0;
        int n = sc.length;
        
        for (int i = 0; i < n; i++)
            pq.add(new Value(sc[i]));
        
        while (pq.peek().val < K)
        {
            if (pq.size() < 2)
                return -1;
            
            int x = pq.poll().val, y = pq.poll().val;
            pq.add(new Value(x + y * 2));
            ans++;
        }
        
        return ans;
    }
}