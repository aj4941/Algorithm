#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int dx[8] = { -1, 1, 0, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
unordered_map<string, bool> mpA, mpB;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<pair<int, string>> A, B;
    int n; cin >> n;
    cin.ignore();
    string s;
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        cin.clear();

        // cout << "result : " << s << endl;

        if (s.size() >= 6 && s.substr(0, 6) == "boj.kr")
        {
            // if (mpB.count(s)) continue;
            B.push_back({ stoi(s.substr(7)), s });
            // mpB[s] = true;
        }
        else
        {
            // if (mpA.count(s)) continue;
            A.push_back({s.size(), s});
            // mpA[s] = true;
        }
    }

    sort(A.begin(), A.end()); sort(B.begin(), B.end());

    for (auto to : A) cout << to.second << "\n";
    for (auto to : B) cout << to.second << "\n";
}