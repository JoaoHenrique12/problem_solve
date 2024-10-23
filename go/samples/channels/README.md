# Channels

Channels are the pipes that connect concurrent goroutines.
You can send values into channels from one goroutine and
receive those values into another goroutine.

Into a same goroutine you can't put a message on channel and remove it.

## One way channel

Exist channels that just send or receive informations.

Use of Unidirectional Channel: The unidirectional channel is used to provide the
type-safety of the program so, that the program gives less error. Or you can also
use a unidirectional channel when you want to create a channel that can only send
or receive data.
