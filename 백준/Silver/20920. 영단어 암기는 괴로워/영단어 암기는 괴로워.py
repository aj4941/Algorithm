n, m = map(int, input().split())
mp = {}

# 문자열을 입력 받고 m보다 길이가 짧으면 무시, 아니면 카운트
for _ in range(n):
    s = input().strip()
    if len(s) < m:
        continue
    if s in mp:
        mp[s] += 1
    else:
        mp[s] = 1

# 문자열 정보를 리스트에 저장 (빈도, 길이, 문자열)
v = [(freq, len(word), word) for word, freq in mp.items()]

# 빈도수 내림차순, 길이 내림차순, 사전 순 정렬
v.sort(key=lambda x: (-x[0], -x[1], x[2]))

# 정렬된 결과 출력
for _, _, word in v:
    print(word)