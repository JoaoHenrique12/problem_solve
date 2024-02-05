l = fn x, y, z -> z * y + x end
l = &(&3 * &2 + &1)
l.(1,2,3) # 7

p = &IO.puts/1
p.(str)

def small_area(x,y), do: x*y
