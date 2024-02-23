package main

import "fmt"

func main() {
	var float float64

	fmt.Printf("Enter float: ")
	fmt.Scan(&float)

	fmt.Printf("%.0f", float)
}
