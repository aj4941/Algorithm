import sys
input = sys.stdin.read

Memo = [-1] * 100

def fibo(n):
    if Memo[n] != -1:
        return Memo[n]
    if n == 0:
        Memo[n] = 0
    elif n == 1 or n == 2:
        Memo[n] = 1
    else:
        Memo[n] = fibo(n - 1) + fibo(n - 2)
    return Memo[n]

n = int(input().strip())
print(fibo(n))