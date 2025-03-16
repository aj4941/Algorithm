#include <iostream>
#include <queue>
using namespace std;

int bfs(int check[500][500], int a, int b, int R, int C, int l)
{
	int count = 0;
	queue<int> rq;
	queue<int> cq;
	queue<int> srq;
	queue<int> scq;
	check[a][b] = 1;
	rq.push(a); cq.push(b);
	while(1)
	{
		int r = rq.front();
		int c = cq.front();
		rq.pop(); cq.pop();
		if(r == R && c == C)
			return count;
		if(r - 2 >= 0 && c - 1 >= 0 && check[r - 2][c - 1] == 0)
		{
			check[r - 2][c - 1] = 1;
			srq.push(r - 2); scq.push(c - 1);
			if(r - 2 == R && c - 1 == C)
				return count + 1;
		}
		if(r - 2 >= 0 && c + 1 < l && check[r - 2][c + 1] == 0)
		{
			check[r - 2][c + 1] = 1;
			srq.push(r - 2); scq.push(c + 1);
			if(r - 2 == R && c + 1 == C)
				return count + 1;
		}
		if(r + 2 < l && c - 1 >= 0 && check[r + 2][c - 1] == 0)
		{
			check[r + 2][c - 1] = 1;
			srq.push(r + 2); scq.push(c - 1);
			if(r + 2 == R && c - 1 == C)
				return count + 1;
		}
		if(r + 2 < l && c + 1 < l && check[r + 2][c + 1] == 0)
		{
			check[r + 2][c + 1] = 1;
			srq.push(r + 2); scq.push(c + 1);
			if(r + 2 == R && c + 1 == C)
				return count + 1;
		}
		if(r - 1 >= 0 && c - 2 >= 0 && check[r - 1][c - 2] == 0)
		{
			check[r - 1][c - 2] = 1;
			srq.push(r - 1); scq.push(c - 2);
			if(r - 1 == R && c - 2 == C)
				return count + 1;
		}
		if(r + 1 < l && c - 2 >= 0 && check[r + 1][c - 2] == 0)
		{
			check[r + 1][c - 2] = 1;
			srq.push(r + 1); scq.push(c - 2);
			if(r + 1 == R && c - 2 == C)
				return count + 1;
		}
		if(r - 1 >= 0 && c + 2 < l && check[r - 1][c + 2] == 0)
		{
			check[r - 1][c + 2] = 1;
			srq.push(r - 1); scq.push(c + 2);
			if(r - 1 == R && c + 2 == C)
				return count + 1;
		}
		if(r + 1 < l && c + 2 < l && check[r + 1][c + 2] == 0)
		{
			check[r + 1][c + 2] = 1;
			srq.push(r + 1); scq.push(c + 2);
			if(r + 1 == R && c + 2 == C)
				return count + 1;
		}
		if(rq.empty() && cq.empty())
		{
			while(!srq.empty())
			{
				rq.push(srq.front());
				srq.pop();
			}
			while(!scq.empty())
			{
				cq.push(scq.front());
				scq.pop();
			}
			count++;
		}
	}
}
int main(void)
{
	int check[500][500] = { 0 };
	int T, l, i, r, c, R, C;
	cin >> T;
	for(i = 0; i < T; i++)
	{
		cin >> l;
		cin >> r >> c;
		cin >> R >> C;
		cout << bfs(check, r, c, R, C, l) << endl;
		for(r = 0; r < l; r++)
		{
			for(c = 0; c < l; c++)
				check[r][c] = 0;
		}
	}
}