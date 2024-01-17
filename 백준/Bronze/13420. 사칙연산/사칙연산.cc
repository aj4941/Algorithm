#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const ll inf = 1000000007;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        ll a, b, c;
        char r1, r2;
        cin >> a >> r1 >> b >> r2 >> c;
        bool hasAns = false;
        if (r1 == '*' && a * b == c) hasAns = true;
        if (r1 == '/' && a / b == c) hasAns = true;
        if (r1 == '-' && a - b == c) hasAns = true;
        if (r1 == '+' && a + b == c) hasAns = true;

        if (hasAns)
            cout << "correct" << "\n";
        else
            cout << "wrong answer" << "\n";
    }
}
