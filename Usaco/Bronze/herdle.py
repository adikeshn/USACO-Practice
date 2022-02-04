import sys

correct = [[], [], []]
guess = [[], [], []]
index = 0
for x in sys.stdin:
    if index >= 3:
        guess[index - 3] = [x[0], x[1], x[2]]
    else:
        correct[index] = [x[0], x[1], x[2]]
    index += 1
letters = dict()
numYellow = 0
numGreen = 0
for x in correct:
    for y in x:
        if y not in letters:
            letters[y] = 1
        else:
            letters[y] += 1
for x in range(len(guess)):
    for y in range(len(guess[x])):
        if correct[x][y] == guess[x][y]:
            numGreen += 1
            letters[guess[x][y]] -= 1
        elif guess[x][y] in letters:
            if letters[guess[x][y]] != 0:
                numYellow += 1
                letters[guess[x][y]] -= 1
print(numGreen)
print(numYellow)
