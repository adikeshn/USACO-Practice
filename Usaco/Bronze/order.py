fin = open("milkorder.in", "r")
fout = open("milkorder.out", "w")

lines = list(map(lambda x: list(map(int, x.split())), fin.readlines()))
N = (lines[0][0])
M = lines[0][1]
if M > 0:
    social = lines[1]
position = []
check = []
answer = [0] * (N)
for x in lines[1:]:
    if len(x) == 2:
        position.append(x)
        check.append(x[0])
        answer[x[1] - 1] = x[0]
if M > 0:
    if 1 not in social:
        for x in reversed(range(0, len(social))):
            if social[x] not in check:
                if x+1 == len(social):
                    index = len(answer)
                else:
                    connected = social[x+1]
                    index = answer.index(connected)
                for y in reversed(range(0, index)):
                    if answer[y] == 0:
                        answer[y] = social[x]
                        break
    else:
        for x in social:
            if x not in check:
                answer[answer.index(0)] = x
for x in range(len(answer)):
    if answer[x] == 0:
        answer[x] = 1
        break
print(answer)
fout.write(str(answer.index(1) + 1))
