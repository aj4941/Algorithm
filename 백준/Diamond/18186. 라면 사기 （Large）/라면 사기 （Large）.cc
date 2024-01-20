#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_FACTORIES = 1000003;

ll factoryCounts[MAX_FACTORIES];
ll n, b, c;
ll totalCost = 0;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> b >> c;
    for (int i = 1; i <= n; i++)
        cin >> factoryCounts[i];

    if (b < c)
    {
        for (int i = 1; i <= n; i++)
            totalCost += factoryCounts[i];
        
        cout << totalCost * b;
        return 0;
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (factoryCounts[i+1] > factoryCounts[i+2])
        {
            ll count = min(factoryCounts[i], factoryCounts[i+1] - factoryCounts[i+2]);
            totalCost += (b + c) * count;

            factoryCounts[i] -= count;
            factoryCounts[i+1] -= count;

            ll count2 = min(factoryCounts[i], min(factoryCounts[i+1], factoryCounts[i+2]));
            totalCost += (b + 2 * c) * count2;

            factoryCounts[i] -= count2;
            factoryCounts[i+1] -= count2;
            factoryCounts[i+2] -= count2;
        } 
        else
        { 
            ll count = min(factoryCounts[i], min(factoryCounts[i+1], factoryCounts[i+2]));
            totalCost += (b + 2 * c) * count;

            factoryCounts[i] -= count;
            factoryCounts[i+1] -= count;
            factoryCounts[i+2] -= count;

            ll count2 = min(factoryCounts[i], factoryCounts[i+1]);
            totalCost += (b + c) * count2;

            factoryCounts[i] -= count2;
            factoryCounts[i+1] -= count2;
        }
        totalCost += b * factoryCounts[i];
        factoryCounts[i] = 0;
    }

    cout << totalCost << '\n';
}