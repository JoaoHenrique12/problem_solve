empty = %{}
sqrs = %{1 => 1, 2 => 4, 3 => 9}

sqrs[1]
Map.get(sqrs,{key})

cat = %{name: "tim", age: 12}

# Replace elements
cat = %{cat | name: "pope"}
