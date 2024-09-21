import java.util.*;

class Solution 
{
    public int solution(String s) 
    {
        int ans = (int)1e9;
        for (int len = 1; len <= s.length(); len++)
        {
            int res = 0;
            String prv = s.substring(0, len);
            int cnt = 1;
            for (int i = len; i < s.length(); i += len)
            {
                String tmp = s.substring(i, Math.min(i + len, s.length()));
                if (prv.equals(tmp))
                    cnt++;
                else
                {
                    res += len;
                    if (cnt > 1)
                        res += String.valueOf(cnt).length();
                    cnt = 1;
                }
                prv = tmp;
            }
            
            res += prv.length();
            if (cnt > 1)
                res += String.valueOf(cnt).length();
            ans = Math.min(ans, res);
        }
        
        return ans;
    }
}