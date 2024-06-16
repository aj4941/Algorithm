n = int(input())

a = list(map(int, input().split()))

cnt = mx = 0

for x in a:
    cur = 0
    while x > 0:
        if x % 2 == 1:
            cnt += 1
            x -= 1
        else:
            x //= 2
            cur += 1

    mx = max(mx, cur)

print(cnt + mx)