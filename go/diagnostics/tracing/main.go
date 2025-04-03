package main

import (
	"context"
	"fmt"
	"log"
	"os"
	"runtime/trace"
	"sync"
)

// Wrapper for tracing any function
func traceFunction(name string, fn func()) {
	// Create a new independent task for each function call
	ctx, task := trace.NewTask(context.Background(), name)
	defer task.End()

	// Add a custom log event so the name appears in the trace
	trace.Log(ctx, "goroutine_name", name)

	trace.Log(ctx, "event", name+" started")
	fn()
	trace.Log(ctx, "event", name+" completed")
}

func main() {
	// Create trace file
	f, err := os.Create("trace.out")
	if err != nil {
		log.Fatalf("failed to create trace file: %v", err)
	}
	defer f.Close()

	// Start tracing
	if err := trace.Start(f); err != nil {
		log.Fatalf("failed to start trace: %v", err)
	}
	defer trace.Stop()

	// Use a WaitGroup to wait for goroutines
	var wg sync.WaitGroup
	wg.Add(2)

	go func() {
		defer wg.Done()
		traceFunction("tracedFunction1", tracedFunction)
	}()

	go func() {
		defer wg.Done()
		traceFunction("tracedFunction2", tracedFunction)
	}()

	wg.Wait() // Wait for all goroutines to finish
}

// Function remains unaware of tracing
func tracedFunction() {
	fmt.Println("Executing traced function...")
}
