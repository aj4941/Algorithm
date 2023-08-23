n = int(input())
a = list(map(int, input().split()))
cnt = [0 for _ in range(100)]
ans = -1

for i in range(n):
    for j in range(0, 64):
        if a[i] & (1 << j):
            cnt[j] += 1
            ans = max(ans, (1 << j))
            break

num = 0

while num <= 62:
    cnt[num + 1] += cnt[num] // 2
    cnt[num] %= 2
    if cnt[num + 1] > 0:
        ans = (1 << (num + 1))
    num += 1

print(ans)
