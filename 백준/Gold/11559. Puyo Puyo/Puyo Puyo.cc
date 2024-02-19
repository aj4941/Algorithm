#include <iostream>
#include <queue>
using namespace std;

char Map[20][20];
int count = 0;
int flag = 0;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
queue<pair<int,int>> q;

void BFS(int x, int y, int cache[20][20])
{
	cache[x][y] = 1;
	int result = 1;
	queue<pair<int,int>> check;
	check.push({ x, y });
	q.push({ x, y });
	
	while(!q.empty())
	{
		auto c = q.front(); q.pop();
		for(int i = 0; i < 4; i++)
		{
			int cx = c.first + dx[i]; int cy = c.second + dy[i];
			if(cx < 0 || cy < 0 || cx >= 12 || cy >= 6) continue;
			if(Map[c.first][c.second] == Map[cx][cy] && !cache[cx][cy])
			{
				cache[cx][cy] = 1;
				q.push({ cx, cy });
				check.push({ cx, cy });
				result++;
			}
		}
	}
	if(result >= 4)
	{
		flag = 1;
		while(!check.empty())
		{
			auto c = check.front(); check.pop();
			Map[c.first][c.second] = '.';
		}
	}
}
int main(void)
{
	int i, j;
	for(i = 0; i < 12; i++)
		scanf("%s", Map[i]);
	while(!flag)
	{
		int cache[20][20] = { 0 };
		for(i = 0; i < 12; i++) for(j = 0; j < 6; j++)
			if(Map[i][j] != '.') BFS(i, j, cache);
		if(flag) { count++; flag = 0; }
		else break;
		for(i = 11; i >= 0; i--) for(j = 0; j < 6; j++)
		{
			if(Map[i][j] == '.')
			{
				int ui = i; ui--;
				while(ui != -1)
				{
					if(Map[ui][j] != '.')
					{
						Map[i][j] = Map[ui][j];
						Map[ui][j] = '.';
						break;
					}
					ui--;
				}
			}
		}
	}
	cout << count;
}