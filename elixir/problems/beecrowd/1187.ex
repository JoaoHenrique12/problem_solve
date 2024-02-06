op = IO.gets("") |> String.trim()

size = 12
square = for x <- 0..(size - 1), y <- 0..(size - 1) do 
  {value, _} = IO.gets("") |> String.trim() |> Float.parse()
  {x, y, value}
end

up_part = Enum.filter(square,
  fn {y, x, _value} -> ( (x > y and x < (size - 1 - y) ) and (y < (size-1) / 2 ) ) end
)

sum = Enum.reduce(up_part, 0, fn {_, _,v1}, acc -> v1 + acc end)

sum = if op == "S", do: sum, else: sum/30
sum = :erlang.float_to_binary(sum, [decimals: 1])
IO.puts(sum)
