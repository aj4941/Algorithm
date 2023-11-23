#include <iostream>
#include <cmath>
using namespace std;
 
int main(void)
{
	int n;
	int a[1000] = { 0 };
	long long dp[1000] = { 0 };
	cin >> n;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
		dp[i] = max(dp[i - 3] + a[i - 1] + a[i], dp[i - 2] + a[i]);
	cout << dp[n];
}