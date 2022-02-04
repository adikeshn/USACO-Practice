fin = open("swap.in", "r")
four = open("swap.out", "w")

lines = fin.readlines()
N = int(lines[0].split()[0])
B = int(lines[0].split()[1])
swaps = []
arrange = list(range(1, N+1))
for x in lines[1:]:
    stuff = x.split()
    c = int(stuff[0])
    n = int(stuff[1])
    swaps.append([c, n])
for x in range(B):
    for y in swaps:
        cut = arrange[y[0]-1:(y[1])]
        cut = reversed(cut)
        arrange[y[0]-1: y[1]] = cut

for x in arrange:
    four.write(str(x) + "\n")
