defmodule Geometry do
  def area({:rectangle, a,b}) do
    a*b
  end

  def area({:square, a}) do
    a*a
  end

  def area({:circle, r}) do
    :math.pow(r,2) * :math.pi
  end

  def area(unknown) do
    {:error, {:unknown_shape, unknown}}
  end
end
