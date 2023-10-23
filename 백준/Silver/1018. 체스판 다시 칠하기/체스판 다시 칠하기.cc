#include <iostream>
using namespace std;

int main(void)
{
	int N, M, i, j, r, c, t, count;
	int check = 0, min = 11111111;
	char flag[2] = { 'B' , 'W' };
	char Map[100][100];
	cin >> N >> M;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
			cin >> Map[i][j];
	}
	for(i = 0; i <= N - 8; i++)
	{
		for(j = 0; j <= M - 8; j++)
		{
			for(t = 0; t < 2; t++)
			{
				count = 0;
				if(t == 0)
					check = 0;
				else if(t == 1)
					check = 1;
				for(r = i; r < i + 8; r++)
				{
					for(c = j; c < j + 8; c++)
					{
						if(Map[r][c] != flag[check % 2])
							count++;
						check++;
					}
					check--;
				}
			if(min > count) min = count;
			}
		}
	}
	cout << min;
}