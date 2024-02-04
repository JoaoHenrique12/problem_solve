import Integer

{n, _} = IO.gets("") |> Integer.parse

for item <- 1..n, is_even(item) do
  IO.puts(Integer.to_string(item) <> "^2 = " <> Integer.to_string(item * item))
end
