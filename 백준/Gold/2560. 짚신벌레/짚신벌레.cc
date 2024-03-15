#include <bits/stdc++.h>
using namespace std;
const int inf = 1000;

int main(void) 
{
	int a, b, d, n; 
	cin >> a >> b >> d >> n;
	int sz = d;
	vector<int> v(sz); v[0] = 1;
	int st = 0, res = 0;
	
	for (int i = 0; i < n; i++)
	{
		a = (a - 1 + sz) % sz;
		b = (b - 1 + sz) % sz;
		d = (d - 1 + sz) % sz;
		st = (st - 1 + sz) % sz;
		
		v[d] = 0;
		res += v[a]; res %= inf;
		res = (res - v[b] + inf) % inf;
		
		v[st] += res; v[st] %= inf;
	}
	
	int ans = 0;
	
	for (int i = 0; i < sz; i++)
	{
		ans += v[i];
		ans %= inf;
	}
	
	cout << ans;
}