#include <iostream>
using namespace std;

int Point[4] = { 0, 0, 0, 0 };
int Paper[3000][3000] = { 0 };
void DivideConquer(int N, int r, int c)
{
	int i, j;
	int num = Paper[r][c];
	if(N == 1)
	{
		Point[num + 1]++;
		return;
	}
	for(i = r; i < r + N; i++) for(j = c; j < c + N; j++)
	{
		if(num != Paper[i][j])
		{
			DivideConquer(N / 3, r, c);
			DivideConquer(N / 3, r + N / 3, c);
			DivideConquer(N / 3, r + (N / 3) * 2, c);
			DivideConquer(N / 3, r, c + N / 3);
			DivideConquer(N / 3, r + N / 3, c + N / 3);
			DivideConquer(N / 3, r + (N / 3) * 2, c + N / 3);
			DivideConquer(N / 3, r, c + (N / 3) * 2);
			DivideConquer(N / 3, r + (N / 3), c + (N / 3) * 2);
			DivideConquer(N / 3, r + (N / 3) * 2, c + (N / 3) * 2);
			return;
		}
	}
	if(i == r + N && j == c + N)
	{
		Point[num + 1]++;
		return;
	}
	
}
int main(void)
{
	int N, i, j;
	cin >> N;
	for(i = 0; i < N; i++) for(j = 0; j < N; j++)
		scanf("%d", &Paper[i][j]);
		
	DivideConquer(N, 0, 0);
	for(i = 0; i <= 2; i++)
		printf("%d\n", Point[i]);
}