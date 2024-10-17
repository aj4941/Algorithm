import java.util.*;

public class Solution 
{
    Queue<Integer> q = new LinkedList<>();
    
    public int[] solution(int[] a) 
    {
        int n = a.length;
        for (int i = 0; i < n; i++)
        {
            if (q.size() == 0)
                q.add(a[i]);
            else if (a[i - 1] != a[i])
                q.add(a[i]);
        }
        
        int[] ans = new int[q.size()];
        int idx = 0;
        
        while (!q.isEmpty())
        {
            ans[idx++] = q.peek();
            q.poll();
        }
        
        return ans;
    }
}