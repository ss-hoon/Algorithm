maze_len = int(input())
maze = list(map(int, input().split()))
cache = [-1] * maze_len
cache[0] = 0

for idx in range(maze_len):
    if cache[idx] == -1:
        break

    for step in range(1, maze[idx]+1):
        if idx+step < maze_len and cache[idx+step] == -1:
            cache[idx+step] = cache[idx] + 1

print(cache[-1])