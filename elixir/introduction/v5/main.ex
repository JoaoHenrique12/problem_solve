defmodule Playground do
  def sum([]), do: 0
  def sum([h|t]) do
    h + sum(t)
  end

  def get_fib(n) do
    start = :os.system_time(:seconds)
    ans = fib(n)
    finish = :os.system_time(:seconds)
    delta = finish - start
    IO.puts("Fib: #{ans}")
    IO.puts("Time: #{delta}")
  end

  defp fib(n) when n < 0, do: :error
  defp fib(n), do: fib(n, 1, 0)
  defp fib(0, _, result), do: result
  defp fib(n, next, result), do: fib(n - 1, next + result, next)
end

# Enum.each([1,2,3], fn x -> IO.puts(x) end)
# Enum.map([1,2,3], fn x -> x * 2 end)
# Enum.filter([1,2,3], fn x -> Integer.is_odd(x) end)
# Enum.reduce([1,2,3],0, fn x,y -> x + y end) # {iter}, {init}, {fn {acumulator}, {params}}

# for x <- [1,2,3], y <- [1,2,3], do: {x,y, x*y}
# for x <- 1..9, y <- 1..9, x < y, into: %{},  do: {{x,y}, x*y}

# for x <- 1..9, y <- 1..9, x < y, into: %{} do
#   {{x,y}, x*y}
# end
