cache = [[False] * 5 for _ in range(5)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
def dfs(x, y, cnt, move, a):
    if move == 3: 
        if cnt >= 2:
            return True
        return False

    has_ans = False
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if 0 <= nx < 5 and 0 <= ny < 5 and not cache[nx][ny] and a[nx][ny] != -1:
            cache[x][y] = True
            if a[nx][ny] == 1:
                has_ans |= dfs(nx, ny, cnt + 1, move + 1, a)
            else:
                has_ans |= dfs(nx, ny, cnt, move + 1, a)
            cache[x][y] = False

    return has_ans

# 입력 받기
a = [list(map(int, input().split())) for _ in range(5)]
x, y = map(int, input().split())

# DFS 실행
has_ans = dfs(x, y, 0, 0, a)

# 결과 출력
print(1 if has_ans else 0)