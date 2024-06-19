from collections import deque

# 첫 번째 줄에서 n, m, v 입력 받기
n, m, v = map(int, input().split())

# 그래프 초기화
graph = [[] for _ in range(n + 1)]

# 이후 m개의 간선 정보 입력 받기
for _ in range(m):
    U, V = map(int, input().split())
    graph[U].append(V)
    graph[V].append(U)

# 그래프의 각 리스트 정렬
for connections in graph:
    connections.sort()

def dfs(v, visited):
    print(v, end=' ')
    visited[v] = True
    for neighbor in graph[v]:
        if not visited[neighbor]:
            dfs(neighbor, visited)

def bfs(v, visited):
    queue = deque([v])
    visited[v] = True
    while queue:
        current = queue.popleft()
        print(current, end=' ')
        for neighbor in graph[current]:
            if not visited[neighbor]:
                queue.append(neighbor)
                visited[neighbor] = True

# 방문 확인용 배열 초기화
visited_dfs = [False] * (n + 1)
visited_bfs = [False] * (n + 1)

# DFS와 BFS 실행
dfs(v, visited_dfs)
print()
bfs(v, visited_bfs)