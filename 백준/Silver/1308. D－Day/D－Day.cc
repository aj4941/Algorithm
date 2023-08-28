#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int M[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool check(int y)
{
    if (y % 4 == 0)
    {
        if (y % 400 == 0 || y % 100 != 0)
            return true;

        return false;
    }
    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int cy, cm, cd; cin >> cy >> cm >> cd;
    int y, m, d; cin >> y >> m >> d;
    if (y - cy > 1000)
    {
        cout << "gg";
        return 0;
    }
    if (y - cy == 1000)
    {
        if (m > cm)
        {
            cout << "gg";
            return 0;
        }
        else if (m == cm)
        {
            if (d >= cd)
            {
                cout << "gg";
                return 0;
            }
        }
    }

    int ans = 0;

    while (true)
    {
        if (y == cy && m == cm && d == cd)
        {
            cout << "D-" << ans;
            return 0;
        }

        ans++; cd++;
        bool flag = check(cy);

        if (flag) M[2]++;

        if (M[cm] < cd)
        {
            cm++;
            cd = 1;
        }
        if (cm == 13)
        {
            cy++;
            cm = 1;
        }

        if (flag) M[2]--;
    }
}
