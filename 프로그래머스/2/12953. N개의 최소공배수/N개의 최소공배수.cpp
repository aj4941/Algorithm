#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;

int solution(vi a) 
{
    int n = a.size();
    int ans = 1;
    for (int m = 2; m <= 100; m++)
    {
        for (int i = 0; i < 10; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (a[j] % m == 0) 
                    cnt++;
            }
            if (cnt >= 2)
            {
                ans *= m;
                for (int j = 0; j < n; j++)
                {
                    if (a[j] % m == 0)
                        a[j] /= m;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) ans *= a[i];
    
    return ans;
}