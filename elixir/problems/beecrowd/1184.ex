op = IO.gets("") |> String.trim()

size = 12
square = for x <- 0..(size - 1), y <- 0..(size - 1) do 
  {value, _} = IO.gets("") |> String.trim() |> Float.parse()
  {x, y, value}
end

down_diag_part = Enum.filter(square,
  fn {y, x, _value} -> ( x < y ) end
)

size_down_diag_part = length(down_diag_part)

sum = Enum.reduce(down_diag_part, 0, fn {_, _,v1}, acc -> v1 + acc end)

sum = if op == "S", do: sum, else: sum/size_down_diag_part
sum = :erlang.float_to_binary(sum, [decimals: 1])
IO.puts(sum)
