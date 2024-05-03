#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<vector<char>> a;
vector<vector<string>> b
                        = { { "###", ".#.", "###", "###", "#.#", "###", "###", "###", "###", "###" },
                            { "#.#", ".#.", "..#", "..#", "#.#", "#..", "#..", "..#", "#.#", "#.#" },
                            { "#.#", ".#.", "###", "###", "###", "###", "###", "..#", "###", "###" },
                            { "#.#", ".#.", "#..", "..#", "..#", "..#", "#.#", "..#", "#.#", "..#" },
                            { "###", ".#.", "###", "###", "..#", "###", "###", "..#", "###", "###" }};

bool equal(int aidx, int bidx)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = aidx; j < aidx + 3; j++)
        {
            if (a[i][j] != b[i][bidx][j - aidx])
                return false;
        }
    }
    return true;
}

int calc(int idx)
{
    for (int i = 0; i <= 9; i++)
    {
        if (equal(idx, i))
            return i;
    }
    return -1;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    a.resize(5, vector<char>(n / 5 + 10));
    string s; cin >> s;
    int idx = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            a[i][j] = '.';
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 5; j < n / 5 + 5; j++)
        {
            a[i][j] = s[idx++];
//            cout << a[i][j];
        }
//        cout << endl;
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = n / 5 + 5; j < n / 5 + 10; j++)
        {
            a[i][j] = '.';
        }
    }

    string ans = "";

    for (int j = 0; j < n / 5 + 10; j++)
    {
        int res = calc(j);
        if (res != -1)
        {
            ans += res + '0';
        }
    }

    cout << ans;
}