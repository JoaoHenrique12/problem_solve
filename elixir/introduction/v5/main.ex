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

  defp fib(0), do: 0
  defp fib(1), do: 1
  defp fib(n) when n < 0, do: :error
  defp fib(n), do: fib(n - 1) + fib(n - 2)
end
