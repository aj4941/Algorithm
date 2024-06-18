from queue import Queue

# 다리 길이, 다리 최대 하중, 트럭 무게 리스트를 입력받음
n, w, L = map(int, input().split())
truck_weights = list(map(int, input().split()))

trucks = Queue()  # 트럭 무게를 Queue에 추가
for weight in truck_weights:
    trucks.put(weight)

bridge = Queue()  # 다리를 나타내는 Queue, 초기에는 0으로 채워진다
for _ in range(w):
    bridge.put(0)

time = 0
current_weight = 0

while True:
    # 다리에서 트럭이 나가면 해당 무게를 빼준다
    current_weight -= bridge.get()

    if not trucks.empty():
        if current_weight + trucks.queue[0] <= L:  # 새 트럭이 다리에 올라갈 수 있으면
            truck_weight = trucks.get()
            bridge.put(truck_weight)
            current_weight += truck_weight
        else:
            bridge.put(0)  # 다리에 트럭이 올라가지 못하면 0을 추가
    else:
        bridge.put(0)  # 남은 트럭이 없다면 0을 계속 추가

    time += 1

    if trucks.empty() and current_weight == 0:  # 모든 트럭이 다리를 지났으면
        break

print(time)