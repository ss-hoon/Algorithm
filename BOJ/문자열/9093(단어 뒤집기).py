from sys import stdin

count = int(stdin.readline())
for _ in range(count):
    sentence = stdin.readline().split()
    sentence = [word[::-1] for word in sentence]
    print(' '.join(sentence))