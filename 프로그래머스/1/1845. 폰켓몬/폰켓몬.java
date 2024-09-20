import java.util.*;

class Solution 
{
    Map<Integer, Integer> mp = new HashMap<>();
    
    public int solution(int[] a) 
    {
        int ans = 0;
        int n = a.length;
        
        for (int val : a)
        {
            if (mp.containsKey(val))
                continue;
            else
            {
                mp.put(val, 1);
                ans++;
            }
        }
        
        return Math.min(n / 2, ans);
    }
}