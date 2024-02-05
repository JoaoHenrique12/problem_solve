# Float to integer.
round(10.3)
floor(10.3)
trunc(10.3)
ceil(10.3)

# Get line of integers
IO.gets("") |> String.split() |> Enum.map(&String.to_integer/1)

# Operations
rem(10,3)
div 10, 3

Integer.mod(10,3)
Integer.pow(2,3)

Integer.to_string 123

:math.sin(:math.pi)
