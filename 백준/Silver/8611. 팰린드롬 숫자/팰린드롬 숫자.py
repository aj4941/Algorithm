import sys

n = int(sys.stdin.readline())
empty = True

for i in range(2, 11):
    m = n
    res = ""
    while m > 0:
        res = str(m % i) + res
        m //= i

    flag = True

    for j in range(0, len(res)):
        if res[j] != res[len(res) - 1 - j]:
            flag = False

    if flag:
        print(str(i) + " " + res)
        empty = False
        
if empty:
    print("NIE")
