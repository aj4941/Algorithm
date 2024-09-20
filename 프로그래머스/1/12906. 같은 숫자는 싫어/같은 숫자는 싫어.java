import java.util.*;

public class Solution 
{
    ArrayList<Integer> list = new ArrayList<>();
    
    public int[] solution(int[] arr) {
        for (int val : arr)
        {
            if (list.size() == 0) 
                list.add(val);
            else if (list.get(list.size() - 1) != val) 
                list.add(val);
        }
        
        int[] ans = new int[list.size()];
        
        for (int i = 0; i < list.size(); i++)
            ans[i] = list.get(i);
        
        return ans;
    }
}