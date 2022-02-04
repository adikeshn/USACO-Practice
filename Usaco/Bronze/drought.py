import sys

lines = sys.stdin.readlines()
T = int(lines[0].split()[0])
index = 1
for x in range(T):
    stuff = lines[index:index+2]
    N = int(stuff[0])
    cows = list(map(int, stuff[1].split()))
    won = False
    for l in reversed(range(0, min(cows) + 1)):
        change = []
        sum = 0
        chosen = [l] * len(cows)
        for x in range(len(cows)):
            change.append(cows[x] - chosen[x])
        for y in range(len(change) - 1):
            sub = min(change[y], change[y+1])
            change[y] -= sub
            change[y+1] -= sub
            sum += 2*sub
        if change == [0] * len(cows):
            print(sum)
            won = True
            break
    if not won:
        print("-1")
    index += 2
