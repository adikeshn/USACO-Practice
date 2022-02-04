fout = open("notlast.in", "r")
fin = open("notlast.out", "w")

dict = {
    "Bessie": 0,
    "Elsie": 0,
    "Daisy": 0,
    "Gertie": 0,
    "Annabelle": 0,
    "Maggie": 0,
    "Henrietta": 0,
}
production = []
list = fout.readlines()
for x in list[1:]:
    split = x.split()
    production.append([split[0], int(split[1])])

for x in production:
    dict[x[0]] += x[1]

small = min(dict.values())
nextsmall = [max(dict, key=dict.get), max(dict.values())]

for x in dict:
    if dict[x] > small and dict[x] < nextsmall[1]:
        nextsmall[0] = x
        nextsmall[1] = dict[x]
t = 0
print(dict)
print(nextsmall)
for x in dict.values():
    if x == nextsmall[1]:
        t += 1
if len(set(dict.values())) == 1:
    fin.write("Tie\n")
    exit(0)
if t > 1:
    fin.write("Tie\n")
    exit(0)

fin.write(nextsmall[0])
exit(0)
