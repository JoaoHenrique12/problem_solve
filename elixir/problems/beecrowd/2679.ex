import Integer
n = IO.gets("") |> String.trim() |> String.to_integer()

if Integer.is_odd(n) do
  IO.puts("#{n + 1}")
else
  IO.puts("#{n + 2}")
end
