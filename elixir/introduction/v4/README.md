# Guards

Guards are a way to augment pattern matching with more complex checks.
They are allowed in a predefined set of constructs where pattern matching is allowed.
Guards start with the when keyword, which is followed by a boolean expression

**Where use it**

- Function clauses
- Case expressions
- Anonymous functions

## if/else/unless

```elixir
if true do
  "This works!"
end

unless true do
  "This will never be seen"
end
```

```elixir
x = if nil do
  "This won't be seen"
else
  "This will"
end
```

## cond

```elixir
cond do
  2 + 2 == 5 ->
    "This will not be true"
  2 * 2 == 3 ->
    "Nor this"
  1 + 1 == 2 ->
    "But this will"
end
```

## case

```elixir
case {1, 2, 3} do
  {4, 5, 6} ->
    "This clause won't match"
  {1, x, 3} ->
    "This clause will match and bind x to 2 in this clause"
    IO.puts(x)
  _ ->
    "This clause would match any value"
end
```
