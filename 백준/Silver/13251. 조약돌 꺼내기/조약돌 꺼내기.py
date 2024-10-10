from math import factorial

# nCr을 계산하는 함수
def nCr(n, r):
    if r > n:
        return 0
    return factorial(n) // (factorial(r) * factorial(n - r))

# 입력을 받는 부분
m = int(input())
a = list(map(int, input().split()))
k = int(input())

n = sum(a)  # a 배열의 합계
r1 = 0
r2 = nCr(n, k)

for i in range(m):
    if k <= a[i]:
        r1 += nCr(a[i], k)

# 결과 출력
print(f"{r1 / r2:.9f}")
