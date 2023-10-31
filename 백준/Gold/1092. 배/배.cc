#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <string.h>
#include <stack>
using namespace std;

int main(void)
{
	stack<int> s, p;
	int Time = 0, count = 0; 
	int N, M;
	int c[100], b[12000];
	cin >> N;
	for(int i = 0; i < N; i++)
		scanf("%d", &c[i]);
	sort(c, c + N);
	cin >> M;
	for(int i = 0; i < M; i++)
		scanf("%d", &b[i]);
	sort(b, b + M);
	for(int i = 0; i < M; i++)
		s.push(b[i]);
	if(c[N - 1] < b[M - 1])
	{
		cout << "-1";
		return 0;
	}
	while(!s.empty())
	{
		Time++;
		for(int i = N - 1; i >= 0; i--)
		{
			if(c[i] >= s.top()) s.pop();
			else
			{
				p.push(s.top());
				s.pop();
				i++;
			}
			if(s.empty()) break;
		}
		while(!p.empty())
		{
			s.push(p.top());
			p.pop();
		}
	}
	cout << Time;
}