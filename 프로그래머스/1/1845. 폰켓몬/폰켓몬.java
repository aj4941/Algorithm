import java.util.*;

class Solution 
{
    Map<Integer, Integer> mp = new HashMap<>();
    public int solution(int[] a) 
    {
        int n = a.length;
        for (int i = 0; i < n; i++)
        {
            if (mp.containsKey(a[i])) continue;
            mp.put(a[i], 1);
        }
        
        return Math.min(n / 2, mp.size());
    }
}