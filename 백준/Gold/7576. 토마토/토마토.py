from collections import deque

dx = [-1, 1, 0, 0] # 토마토가 상하좌우로 퍼지는 것을 표현
dy = [0, 0, -1, 1]

m, n = map(int, input().split())
a = []
for i in range(n):
    a.append(list(map(int, input().split())))

q1 = deque()
q2 = deque() # bfs가 수행되는 횟수 (days)를 체크하기 위해 큐를 2개 구성함

for i in range(n):
    for j in range(m):
        if a[i][j] == 1:
            q1.append((i, j))

days = 0

while True:
    while q1: # queue 1 에서는 현재 존재하는 토마토들에서 상하좌우로 토마토를 전파시킴
        x, y = q1.popleft()
        for i in range(4): # 상하좌우 탐색
            nx, ny = x + dx[i], y + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= m: # 범위를 벗어나면 넘기기
                continue
            if a[nx][ny] == 1 or a[nx][ny] == -1: # 과거에 토마토가 되었거나 토마토가 없는 칸이라면 넘기기
                continue
            a[nx][ny] = 1 # 탐색한 칸을 토마토로 만들고
            q2.append((nx, ny)) # queue 2에 넣어서 다음 bfs에 전파되도록 구성

    if not q2: # queue 2가 비어있다는 것은 queue 1에서 전파된 토마토가 없다는 뜻이므로 탐색 종료
        break

    q1, q2 = q2, q1 # queue 2에 있는 새로운 토마토를 queue 1에 넣고 queue 1은 비어있는 큐로 바꾸기
    days += 1 # bfs가 1번 수행될 때마다 하루가 지나므로 1일 추가

hasAns = all(a[i][j] != 0 for i in range(n) for j in range(m)) # 익지 않은 토마토가 있다면 정답이 될 수 없으므로 체크

if not hasAns: # hasAns = false 라면 익지 않은 토마토가 있다는 것이므로 days = -1 설정
    days = -1

print(days)