#include <stdio.h>
#include <string.h>
void Rplus(char U[3][3], char D[3][3], char F[3][3], char B[3][3], char L[3][3], char R[3][3])
{	
	int i, j, k;
	char temp[3][3];
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
			temp[j][2 - i] = R[i][j];
	}
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
			R[i][j] = temp[i][j];
	}
	for(k = 0; k < 3; k++)
		temp[k][2] = U[k][2];
	for(k = 0; k < 3; k++)
		U[k][2] = F[k][2];
	for(k = 0; k < 3; k++)
		F[k][2] = D[k][2];
	for(k = 0; k < 3; k++)
		D[k][2] = B[2 - k][0];
	for(k = 0; k < 3; k++)
		B[2 - k][0] = temp[k][2];
}

void Lplus(char U[3][3], char D[3][3], char F[3][3], char B[3][3], char L[3][3], char R[3][3])
{	// OK
	int i, j, k;
	char temp[3][3];
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
			temp[j][2 - i] = L[i][j];
	}
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
			L[i][j] = temp[i][j];
	}
	for(k = 0; k < 3; k++)
		temp[k][0] = U[k][0];
	for(k = 0; k < 3; k++)
		U[k][0] = B[2 - k][2];
	for(k = 0; k < 3; k++)
		B[2 - k][2] = D[k][0];
	for(k = 0; k < 3; k++)
		D[k][0] = F[k][0];
	for(k = 0; k < 3; k++)
		F[k][0] = temp[k][0];
}

void Uplus(char U[3][3], char D[3][3], char F[3][3], char B[3][3], char L[3][3], char R[3][3])
{	// OK
	int i, j, k;
	char temp[3][3];
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
			temp[j][2 - i] = U[i][j];
	}
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
			U[i][j] = temp[i][j];
	}
	for(k = 0; k < 3; k++)
		temp[0][k] = B[0][k];
	for(k = 0; k < 3; k++)
		B[0][k] = L[0][k];
	for(k = 0; k < 3; k++)
		L[0][k] = F[0][k];
	for(k = 0; k < 3; k++)
		F[0][k] = R[0][k];
	for(k = 0; k < 3; k++)
		R[0][k] = temp[0][k]; // OK OK
}

void Dplus(char U[3][3], char D[3][3], char F[3][3], char B[3][3], char L[3][3], char R[3][3])
{	// OK
	int i, j, k;
	char temp[3][3];
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
			temp[j][2 - i] = D[i][j];
	}
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
			D[i][j] = temp[i][j];
	}
	for(k = 0; k < 3; k++)
		temp[2][k] = F[2][k];
	for(k = 0; k < 3; k++)
		F[2][k] = L[2][k];
	for(k = 0; k < 3; k++)
		L[2][k] = B[2][k];
	for(k = 0; k < 3; k++)
		B[2][k] = R[2][k];
	for(k = 0; k < 3; k++)
		R[2][k] = temp[2][k]; // OK OK
}

void Fplus(char U[3][3], char D[3][3], char F[3][3], char B[3][3], char L[3][3], char R[3][3])
{	// OK
	int i, j, k;
	char temp[3][3];
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
			temp[j][2 - i] = F[i][j];
	}
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
			F[i][j] = temp[i][j];
	}
	for(k = 0; k < 3; k++)
		temp[2][k] = U[2][k];
	for(k = 0; k < 3; k++)
		U[2][k] = L[2 - k][2];
	for(k = 0; k < 3; k++)
		L[2 - k][2] = D[0][2 - k];
	for(k = 0; k < 3; k++)
		D[0][2 - k] = R[k][0];
	for(k = 0; k < 3; k++)
		R[k][0] = temp[2][k]; // OK
}

void Bplus(char U[3][3], char D[3][3], char F[3][3], char B[3][3], char L[3][3], char R[3][3])
{	// OK
	int i, j, k;
	char temp[3][3];
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
			temp[j][2 - i] = B[i][j];
	}
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
			B[i][j] = temp[i][j];
	}
	for(k = 0; k < 3; k++)
		temp[0][k] = U[0][k];
	for(k = 0; k < 3; k++)
		U[0][k] = R[k][2];
	for(k = 0; k < 3; k++)
		R[k][2] = D[2][2 - k];
	for(k = 0; k < 3; k++)
		D[2][2 - k] = L[2 - k][0];
	for(k = 0; k < 3; k++)
		L[2 - k][0] = temp[0][k]; // OK
}

int main(void)
{
	char U[3][3] = {'w','w','w','w','w','w','w','w','w'};
	char D[3][3] = {'y','y','y','y','y','y','y','y','y'};
	char F[3][3] = {'r','r','r','r','r','r','r','r','r'};
	char B[3][3] = {'o','o','o','o','o','o','o','o','o'};
	char L[3][3] = {'g','g','g','g','g','g','g','g','g'};
	char R[3][3] = {'b','b','b','b','b','b','b','b','b'};
	int n, i, j, s, k, p, count;
	char move[3];
	scanf("%d", &n);
	for(s = 0; s < n; s++)
	{
		scanf("%d", &count);
		for(k = 0; k < count; k++)
		{
			scanf("%s", move);
			if(!strcmp(move, "U+"))
				Uplus(U, D, F, B, L, R);
			else if(!strcmp(move, "U-"))
			{
				for(p = 0; p < 3; p++)
					Uplus(U, D, F, B, L, R);
			}
			else if(!strcmp(move, "D+"))
				Dplus(U, D, F, B, L, R);
			else if(!strcmp(move, "D-"))
			{
				for(p = 0; p < 3; p++)
					Dplus(U, D, F, B, L, R);
			}
			else if(!strcmp(move, "L+"))
				Lplus(U, D, F, B, L, R);
			else if(!strcmp(move, "L-"))
			{
				for(p = 0; p < 3; p++)
					Lplus(U, D, F, B, L, R);
			}
			else if(!strcmp(move, "R+"))
				Rplus(U, D, F, B, L, R);
			else if(!strcmp(move, "R-"))
			{
				for(p = 0; p < 3; p++)
					Rplus(U, D, F, B, L, R);
			}
			else if(!strcmp(move, "F+"))
				Fplus(U, D, F, B, L, R);
			else if(!strcmp(move, "F-"))
			{
				for(p = 0; p < 3; p++)
					Fplus(U, D, F, B, L, R);
			}
			else if(!strcmp(move, "B+"))
				Bplus(U, D, F, B, L, R);
			else if(!strcmp(move, "B-"))
			{
				for(p = 0; p < 3; p++)
					Bplus(U, D, F, B, L, R);
			}
		}
    	for(i = 0; i < 3; i++)
		{
			for(j = 0; j < 3; j++)
				printf("%c", U[i][j]);
			if(!(i == 2 && s == n - 1))
				printf("\n");
		}
		for(i = 0; i < 3; i++)
		{
			for(j = 0; j < 3; j++)
			{
				U[i][j] = 'w'; 	D[i][j] = 'y';	F[i][j] = 'r';
				B[i][j] = 'o';  L[i][j] = 'g';  R[i][j] = 'b';
			}
		}
	}
}