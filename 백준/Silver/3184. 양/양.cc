#include <iostream>
using namespace std;

int R, C;
int sheep = 0, wolf = 0, o = 0, v = 0;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
char map[300][300];
int check[300][300] = { 0 };

void dfs(int x, int y)
{
	check[x][y] = 1;
	for(int i = 0; i < 4; i++)
	{
		int cx = x + dx[i]; int cy = y + dy[i];
		if(cx >= R || cx < 0 || cy >= C || cy < 0) continue;
		if(check[cx][cy] == 0 && map[cx][cy] != '#')
		{
			if(map[cx][cy] == 'v')
			{
				v++;
				dfs(cx, cy);
			}
			else if(map[cx][cy] == 'o')
			{
				o++;
				dfs(cx, cy);
			}
			else if(map[cx][cy] == '.')
				dfs(cx, cy);
		}
	}
}
int main(void)
{
	cin >> R >> C;
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			scanf(" %c", &map[i][j]);
			if(map[i][j] == 'v') wolf++;
			else if(map[i][j] == 'o') sheep++;
		}		
	}
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			if(check[i][j] == 0 && map[i][j] != '#')
			{
				if(map[i][j] == 'v') v++;
				if(map[i][j] == 'o') o++;
				dfs(i, j);
				if(o > v)
					wolf -= v;
				else
					sheep -= o;
				v = o = 0;
			}
		}
	}
	cout << sheep << " " << wolf;
}