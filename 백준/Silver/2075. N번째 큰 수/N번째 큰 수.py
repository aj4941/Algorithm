import heapq

n = int(input())  # n 입력 받기
min_heap = []  # 최소 힙 생성

for _ in range(n):
    line = map(int, input().split())  # n개의 숫자를 한 줄씩 입력 받기
    for num in line:
        heapq.heappush(min_heap, num)  # 힙에 원소 추가
        if len(min_heap) > n:  # 힙의 크기가 n을 초과하면
            heapq.heappop(min_heap)  # 최소 원소(힙의 루트) 제거

print(min_heap[0])  # n번째로 큰 원소 출력