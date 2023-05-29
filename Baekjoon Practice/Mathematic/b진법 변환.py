n,b = map(int,input('십진법 n을 b진법으로 바꾸어주는 프로그램입니다. n과 b를 입력하세요 >> ').split())
q = n
k = 0
stack = []
while(q != 0):
    r = q % b
    stack.append(r)
    q //= b
ans = ''
while stack:
    ans += str(stack.pop())
print(ans)