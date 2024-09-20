import java.util.*;

class Solution 
{
    int ans = 0;
    int t = 0;
    ArrayList<Integer> a = new ArrayList<>();
    
    public void dfs(int i, int sum)
    {
        if (i == a.size())
        {
            if (sum == t)
                ans++;
            return;
        }
        
        dfs(i + 1, sum + a.get(i));
        dfs(i + 1, sum - a.get(i));
    }
    
    public int solution(int[] v, int target) {
        t = target;
        for (int to : v) a.add(to);
        dfs(0, 0);
        return ans;
    }
}