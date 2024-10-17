import java.util.*;

class Solution 
{
    Deque<Integer> dq = new LinkedList<>();
    public int solution(int len, int w, int[] a) 
    {
        for (int i = 0; i < len; i++) 
            dq.addLast(0);
        
        int ans = 0;
        int idx = 0, cur = 0;
        
        while (true)
        {
            cur -= dq.getLast(); dq.removeLast();
            if (idx < a.length && cur + a[idx] <= w)
            {
                dq.addFirst(a[idx]);
                cur += a[idx++];
            }
            else
                dq.addFirst(0);
            ans++;
            
            if (cur == 0 && idx == a.length)
                break;
        }
        
        return ans;
    }
}