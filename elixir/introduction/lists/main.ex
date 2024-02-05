numbers = [1, 2, 3, 4]

length(numbers)

Enum.at(numbers, -3) # index > length(numbers) then return nil, negative numbers return length - index
3 in numbers # true

numbers = List.replace_at(numbers,{index}, {new_value})# If index is out of bound return the original list.
numbers = List.insert_at(numbers,{index}, {new_value}) # Index is capped at the list end.

concatenated_list = numbers ++ numbers

[head | tails] = [1, 2, 3, 4]

# Constant time operators
hd(numers) # Head
tl(numers) # Tails

alist = [1,true, :atom]
alist = [:head | alist]
