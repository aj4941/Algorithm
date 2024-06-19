import sys
sys.setrecursionlimit(100)  # 재귀 깊이 제한 증가

def dfs(tmp):
    if tmp == s:
        return 1
    if len(s) > len(tmp):
        return 0
    ans = 0
    if tmp[-1] == 'A':
        ans = max(ans, dfs(tmp[:-1]))
    if tmp[0] == 'B':
        ans = max(ans, dfs(tmp[::-1][:-1]))
    return ans

s = input().strip()
t = input().strip()

print(dfs(t))