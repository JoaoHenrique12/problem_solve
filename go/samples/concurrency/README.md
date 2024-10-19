## Concorrencia vs Paralelismo

Concurrency is when two or more tasks can start, run, and complete in overlapping time periods.
It doesn't necessarily mean they'll ever both be running at the same instant. For example, multitasking
on a single-core machine.

Parallelism is when tasks literally run at the same time, e.g., on a multicore processor.

A **thread** is a basic unit of execution of any process. [threads](https://stackoverflow.com/questions/5201852/what-is-a-thread-really).

**Yield**, is the time spent to change between processes.

```bash
go run -race main.go
```
