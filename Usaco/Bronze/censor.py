fin = open("censor.in", "r")
fout = open("censor.out", "w")

lines = fin.readlines()
text = list(lines[0])
censores = list(lines[1])
done = False

while not done:
    checks = 0
    for x in range(len(text)):
        check = text[x:x+len(censores)]
        if check == censores:
            del text[x:x+len(censores)]
            checks = 1
            break
    if checks == 0:
        done = True
print("".join(text[:-1]))
fout.write("".join(text[:-1]))
