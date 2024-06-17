from collections import deque

n, k = map(int, input().split())
dq = deque(range(1, n + 1))

print("<", end="")

while dq:
    for _ in range(k - 1):
        dq.append(dq.popleft())
    
    print(dq.popleft(), end="")
    if dq:
        print(", ", end="")

print(">")