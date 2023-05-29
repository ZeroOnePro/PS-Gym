def solution(s):
    answer = ''
    words = list(map(lambda word:word.capitalize(),s.split(' ')))
    cnt = len(words)-1
    for word in words:
        answer += word
        if(cnt):
            answer += ' '
        cnt -= 1
    return answer

if __name__ == "__main__":
  print(solution("3people unfollowed me"))