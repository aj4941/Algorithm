#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
	int n; cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		reverse(s[i].begin(), s[i].end());
	}
	
	int len = s[0].size();
	
	while (len > 0)
	{
		bool flag = true;
		unordered_map<string, bool> mp;
		for (int i = 0; i < n; i++)
		{
			if (mp.count(s[i]))
			{
				flag = false;
				break;
			}
			mp[s[i]] = true;
		}
		
		if (!flag)
			break;
			
		len--;
		
		for (int i = 0; i < n; i++)
			s[i].pop_back();
	}
	
	cout << len + 1;
	return 0;
}