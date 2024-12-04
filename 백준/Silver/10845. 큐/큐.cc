#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main(void)
{
    ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	queue<int> q;
	while(n--)
	{
	    string st; cin >> st;
	    if(st == "push")
	    {
	        int n; cin >> n;
	        q.push(n);
	    }
	    else if(st == "pop")
	    {
	        if(q.empty()) cout << "-1" << "\n";
	        else
	        {
	            cout << q.front() << "\n";
	            q.pop();
	        }
	    }
	    else if(st == "size")
	    {
	        cout << q.size() << "\n";
	    }
	    else if(st == "empty")
	    {
	        if(q.empty()) cout << "1" << "\n";
	        else cout << "0" << "\n";
	    }
	    else if(st == "front")
	    {
	        if(q.empty()) cout << "-1" << "\n";
	        else
	        {
	            
	            cout << q.front() << "\n";
	        }
	    }
	    else if(st == "back")
	    {
	        if(q.empty()) cout << "-1" << "\n";
	        else cout << q.back() << "\n";
	    }
	}
}