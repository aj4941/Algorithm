n = int(input())
a = list(map(int, input().split()))
dic = {}
ans = -1

for i in range(n):
    dic[a[i]] = dic.get(a[i], 0) + 1
    ans = max(ans, a[i])

num = 1

while num <= 2 ** 62:
    if num in dic:
        dic[num * 2] = dic.get(num * 2, 0) + dic[num] // 2
        dic[num] = dic[num] % 2
        if dic[num * 2] > 0:
            ans = num * 2

    num *= 2

print(ans)
