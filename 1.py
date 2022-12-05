num = 3
 
while num <= 1e6
    decStr = num.to_s
    binStr = num.to_s(2)
    if decStr == decStr.reverse and binStr == binStr.reverse 
        puts "num = #{num}"
        break
    end
    
    # Искать только нечетные числа, каждый раз добавлять 2
    num += 2
end