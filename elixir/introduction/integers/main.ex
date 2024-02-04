round(10.3)
floor(10.3)
trunc(10.3)
ceil(10.3)

# Get line of integers
IO.gets("") |> String.split() |> Enum.map(&String.to_integer/1)

# Get mod, rem
Integer.mod(10,3)
rem(10,3)
Integer.pow(2,3)
