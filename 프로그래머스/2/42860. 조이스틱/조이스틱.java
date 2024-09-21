import java.util.*;

class Solution 
{    
    public int solution(String s) 
    {
        int n = s.length();
        ArrayList<Integer> v = new ArrayList<>();
        int ans = 0;
        
        for (int i = 0; i < n; i++)
        {
            ans += Math.min(s.charAt(i) - 'A', ('A' - s.charAt(i) + 26) % 26);
            if (i > 0 && s.charAt(i) != 'A') 
                v.add(i);
        }
        
        if (v.size() == 0)
            return ans;
        
        int res = Math.min(v.get(v.size() - 1), n - v.get(0));
        
        for (int i = 0; i < v.size(); i++)
        {
            int li = v.get(i), ri = v.get((i + 1) % v.size());
            int v1 = li * 2 + (n - ri);
            int v2 = (n - ri) * 2 + li;
            res = Math.min(res, Math.min(v1, v2));
        }
        
        return ans + res;
    }
}
