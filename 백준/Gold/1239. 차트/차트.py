from itertools import permutations

n = int(input())

a = list(map(int, input().split()))

ans = 0

for p in permutations(range(n)):
    cnt = [0] * 102
    val = 0
    cnt[val] = 1

    for i in p:
        val += a[i]
        cnt[val] = 1

    res = 0

    for i in range(50):
        if cnt[i] and cnt[i + 50]:
            res += 1

    ans = max(ans, res)

print(ans)