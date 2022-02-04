fin = open('tttt.in', 'r')
fout = open('tttt.out', 'w')

board = []
lines = fin.readlines()
board.append(list(lines[0][:3]))
board.append(list(lines[1][:3])) 
board.append(list(lines[2][:3]))
ar = []
solo = 0
team = 0
for x in board:
    cows = set()
    for y in x:
        cows.add(y)
    if len(cows) == 1:
        if cows not in ar:
            solo += 1
            ar.append(cows)
    elif len(cows) == 2:
        if cows not in ar:
            team += 1
            ar.append(cows)

for x in range(3):
    cows = set()
    for y in board:
        cows.add(y[x])
    if len(cows) == 1:
        if cows not in ar:
            solo += 1
            ar.append(cows)
    elif len(cows) == 2:
        if cows not in ar:
            team += 1
            ar.append(cows)
cows = set()
cows2 = set()
counter = 2
for x in range(3):
    cows.add(board[x][x])
    cows2.add(board[x][counter])
    counter -= 1

if len(cows) == 1:
    if cows not in ar:
        solo += 1
        ar.append(cows)
elif len(cows) == 2:
    if cows not in ar:
        team += 1
        ar.append(cows)

if len(cows2) == 1:
    if cows2 not in ar:
        solo += 1
        ar.append(cows2)
elif len(cows2) == 2:
    if cows2 not in ar:
        team += 1
        ar.append(cows2)

fout.write(str(solo) + '\n')
fout.write(str(team))

