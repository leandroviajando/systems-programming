package main

import "C"
import "fmt"

/*
 * isStackGrowingUpwards recursively checks the stack growth direction.
 *
 * Returns 1 if the stack grows upwards, 0 if downwards.
 */
func isStackGrowingUpwards(previous *int) bool {
	var current int

	if previous == nil {
		return isStackGrowingUpwards(&current)
	}

	return current > *previous
}

func main() {
	fmt.Println("This is a Go script checking stack growth direction:")
	if isStackGrowingUpwards(nil) {
		fmt.Println("Up")
	} else {
		fmt.Println("Down")
	}
}
