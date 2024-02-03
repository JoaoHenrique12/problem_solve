sync_fn = fn x -> Process.sleep(1000); " sync: #{x} " end
async_fn = fn x -> spawn(fn -> IO.puts(sync_fn.(x <> " async")) end) end

IO.puts(Enum.each(1..2, &sync_fn.("test #{&1}")))

Enum.each(1..5, &async_fn.("test #{&1}"))

send(self(), "Hello, process.")

receive do msg -> IO.puts(msg)
after 5000 -> IO.puts("Error, no message")
end

send(self(), {:msg, 10})

result = receive do { :msg, x } -> x * x
end
