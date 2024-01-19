#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int T, N, C, i, j;
	int sumC = 0;
	double G;
	double sum = 0;
	scanf("%d", &T);
	
	for(i = 0; i < T; i++)
	{
		scanf(" %d", &N);
		for(j = 0; j < N; j++)
		{
			scanf(" %d %lf", &C, &G);
			sum += C * G;
			sumC += C;
		}
		printf("%d %.1lf\n", sumC, sum / sumC);
		sum = sumC = 0;
	}
}