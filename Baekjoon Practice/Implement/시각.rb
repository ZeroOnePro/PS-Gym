n = gets
n = n.to_i
cnt = 0
for hour in 0..n
    for minute in 0...60
        for second in 0...60
           if (hour.to_s + minute.to_s + second.to_s).include? "3"
                cnt += 1
           end
        end
    end
end
puts cnt