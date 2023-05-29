y, x = gets.split
x = x.to_i
# x는 행 y가 열
locate = [[-2,-1], [-1,-2], [1,-2], [2,-1], [2,1], [1,2], [-1,2],[-2,1]]
cnt = 8
locate.map{
    |nx,ny| nx +=x ny+=y.ord - 'a'.ord  # 문자니까 'a' 아스키코드를 빼서 숫자로 만듦
    if nx < 1 or ny < 1
        cnt -= 1
    end
    if nx > 8 or ny > 8
        cnt -= 1
    end
}
puts cnt
