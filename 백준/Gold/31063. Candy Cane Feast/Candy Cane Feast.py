cow_num, candy_num = map(int, input().split())
cows = list(map(int, input().split()))
candies = list(map(int, input().split()))
grow = [0]*cow_num
candy_locations = [1]*candy_num

for k in range(candy_num):
    for r in range(cow_num):
        if cows[r] >= candies[k]: # 사탕 높이 보다 크다면
            cows[r] += candies[k] - (candy_locations[k]-1)
            break
        elif cows[r] >= candy_locations[k]: # 사탕 하단 높이 보다 크다면
            grow_before = cows[r]
            cows[r] += cows[r] - (candy_locations[k]-1)
            candy_locations[k] = grow_before+1

for k in cows:
    print(k)