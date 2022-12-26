from sys import stdin

count = int(input())
result = []

for _ in range(count):
    word = stdin.readline()
    i = 0
    temp = ''

    while i < len(word):
        if word[i].isdigit():
            temp += word[i]
        else:
            if temp:
                result.append(int(temp))
                temp = ''

        i += 1

result.sort()
print(*result, sep='\n')