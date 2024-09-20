import java.util.*;

class Solution 
{
    public int[] solution(int[] array, int[][] commands) 
    {
        int n = commands.length, m = commands[0].length;
        int[] ans = new int[n];
        
        for (int i = 0; i < n; i++)
        {
            int x = commands[i][0] - 1, y = commands[i][1] - 1;
            int k = commands[i][2] - 1;
            int[] a = new int[y - x + 1];
            int idx = 0;
            for (int j = x; j <= y; j++)
                a[idx++] = array[j];
            
            Arrays.sort(a);
            ans[i] = a[k];
        }
        
        return ans;
    }
}