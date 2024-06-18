n = int(input())  # 숫자 n 입력 받기
a = []

for _ in range(n):
    x, y = map(int, input().split())  # 튜플의 각 원소 입력 받기
    a.append((x, y))  # 리스트에 튜플 추가

# 리스트 a를 정렬
a.sort()

ans = 0
stk = []

for to in a:
    # 스택에 요소가 있고 스택의 top 요소가 to[1] 보다 크면 pop
    while len(stk) > 0 and stk[-1] > to[1]:
        stk.pop()
    
    # to[1]이 0이면 계속
    if to[1] == 0:
        continue
    
    # 스택이 비어 있거나 스택의 top 요소가 to[1]과 다르면
    if len(stk) == 0 or stk[-1] != to[1]:
        ans += 1
        stk.append(to[1])  # to[1]을 스택에 push

print(ans)
