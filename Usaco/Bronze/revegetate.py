fin = open("revegetate.in", "r")
fout = open("revegetate.out", "w")

lines = list(map(lambda x: list(map(int, x.split())), fin.readlines()))
chosen = {}
for x in range(1, lines[0][0]+1):
    chosen[str(x)] = 0

for x in range(1, lines[0][0]+1):
    connected = []
    taken = {"1": 0, "2": 0, "3": 0, "4": 0}
    for y in lines[1:]:
        if y[0] == x:
            connected.append(y[1])
        elif y[1] == x:
            connected.append(y[0])
    for y in chosen:
        if int(y) in connected and chosen[y] != 0:
            taken[str(chosen[y])] = 1
    for y in taken:
        if taken[y] == 0:
            chosen[str(x)] = int(y)
            break
fout.write("".join(list(map(str, chosen.values()))))
