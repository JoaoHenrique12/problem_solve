package main

import (
	"fmt"
	"os"
	// "runtime"
	"runtime/pprof"
	"time"
)

// Executing profiling CPU and memory from tests
// go test -cpuprofile cpu.prof -memprofile mem.prof -bench .

func someCPUIntensiveTask() {
	for i := 0; i < 10000000; i++ {
		_ = i * i
	}
}

func allocateMemory() {
	_ = make([]int, 1000000)
}

func main() {
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

	// Perform some tasks to profile
	fmt.Println("Starting CPU intensive task...")
	for i := 0; i < 5; i++ {
		someCPUIntensiveTask()
		time.Sleep(100 * time.Millisecond) // Simulate some work
	}
	fmt.Println("CPU intensive task finished.")

	fmt.Println("Starting memory allocation...")
	for i := 0; i < 3; i++ {
		allocateMemory()
		time.Sleep(200 * time.Millisecond) // Simulate some work
	}
	fmt.Println("Memory allocation finished.")


	// Forces a garbage collection cycle. This is important to get a more accurate snapshot of the heap at the time of profiling.
	// runtime.GC() 

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

	fmt.Println("CPU profile written to cpu.prof")
	fmt.Println("Memory profile written to mem.prof")
	fmt.Println("\nTo analyze the profiles, use the go tool pprof:")
	fmt.Println("  go tool pprof cpu.prof")
	fmt.Println("  go tool pprof mem.prof")
}
