n, m = map(int, input().split())
cache = [False] * (n + 1)  # 인덱스 1부터 사용하기 위해 n+1로 설정

def func(cnt, res):
    if cnt == m:
        print(' '.join(map(str, res)))
        return

    for i in range(1, n + 1):
        if not cache[i]:
            cache[i] = True
            res.append(i)
            func(cnt + 1, res)
            res.pop()  # 선택 해제하고 다음 숫자 탐색
            cache[i] = False

func(0, [])  # 초기 카운트 0, 선택된 숫자 리스트는 비어있는 상태에서 시작