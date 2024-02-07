defmodule PlayGround do
  defp ans(size) do
    for y <- 0..size-1, x <- 0..size-1 do 
      if x == 0, do: IO.write(" ")

      if ((size - 1 - x ) >= y) do
        IO.write("#{min(x + 1,y + 1)}")
      else
        IO.write("#{min(size - x ,size - y )}")
      end

      if x == size-1, do: IO.write("\n"), else: IO.write("   ")
    end
    IO.write("\n")
  end

  def main() do
    size = IO.gets("") |> String.trim() |> String.to_integer()
    if size != 0 do
      ans(size)
      main()
    end
  end
end

PlayGround.main()
