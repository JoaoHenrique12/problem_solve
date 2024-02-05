defmodule Geometry do
  def area({:rectangle, a,b}), do: a*b
  def area({:square, a}), do: a*a
  def area({:circle, r}), do: :math.pow(r,2) * :math.pi

  def area(unknown), do: {:error, {:unknown_shape, unknown}}
end
