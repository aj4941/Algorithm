#include <stdio.h>

int main(void)
{
	long long A, B, C, D;
	long long sum1 = 0, sum2 = 0;
	long long i = 1, j = 1;
	scanf("%lld %lld %lld %lld", &A, &B, &C, &D);
	
		while(B != 0)
		{
			sum1 += (B % 10) * i;
			B /= 10;
			i *= 10;
		}
		
		while(A != 0)
		{
			sum1 += (A % 10) * i;
			A /= 10;
			i *= 10;
		}
		
		while(D != 0)
		{
			sum2 += (D % 10) * j;
			D /= 10;
			j *= 10;
		}
		
		while(C != 0)
		{
			sum2 += (C % 10) * j;
			C /= 10;
			j *= 10;
		}
		
		printf("%lld", sum1 + sum2);
}