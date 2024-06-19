# 입력 받기
n, m, k = map(int, input().split())

# (x, y) 쌍을 입력받아 리스트에 저장
pairs = []
for _ in range(k):
    x, y = map(int, input().split())
    pairs.append((x, y))

# (x, y) 쌍을 x 기준 내림차순으로 정렬
pairs.sort(reverse=True, key=lambda pair: pair[0])

# 상위 n개의 x 값의 합이 m을 넘는지 확인
if sum(x for x, y in pairs[:n]) < m:
    print(-1)
else:
    # 이진 탐색으로 조건을 만족하는 최소 y 찾기
    l, r = 0, 10**15
    while l + 1 < r:
        mid = (l + r) // 2
        res, cnt = 0, 0

        for x, y in pairs:
            if y <= mid:
                res += x
                cnt += 1
                if cnt == n:
                    break

        if cnt == n and res >= m:
            r = mid
        else:
            l = mid

    # 가능한 최소 y 값 출력
    print(r)
