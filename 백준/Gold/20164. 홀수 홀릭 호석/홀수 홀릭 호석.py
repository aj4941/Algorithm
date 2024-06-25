def calc(tmp):
    cnt = 0
    for to in tmp:
        if (int(to) % 2) == 1:
            cnt += 1
    return cnt

def max_solve(s):
    tmp = calc(s)
    if len(s) == 1:
        return int(s[0]) % 2
    elif len(s) == 2:
        val = int(s[0]) + int(s[1])
        return max_solve(str(val)) + tmp
    else:
        res = 0
        for i in range(len(s)):
            for j in range(i + 2, len(s)):
                a = s[:i + 1]
                b = s[i + 1:j]
                c = s[j:]
                val = int(a) + int(b) + int(c)
                res = max(res, max_solve(str(val)))
        return res + tmp

def min_solve(s):
    tmp = calc(s)
    if len(s) == 1:
        return int(s[0]) % 2
    elif len(s) == 2:
        val = int(s[0]) + int(s[1])
        return min_solve(str(val)) + tmp
    else:
        res = float('inf')
        for i in range(len(s)):
            for j in range(i + 2, len(s)):
                a = s[:i + 1]
                b = s[i + 1:j]
                c = s[j:]
                val = int(a) + int(b) + int(c)
                res = min(res, min_solve(str(val)))
        return res + tmp

s = input()
mx = max_solve(s)
mn = min_solve(s)
print(mn, mx)