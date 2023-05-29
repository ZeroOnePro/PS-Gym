import sys
n = int(input())
seq = list(map(int,input().split()))
if(n == 1): # 예외 처리
    if(seq[0] != 1):
        print(1)
    else:
        print(2)
    sys.exit()
result = set([])
def go(index, sum):
    global min
    if(n == index):
        result.add(sum)
        return
    go(index+1, sum + seq[index])
    go(index+1, sum)
go(0,0)
result = sorted(result)
i = 0
end = result[len(result) -1]
start = result[i]
cursor = result[i+1]
while(i < len(result)-2):
    if(start +1 != cursor):
        break
    else:
        i += 1
        cursor = result[i+1]
        start = result[i]
if(cursor == end):
    print(end + 1)
else:
    print(start+1)