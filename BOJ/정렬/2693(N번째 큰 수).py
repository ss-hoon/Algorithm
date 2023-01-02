from sys import stdin

for _ in range(int(input())):
    array = list(map(int, stdin.readline().split()))
    print(sorted(array)[-3])