values = []
n = input()
for x in range(5):
    n = input()
    values.append(list((map(lambda x: int(x.strip()) - 1, n.split(',')))))
ansas = []
for x in values:
    ans = 0
    vis = [False] * len(x)
    for y in range(len(x)):
        if (vis[y] == False):
            currindex = y
            newindex = x[currindex]
            count = []
            c = True
            count.append(currindex)
            while(newindex != currindex):
                if newindex in count or vis[newindex]:
                    c = False
                    break
                count.append(newindex)
                newindex = x[newindex]
            if c:
                for v in count:
                    vis[v] = True
                ans += len(count)

    ansas.append(ans)
print(f'{ansas[0]}, {ansas[1]}, {ansas[2]}, {ansas[3]}, {ansas[4]}')
