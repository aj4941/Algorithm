import java.util.*;

class Solution 
{
    Map<String, String> mp = new HashMap<>();
    ArrayList<String> res = new ArrayList<>();
    
    public String[] solution(String[] s) 
    {
        for (int i = 0; i < s.length; i++)
        {
            String[] t = s[i].split(" ");
            if (t[0].equals("Enter") || t[0].equals("Change"))
                mp.put(t[1], t[2]);
        }
        for (int i = 0; i < s.length; i++)
        {
            String[] t = s[i].split(" ");
            if (t[0].equals("Enter"))
                res.add(mp.get(t[1]) + "님이 들어왔습니다.");
            else if (t[0].equals("Leave"))
                res.add(mp.get(t[1]) + "님이 나갔습니다.");
        }
        
        String[] ans = new String[res.size()];
        for (int i = 0; i < res.size(); i++)
            ans[i] = res.get(i);
        
        return ans;
    }
}