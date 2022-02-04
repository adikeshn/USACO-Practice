import sys

stuff = sys.stdin.readlines()
T = int(stuff[0].split()[0])
index = 1
for o in range(T):
    current = list(map(int, stuff[index].split()))
    A = current[0:4]
    B = current[4:8]
    ABB = False
    BBA = False
    winA = 0
    winB = 0
    nextCheck = []
    win = False
    for x in A:
        for y in B:
            if x > y:
                winA += 1
            elif y > x:
                winB += 1
    if winA > winB:
        ABB = True
    elif winA < winB:
        BBA = True
    for x in range(1, 11):
        for y in range(1, 11):
            for z in range(1, 11):
                for u in range(1, 11):
                    nextCheck = [x, y, z, u]
                    scoreA = 0
                    scoreB = 0
                    scoreC = [0, 0]
                    for b in nextCheck:
                        for h in A:
                            if h > b:
                                scoreA += 1
                            elif h < b:
                                scoreC[0] += 1
                        for t in B:
                            if t > b:
                                scoreB += 1
                            elif t < b:
                                scoreC[1] += 1
                    if ABB and scoreC[0] > scoreA and scoreC[1] < scoreB and not win:
                        win = True
                    elif BBA and scoreC[1] > scoreB and scoreC[0] < scoreA and not win:
                        win = True
    if winA != winB and win:
        print("yes")
    else:
        print("no")
