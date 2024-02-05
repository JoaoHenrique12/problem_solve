# Tutorial

## Links

[Cons Cells](https://www.gnu.org/software/emacs/manual/html_node/elisp/Cons-Cell-Type.html#:~:text=A%20cons%20cell%20is%20an,and%20likewise%20for%20the%20CDR.)

[Extension files](https://stackoverflow.com/questions/36292620/elixir-when-to-use-ex-and-when-exs-files)

[Naming conventions](https://hexdocs.pm/elixir/main/naming-conventions.html#:~:text=Functions%20that%20return%20a%20boolean%20are%20named%20with%20a%20trailing%20question%20mark.&text=However%2C%20functions%20that%20return%20booleans,follow%20another%20convention%2C%20described%20next.)

[Circuit operators](https://blog.tentamen.eu/elixir-short-circuit-operators/): &&, ||, !

## Small tips

```elixir
alias IO, as: MyIO

# ---------------------
_ -> Anonymous var
_date -> Anonymous var named date

^x = 10
^x = 11 -> error, cause pin operation.
a = b = 1 + 3

# ---------------------
"String add numbers #{3 + 4}" <> " Concat"
String.to_charlist("A string")
```

### Tuples

```elixir
cat = {"jazzpurr", 12}
age = elem(cat,1) # tuple,index

put_elem(cat,1,13) # tuple,index, value
```
