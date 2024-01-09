#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int dx[6] = { -1, -1, 0, 0, 1, 1 };
int dy[6] = { -1, 0, -1, 1, 0, 1 };
int day[15] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int calc(string st)
{
    stringstream sr(st);
    vector<string> v;
    string w;
    while (getline(sr, w, ' '))
        v.push_back(w);

    int days = stoi(v[0]) * 365;
    for (int i = 1; i < stoi(v[1]); i++)
        days += day[i];
    days += stoi(v[2]);

    return days;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string a, b; getline(cin, a); getline(cin, b);

    int st = calc(a), ed = calc(b);

    cout << (ed - st) / 365 << "\n";

    int st_y = stoi(a.substr(0, 4)), ed_y = stoi(b.substr(0, 4));

    cout << ed_y - st_y + 1 << "\n";

    cout << ed_y - st_y;

}