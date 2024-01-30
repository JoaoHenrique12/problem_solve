defmodule Playground do
  def area(a,b) do
    a*b
  end

  def small_area(x,y), do: x*y

  def name do
    "NAME: SMALL_TALK"
  end

  def anom v do
    anonymous = fn x -> x * x end
    anonymous.(v)
  end

  def put str do
    p = &IO.puts/1
    p.(str)
  end
end
