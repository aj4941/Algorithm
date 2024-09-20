import java.util.*;

class Solution 
{
    public int solution(int[] diff, int[] t, long lim) 
    {
        int n = diff.length;
        long l = 0, r = (long) 1e18;
        while (l + 1 < r)
        {
            long mid = (l + r) / 2;
            long res = 0;
            for (int i = 0; i < n; i++)
            {
                long prv_val = (i - 1 >= 0) ? t[i - 1] : 0;
                long cur = Math.max((long)diff[i] - (long)mid, 0) 
                    * ((long)t[i] + prv_val) + (long)t[i];
                res += cur;
            }
            
            if (res <= lim) r = mid;
            else l = mid;
        }
        
        return (int) r;
    }
}