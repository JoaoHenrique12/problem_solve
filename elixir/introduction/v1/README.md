# Init

## First glance
elixir main.exs
iex -> Interpreter.

```
div 5, 2
rem(5,2)

:atom
:"Valid &%atom"
var = :atom

alias IO, as: MyIO

true and not false or false
nil

"String add numbers #{3 + 4}" <> " Concat"
~s(This is a string)
'Charactere list, single quote #{3 + 5}'
~c(This is a charactere list)
String.to_charlist("A string")
```
[Circuit operators](https://blog.tentamen.eu/elixir-short-circuit-operators/): &&, ||, !

### Collections

#### Tuples

```elixir
cat = {"jazzpurr", 12}
age = elem(cat,1) # tuple,index

put_elem(cat,1,13) # tuple,index, value
```

#### Lists

```elixir
numbers = [1, 2, 3, 4]

length(numbers)

Enum.at(numbers, {index})
Enum.at(numbers, {index}) # index > length(numbers) then return nil, negative numbers return mod number.
3 in numbers # true

numbers = List.replace_at(numbers,{index}, {new_value})
List.insert_at(numbers,{index}, {new_value})

concatenated_list = numbers ++ numbers

[head | tails] = [1, 2, 3, 4]

# Constant time operators
hd(numers) # Head
tl(numers) # Tails

alist = [1,true, :atom]
alist = [:head | alist]
```
[Cons Cells](https://www.gnu.org/software/emacs/manual/html_node/elisp/Cons-Cell-Type.html#:~:text=A%20cons%20cell%20is%20an,and%20likewise%20for%20the%20CDR.)

#### Maps
```
empty = %{}
sqrs = %{1 => 1, 2 => 4, 3 => 9}

sqrs[1]
Map.get(sqrs,{key})

cat = %{name: "tim", age: 12}

# Replace elements
cat = %{cat | name: "pope"}
```
