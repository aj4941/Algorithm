#include <vector>
#include <cstring>
 
using namespace std;
 
int MOD = 20170805;
int d[501][501][2];
int dx[] = {1, 0};
int dy[] = {0, 1};
int N;
int M;
 
int cal (int x, int y, int z, vector<vector<int>> &MAP) {
    if (x == N-1 && y == M-1) return 1;
    if (d[x][y][z] != -1) return d[x][y][z];
    d[x][y][z] = 0;
    for (int k = 0; k < 2; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if (MAP[x][y] == 0 || (MAP[x][y] == 2 && k == z)) {
                d[x][y][z] += cal(nx, ny, k, MAP) % MOD;
            }
        }
    }
    return d[x][y][z] % MOD;
}
 
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    memset(d, -1, sizeof(d));
    
    N = m;
    M = n;
    int answer = cal(0, 0, 0, city_map);
    return answer;
}