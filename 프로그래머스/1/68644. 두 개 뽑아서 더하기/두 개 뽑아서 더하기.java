import java.util.*;

class Solution 
{
    TreeSet<Integer> st = new TreeSet<>();
    
    public int[] solution(int[] a) 
    {
        int n = a.length;
        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++)
        {
            st.add(a[i] + a[j]);
        }
        
        int len = st.size();
        int[] ans = new int[len];
        for (int i = 0; i < len; i++)
            ans[i] = st.pollFirst();
        
        return ans;
    }
}