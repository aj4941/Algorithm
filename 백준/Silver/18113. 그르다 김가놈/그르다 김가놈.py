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

l, r = 0, 10**9 + 1

while l + 1 < r: # [l, r) : TTTTFFFF
    mid = (l + r) // 2
    cnt = 0

    for x in a: # 조각 개수 세기
        cnt += x // mid

    if cnt >= m: # True
        l = mid
    else: # False
        r = mid

if l == 0:
    l = -1

print(l)