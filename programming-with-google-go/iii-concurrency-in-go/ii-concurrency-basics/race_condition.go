package main

import "fmt"

/*
When multiple goroutines share access to a variable or resource a race condition may occur.

The output of this programme will be different every time it is executed because the sequence / scheduling
of the given goroutinesis is not deterministic but dependent on the operating system and Go runtime scheduler.
*/
func main() {
	num := 1000

	for i := 0; i < 10; i++ {
		go func() { num += 1 }()
		go func() { num -= 1 }()
		go func() { num *= 1 }()
		go func() { num /= 1 }()
		go func() { num++ }()
		go func() { num-- }()
		go func() { num += 10 }()
		go func() { num -= 10 }()
		go func() { num *= 10 }()
		go func() { num /= 10 }()
	}

	fmt.Println(num)
}
