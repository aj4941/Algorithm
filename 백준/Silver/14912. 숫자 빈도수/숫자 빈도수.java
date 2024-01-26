import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

import static java.lang.Math.max;

class pair {
    long x, y;
    public pair(long x, long y) {
        this.x = x;
        this.y = y;
    }
    public long first() {
        return x;
    }
    public long second() {
        return y;
    }
}

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer s; // new StringTokenizer(br.readLine());
        s = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(s.nextToken()), d = Integer.parseInt(s.nextToken());
        int ans = 0;

        for (int num = 1; num <= n; num++) {
            int n2 = num;
            while (n2 != 0) {
                if (n2 % 10 == d)
                    ans++;
                n2 /= 10;
            }
        }

        System.out.println(ans);
    }
}
