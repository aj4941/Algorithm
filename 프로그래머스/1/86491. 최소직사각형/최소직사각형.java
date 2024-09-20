import java.util.*;

class Solution 
{
    public int solution(int[][] sizes) 
    {
        int n = sizes.length;
        int ans = 0;
        int l = 0, r = 0;
        for (int i = 0; i < n; i++)
        {
            if (sizes[i][0] < sizes[i][1])
            {
                int tmp = sizes[i][0];
                sizes[i][0] = sizes[i][1];
                sizes[i][1] = tmp;
            }
            
            l = Math.max(l, sizes[i][0]);
            r = Math.max(r, sizes[i][1]);
        }
        
        return l * r;
    }
}