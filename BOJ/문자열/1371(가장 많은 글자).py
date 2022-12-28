from sys import stdin

# 초기화
sentence = stdin.read()
alpha_cnt = [0]*26

# 알파벳 카운팅
for alpha in sentence:
    if alpha.isalpha():
        alpha_cnt[ord(alpha)-97] += 1

# 가장 많이 나온 알파벳 출력
max_cnt = max(alpha_cnt)
for i in range(26):
    if alpha_cnt[i] == max_cnt:
        print(chr(i+97), end='')