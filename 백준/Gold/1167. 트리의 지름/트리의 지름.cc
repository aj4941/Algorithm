#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector <pair<int,int>> v[100001]; // 간선과 가중치 
bool visit[100001]; // 방문 노드
int longest; // 가장 긴 정점
int len; // 트리의 지름

void dfs(int s,int d) {
	visit[s] = 1; 
	for (int i = 0; i < v[s].size(); i++) {
		int y = v[s][i].first;
		if (!visit[y]) {
			dfs(y,v[s][i].second + d);
		}
	}
	if (len < d) { // 방문한 정점이 누적 길이가 지금까지의 길이보다 크다면
		len = d; // 길이를 바꿔주고
		longest = s; // 현재 정점을 가장 긴 정점으로 만든다.
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		while (1) {
			int b, c;
			cin >> b;
			if (b == -1) break;
			cin >> c;
			v[a].push_back({ b,c });
		}
	}
	dfs(1, 0); // 1을 기준으로 잡아서 가장 긴 정점을 찾고
	memset(visit, 0, sizeof(visit));
	dfs(longest, 0); // 그 정점으로 다시 가장 긴 지름을 찾는다.
	cout << len << "\n";
}