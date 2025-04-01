# Diagnostics

[Reference](https://go.dev/doc/diagnostics)

Note: Some diagnostics tools may interfere with each other. For example, precise memory profiling skews CPU profiles and goroutine blocking profiling affects scheduler trace. Use tools in isolation to get more precise info.


## Profiling

Profiling tools analyze the complexity and costs of a Go program such as its memory usage and frequently called functions to identify the expensive sections of a Go program.

- [pprof](https://pkg.go.dev/runtime/pprof)
  - [profiling go programs](https://go.dev/blog/pprof)
- [perf](https://perfwiki.github.io/main/)

## Tracing

Tracing is a way to instrument code to analyze latency throughout the lifecycle of a call or user request. Traces provide an overview of how much latency each component
contributes to the overall latency in a system. Traces can span multiple Go processes.

Is there a way to automatically intercept each function call and create traces?

Go doesn’t provide a way to automatically intercept every function call and create trace spans. You need to manually instrument your code to create, end, and annotate spans.

- [tracing](https://pkg.go.dev/golang.org/x/net/trace)

## Debuging

Debugging allows us to pause a Go program and examine its execution. Program state and flow can be verified with debugging.

- [delve](https://github.com/derekparker/delve)

## Runtime Statistics and Events

Collection and analysis of runtime stats and events provides a high-level overview of the health of Go programs. Spikes/dips of metrics helps us to identify changes in throughput, utilization, and performance.
