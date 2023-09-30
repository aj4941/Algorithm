import sys; input = sys.stdin.readline

answer = 0
for _ in range(int(input())):
    x = int(input()[2:]) # 두번째부터 정수로 입력받는다.
    if x <= 90: # 90 이하이면 개수에 1을 더한다.
        answer += 1
print(answer)