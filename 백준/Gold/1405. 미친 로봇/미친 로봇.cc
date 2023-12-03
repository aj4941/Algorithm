#include <iostream>

#include <iomanip>

using namespace std;

 

const int MAX = (14 + 1) * 2;

 

typedef struct

{

        int y, x;

}Dir;

 

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

 

int N;

double probability[4];

double result;

bool visited[MAX][MAX];

 

void DFS(int y, int x, double chance)

{

        //다 이동했으면 누적 확률들을 더해준다

        if (N == 0)

        {

                 result += chance;

                 return;

        }

 

        visited[y][x] = true; //밟은 땅으로 표시

        for (int i = 0; i < 4; i++)

        {

                 int nextY = y + moveDir[i].y;

                 int nextX = x + moveDir[i].x;

 

                 if (!visited[nextY][nextX])

                 {

                         N -= 1;

                         DFS(nextY, nextX, chance * probability[i]);

                         N += 1;

                         visited[nextY][nextX] = false; //다음에 밟을 땅을 다시 밟지 않음으로 표시

                 }

        }

}

 

int main(void)

{

        ios_base::sync_with_stdio(0);

        cin.tie(0); //실행속도

        cin >> N;

 

        for (int i = 0; i < 4; i++)

        {

                 cin >> probability[i];

 

                 probability[i] *= 0.01;

        }

 

        DFS(15, 15, 1.0);

 

        cout << fixed;

        cout << setprecision(10) << result << "\n";

        return 0;

}