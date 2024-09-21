import java.util.*;

class Solution 
{
    int cmp(int v1, int v2)
    {
        String s1 = String.valueOf(v1);
        String s2 = String.valueOf(v2);
        int r1 = Integer.valueOf(s1 + s2);
        int r2 = Integer.valueOf(s2 + s1);
        if (r1 > r2) return -1;
        else if (r1 == r2) return 0;
        else return 1;
    }
    
    public String solution(int[] numbers) 
    {
        ArrayList<Integer> a = new ArrayList<>();
        for (int to : numbers) a.add(to);
        Collections.sort(a, (v1, v2) -> cmp(v1, v2));
        StringBuilder ans = new StringBuilder();
        
        for (int to : a)
            ans.append(to);
        
        String answer = ans.toString();
        
        if (answer.charAt(0) == '0')
            return "0";
        
        return answer;
    }
}