{n, _} = IO.gets("") |> Integer.parse
{m, _} = IO.gets("") |> Integer.parse

{m, n} = if m < n, do: {n, m}, else: {m, n}

not_13 = Enum.filter( n..m, fn x -> rem(x,13) != 0 end)
ans = Enum.reduce( not_13, 0, fn x, y -> x + y end)

IO.puts(ans)
