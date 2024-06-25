package main

import (
	"C"
	"fmt"
	"sync"
)

const (
	numGoroutines          = 10
	incrementsPerGoroutine = 1000
	decrementsPerGoroutine = 900
)

type Counter struct {
	mu    sync.Mutex
	value int
}

func (c *Counter) Increment() {
	c.mu.Lock()
	defer c.mu.Unlock()
	c.value++
}

func (c *Counter) Decrement() {
	c.mu.Lock()
	defer c.mu.Unlock()
	c.value--
}

func (c *Counter) Get() int {
	c.mu.Lock()
	defer c.mu.Unlock()
	return c.value
}

func main() {
	counter := &Counter{}
	var wg sync.WaitGroup

	for i := 0; i < numGoroutines; i++ {
		wg.Add(1)
		go func() {
			defer wg.Done()
			for j := 0; j < incrementsPerGoroutine; j++ {
				counter.Increment()
			}
			for j := 0; j < decrementsPerGoroutine; j++ {
				counter.Decrement()
			}
		}()
	}

	wg.Wait()
	fmt.Printf("Final count: %d\n", counter.Get())
}
