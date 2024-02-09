n = IO.gets("") |> String.trim() |> String.to_integer()

behave_child = for _ <- 0..n-1 do
  IO.gets("") |> String.trim() |> String.split()
end

behave_child = Enum.sort(
  behave_child,
  fn [_behave, name1],[_behave2, name2] -> name1 < name2 end
)

good_behave = Enum.reduce(
  behave_child,
  0,
  fn [behave, _name], acc -> if behave == "+", do: acc + 1 ,else: acc end
)
bad_behave = length(behave_child) - good_behave

Enum.each(behave_child,fn [_behave, name] -> IO.puts(name) end)

IO.puts("Se comportaram: #{good_behave} | Nao se comportaram: #{bad_behave}")
