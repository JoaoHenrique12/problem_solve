_ = IO.gets("") |> String.trim() |> String.to_integer()

lista = IO.gets("") |> String.split() |> Enum.map(&String.to_integer/1) |> Enum.with_index()

{ min_value, min_index } = Enum.min_by(lista, &(&1))

IO.puts("Menor valor: #{min_value}")
IO.puts("Posicao: #{min_index}")
