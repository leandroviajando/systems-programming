package main

import "fmt"

func main() {
	inputs := make([]int, 10)

	for i := 0; i < 10; i++ {
		fmt.Print("Enter integer ", i+1, ": ")
		fmt.Scan(&inputs[i])
	}

	fmt.Println("Inputs: ", inputs)

	BubbleSort(inputs)

	fmt.Println("Sorted:  ", inputs)
}

func BubbleSort(inputs []int) {
	for i := 0; i < len(inputs)-1; i++ {
		for j := 0; j < len(inputs)-1-i; j++ {
			swap(inputs, j)
		}
	}
}

func swap(slice []int, index int) {
	if slice[index] > slice[index+1] {
		tmp := slice[index+1]

		slice[index+1] = slice[index]
		slice[index] = tmp
	}
}
