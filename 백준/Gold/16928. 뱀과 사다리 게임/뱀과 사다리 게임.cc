#include <bits/stdc++.h>
using namespace std;
int los[101];
int d[101];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int n1, n2;
		cin >> n1 >> n2;
		los[n1] = n2;
	}
	for (int i = 0; i < m; ++i)
	{
		int n1, n2;
		cin >> n1 >> n2;
		los[n1] = n2;
	}

	queue<int> q;
	memset(d, -1, sizeof(d));
	q.push(1);
	d[1] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 1; i <= 6; ++i)
		{
			int nx = x + i;
			if (nx > 100) continue;
			if (los[nx] != 0) {
				nx = los[nx];
			}
			if (d[nx] == -1) {
				d[nx] = d[x] + 1;
				q.push(nx);
			}
		}
	}
	cout << d[100] << "\n";
	return 0;
}