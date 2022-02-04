import sys

lines = sys.stdin.readlines()
order = list(map(int, lines[1].split()))
stalls = list(map(int, lines[2].split()))

factors = 1
subtract = 0
for x in sorted(order, reverse=True):
    count = 0
    for y in range(len(stalls)):
        if stalls[y] >= x and stalls[y] != None:
            count += 1
    factors *= count - subtract
    subtract += 1
print(factors)
