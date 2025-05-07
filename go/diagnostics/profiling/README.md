# Profiling

## Executing profiling tool

```bash
go tool pprof cpu.prof

# MEM
go tool pprof mem.prof

# The first lines show the total amount of memory used.
go tool pprof -top mem.prof

## This mode shows the allocation counts, not the memory consumed
go tool pprof --inuse_objects mem.prof 

## ignore nodes that don’t account for at least 10% of the samples:
go tool pprof --nodefraction=0.1 mem.prof 

```

```bash
(pprof) top10
(pprof) top5 -cum
(pprof) text
(pprof) list some_function_name


(pprof) web
(pprof) web someCPUIntensiveTask

(pprof) web mallocgc
```

### Explanation of output

```bash

(pprof) top10

Showing nodes accounting for 130ms, 100% of 130ms total

      flat  flat%   sum%        cum   cum%

     120ms 92.31% 92.31%      120ms 92.31%  main.someCPUIntensiveTask (inline)

      10ms  7.69%   100%       10ms  7.69%  runtime.memclrNoHeapPointers

         0     0%   100%       10ms  7.69%  main.allocateMemory (inline)

         0     0%   100%      130ms   100%  main.main

         0     0%   100%      130ms   100%  runtime.main

         0     0%   100%       10ms  7.69%  runtime.makeslice

         0     0%   100%       10ms  7.69%  runtime.mallocgc

         0     0%   100%       10ms  7.69%  runtime.memclrNoHeapPointersChunked

```

- flat: this column shows the total time spent in the function itself during the profiling period. it doesn't include the time spent in any functions that this function calls.

- sum: this column shows the cumulative percentage of the flat% values as you go down the list. it helps you quickly identify the functions that, together, account for a significant portion of the total time.

- cum: this column shows the cumulative time spent in the function, including the time spent in all the functions it called. it represents the total time the program was executing within that function's call stack.


## Creating CPU/MEMory Profiling

Running profiling inside test suit.

```bash
go test -cpuprofile cpu.prof -memprofile mem.prof -bench .
```

### Setup endpoints

#### CPU

```go
// Create CPU profile file
cpuFile, err := os.Create("cpu.prof")
if err != nil {
	fmt.Fprintf(os.Stderr, "could not create CPU profile: %v\n", err)
	os.Exit(1)
}
defer cpuFile.Close()

// Start CPU profiling
if err := pprof.StartCPUProfile(cpuFile); err != nil {
	fmt.Fprintf(os.Stderr, "could not start CPU profile: %v\n", err)
	os.Exit(1)
}
defer pprof.StopCPUProfile()
```

#### MEM

```go

import "runtime/pprof", "runtime"
// Forces a garbage collection cycle. This is important to get a more accurate snapshot of the heap at the time of profiling.
runtime.GC() 

// Create memory profile file
memFile, err := os.Create("mem.prof")
if err != nil {
	fmt.Fprintf(os.Stderr, "could not create memory profile: %v\n", err)
	os.Exit(1)
}
defer memFile.Close()

// Get memory profile
if err := pprof.WriteHeapProfile(memFile); err != nil {
	fmt.Fprintf(os.Stderr, "could not write memory profile: %v\n", err)
	os.Exit(1)
}
```
