package main

import (
	"context"
	"fmt"
	"log"
	"os"
	"runtime/trace"
)

// Wrapper for tracing any function
func traceFunction(ctx context.Context, name string, fn func()) {
	ctx, task := trace.NewTask(ctx, name)
	defer task.End()

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

	// Create a task for the main function
	ctx, task := trace.NewTask(context.Background(), "mainTask")
	defer task.End()

	// Run function with tracing
	traceFunction(ctx, "tracedFunction", tracedFunction)
}

// Function remains unaware of tracing
func tracedFunction() {
	fmt.Println("Executing traced function...")
}
