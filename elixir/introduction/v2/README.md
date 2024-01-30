# Explain

```elixir
Enum.each({list}, {function})

# Anonymous Functions
l = fn x, y, z -> z * y + x end
l = &(&3 * &2 + &1)
l.(1,2,3) # 7
```
```elixir
outside = 10
closure = fn -> IO.puts outside end
outside = 100
closure.()
```

```elixir
range = 1..100

IO.inspect([1,2,3], width: 3, limit: 1)
```

```elixir
keys = MapSet.new([:a, :b, :c])
MapSet.member?(keys, :d)
keys = MapSet.put(keys, :a)

# Dates
date = ~D[YYYY-MM-DD]
date.year

time = ~T[HH:MM:SS.SSSS]
time.hour
time.microsecond
```
