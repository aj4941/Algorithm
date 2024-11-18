#include <stdio.h>
#include <string.h>

int main(void)
{
	int N, i, j;
	char s[100];
	char string[100];
	scanf("%d", &N);
	scanf("%s", s);
	for(i = 1; i < N; i++)
	{
		scanf("%s", string);
		for(j = 0; j < strlen(s); j++)
		if(s[j] != string[j])
			s[j] = '?';
	}
	
	for(i = 0; i < strlen(s); i++)
		printf("%c", s[i]);
		
	return 0;
}