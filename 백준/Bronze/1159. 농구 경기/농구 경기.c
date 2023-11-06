#include <stdio.h>

int main(void)
{
	int N, i;
	int flag = 0;
	char C[50];
	int A[150] = { 0 };
	scanf("%d", &N);
	for(i = 0; i < N; i++)
	{
		scanf("%s", C);
		A[C[0]]++;
	}
	
	for(i = 0; i < 150; i++)
	{
		if(A[i] >= 5)
		{
			printf("%c", i);
			flag = 1;
		}
	}
	if(flag == 0)
		printf("PREDAJA");
}