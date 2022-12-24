name = input()

# 초기화
alpha = [0 for _ in range(26)]
prefix = ''
odd_cnt = 0
odd_alpha = ''

# 알파벳 개수 계산
for token in name:
    alpha[ord(token)-65] += 1

# 홀수, 짝수 계산 -> 접두사 생성
for i in range(26):
    if alpha[i] % 2 == 1:
        odd_cnt += 1
        odd_alpha = chr(i+65)

    prefix += chr(i+65) * (alpha[i] // 2)

# 팰린드롬 생성 (접두사 + 홀수 알파벳 + 접두사 역순)
# 생성하지 못하는 경우 -> I'm Sorry Hansoo
print("I'm Sorry Hansoo" if odd_cnt > 1 else prefix + odd_alpha + prefix[::-1])