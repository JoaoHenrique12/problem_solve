defmodule Playground do
  def max_first(a,b) do
    if a >= b, do: a, else: b
    #unless a >= b, do: b, else: a
  end

  def max_second(a,b) do
    case a >= b do
      true -> a
      false -> b
      _ -> :error
    end
  end

  def my_function(number) when is_integer(number) and rem(number, 2) == 0 do
      IO.puts( "It's a even" )
  end

  def my_function(number) when is_integer(number) and rem(number, 2) == 1 do
      IO.puts( "It's a odd" )
  end
end

defmodule Validator do
  def extract_user(user) do
    with {:ok, login} <- extract_login(user),
         {:ok, email} <- extract_email(user),
         {:ok, password} <- extract_password(user) do

      {:ok, %{login: login, email: email, password: password}}
      end
  end

  defp extract_login(%{"login" => login}), do: {:ok, login}
  defp extract_login(_), do: {:error, "login missing"}

  defp extract_email(%{"email" => email}), do: {:ok, email}
  defp extract_email(_), do: {:error, "email missing"}

  defp extract_password(%{"password" => password}), do: {:ok, password}
  defp extract_password(_), do: {:error, "password missing"}
end
