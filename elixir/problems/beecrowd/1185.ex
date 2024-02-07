op = IO.gets("") |> String.trim()

size = 12
square = for x <- 0..(size - 1), y <- 0..(size - 1) do 
  {value, _} = IO.gets("") |> String.trim() |> Float.parse()
  {x, y, value}
end

up_sedond_diag_part = Enum.filter(square,
  fn {y, x, _value} -> (size - x - 1 > y) end
)

size_up_sedond_diag_part = length(up_sedond_diag_part)

sum = Enum.reduce(up_sedond_diag_part, 0, fn {_, _,v1}, acc -> v1 + acc end)

sum = if op == "S", do: sum, else: sum/size_up_sedond_diag_part
sum = :erlang.float_to_binary(sum, [decimals: 1])
IO.puts(sum)
