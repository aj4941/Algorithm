#include <bits/stdc++.h>
using namespace std;
char ch[8] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
vector<int> p = { 0, 1, 2, 3, 4, 5, 6, 7 };
map<char, int> pos;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

bool calc(char a, char b, char op, int num)
{
    int d = abs(pos[a] - pos[b]) - 1;
    if (op == '=') return d == num;
    if (op == '>') return d > num;
    if (op == '<') return d < num;
}

int solution(int n, vector<string> data) 
{
    int ans = 0;
    do {
        for (int i = 0; i < 8; i++)
            pos[ch[p[i]]] = i;
        
        bool hasAns = true;
        
        for (auto s : data)
        {
            char a = s[0], b = s[2], op = s[3];
            int num = s[4] - '0';
            if (!calc(a, b, op, num)) 
            {
                hasAns = false;
                break;
            }
        }
        
        if (hasAns)
            ans++;
        
    } while (next_permutation(p.begin(), p.end()));
    
    return ans;
}