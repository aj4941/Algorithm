import java.util.*;

class Solution 
{
    int cmp(String a, String b)
    {
        long r1 = Long.valueOf(a + b);
        long r2 = Long.valueOf(b + a);
        if (r1 > r2) return -1;
        else if (r1 == r2) return 0;
        else return 1;
    }
    
    public String solution(int[] a) 
    {
        int n = a.length;
        String[] str = new String[n];
        for (int i = 0; i < n; i++)
            str[i] = String.valueOf(a[i]);
        
        Arrays.sort(str, (o1, o2) -> cmp(o1, o2));
        
        String ans = "";
        for (int i = 0; i < n; i++)
            ans += str[i];
        
        if (ans.charAt(0) == '0')
            return "0";
        
        return ans;
    }
}