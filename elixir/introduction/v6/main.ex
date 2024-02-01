defmodule MultiStorage do
  def new, do: %{}

  def add(storage, key, value) do
    Map.update(
      storage,
      key,
      [value],
      fn values -> [value | values] end
    )
  end

  def get(storage, key) do
    Map.get(storage,key,[])
  end
end

# fract = %Fraction{x: 1, y: 2}
# fract |> Map.to_list()
defmodule Fraction do
  defstruct x: nil, y: nil

  def new(x, y) do
    %Fraction{x: x, y: y}
  end

  def value(%Fraction{x: x, y: y}) do
    x / y
  end

  def value(fraction) do
    fraction.x / fraction.y
  end

  def add(%Fraction{x: x1, y: y1},%Fraction{x: x2, y: y2}) do
    new(
      x1 * y1 + x2 * y2,
      y1 * y2
    )
  end
end
