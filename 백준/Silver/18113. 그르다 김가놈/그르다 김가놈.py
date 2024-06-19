# 첫 줄에서 n, k, m을 입력받습니다.
n, k, m = map(int, input().split())

# 다음 n 줄에서 각 줄의 숫자를 입력받아 리스트 a를 생성합니다.
a = [int(input()) for _ in range(n)]

# 입력받은 값에 대해 조건에 따라 a 배열을 조정합니다.
for i in range(n):
    if a[i] >= 2 * k:
        a[i] -= 2 * k
    elif a[i] >= k:
        a[i] -= k
    else:
        a[i] = 0

# 이진 탐색을 수행하여 문제의 조건을 만족하는 최대 l 값을 찾습니다.
l, r = 0, 10**18

while l + 1 < r:
    mid = (l + r) // 2
    cnt = sum(x // mid for x in a)

    if cnt >= m:
        l = mid
    else:
        r = mid

# 만약 l이 0이라면 -1을 출력합니다.
if l == 0:
    l = -1

# 결과를 출력합니다.
print(l)
