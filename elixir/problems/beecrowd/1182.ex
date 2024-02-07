col = IO.gets("") |> String.trim() |> String.to_integer()
op = IO.gets("") |> String.trim()

size = 12
square = for x <- 0..(size - 1), y <- 0..(size - 1) do 
  {value, _} = IO.gets("") |> String.trim() |> Float.parse()
  {x, y, value}
end

col_part = Enum.filter(square,
  fn {_y, x, _value} -> (x == col) end
)

size_col_part = size

sum = Enum.reduce(col_part, 0, fn {_, _,v1}, acc -> v1 + acc end)

sum = if op == "S", do: sum, else: sum/size_col_part
sum = :erlang.float_to_binary(sum, [decimals: 1])
IO.puts(sum)
