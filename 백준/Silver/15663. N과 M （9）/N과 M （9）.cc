#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

void DFS(vector<int> st, vector<int> isSel, int Input[], int cnt)
{
	int i, j;
	if(cnt == m)
	{
		for(i = 0; i < m; i++)
			printf("%d ", st[i]);
		printf("\n");
		return;
	}
	bool used[20000] = { false, };
	for(i = 0; i < n; i++)
	{ 
		if(used[Input[i]] == false && isSel[i] == 0)
		{
			used[Input[i]] = true;
			isSel[i] = 1;
			st.push_back(Input[i]);
			DFS(st, isSel, Input, cnt + 1);
			st.pop_back();
			isSel[i] = 0;
		}
	}
}
int main(void)
{
	int i, num;
	vector<int> st;
	int Input[20000];
	cin >> n >> m;
	vector<int> isSel(n);
	for(i = 0; i < n; i++)
		scanf("%d", &Input[i]);
	sort(Input, Input + n);
	DFS(st, isSel, Input, 0);
}