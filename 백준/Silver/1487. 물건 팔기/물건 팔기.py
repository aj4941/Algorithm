n = int(input())

a = [] # first, second 값을 저장할 리스트

for i in range(n):
    first, second = map(int, input().split())
    a.append((first, second))

mx = ans = 0

for val in range(1000000, -1, -1):
    res = 0
    for first, second in a:
        if first < val:
            continue
        if val - second < 0:
            continue
        res += val - second

    if mx <= res:
        mx = res
        ans = val

print(ans)