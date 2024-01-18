#include <bits/stdc++.h>
using namespace std;

const int MAX_FACTORIES = 10003;

int factoryCounts[MAX_FACTORIES];
int n;
int totalCost = 0;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> factoryCounts[i];

    for (int i = 1; i <= n; i++)
    {
        if(factoryCounts[i+1] > factoryCounts[i+2])
        {
            int count = min(factoryCounts[i], factoryCounts[i+1] - factoryCounts[i+2]);
            totalCost += 5 * count;

            factoryCounts[i] -= count;
            factoryCounts[i+1] -= count;

            int count2 = min(factoryCounts[i], min(factoryCounts[i+1], factoryCounts[i+2]));
            totalCost += 7 * count2;

            factoryCounts[i] -= count2;
            factoryCounts[i+1] -= count2;
            factoryCounts[i+2] -= count2;
        } 
        else
        { 
            int count = min(factoryCounts[i], min(factoryCounts[i+1], factoryCounts[i+2]));
            totalCost += 7 * count;

            factoryCounts[i] -= count;
            factoryCounts[i+1] -= count;
            factoryCounts[i+2] -= count;

            int count2 = min(factoryCounts[i], factoryCounts[i+1]);
            totalCost += 5 * count2;

            factoryCounts[i] -= count2;
            factoryCounts[i+1] -= count2;
        }
        totalCost += 3 * factoryCounts[i];
        factoryCounts[i] = 0;
    }

    cout << totalCost << '\n';
}