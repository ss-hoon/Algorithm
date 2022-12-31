switch_cnt = int(input())
switch = list(map(int, input().split()))

test = int(input())
for _ in range(test):
    gender, num = map(int, input().split())

    if gender == 1:
        for target in range(num, switch_cnt+1, num):
            switch[target-1] ^= 1
    else:
        switch[num-1] ^= 1
        for idx in range(1, switch_cnt):
            if (num-idx-1 < 0) or (num+idx-1 >= switch_cnt):
                break

            if switch[num-idx-1] != switch[num+idx-1]:
                break

            switch[num-idx-1] ^= 1
            switch[num+idx-1] ^= 1

for idx in range(0, switch_cnt, 20):
    print(*switch[idx:idx+20])