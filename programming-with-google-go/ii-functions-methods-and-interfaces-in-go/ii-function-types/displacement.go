package main

import (
	"fmt"
	"math"
)

func main() {
	var a, v, s, t float64

	fmt.Printf("Enter value for acceleration: ")
	fmt.Scanf("%f", &a)
	fmt.Printf("Enter value for initial velocity: ")
	fmt.Scanf("%f", &v)
	fmt.Printf("Enter value for initial displacement: ")
	fmt.Scanf("%f", &s)

	displacement := displacementFuncPartial(a, v, s)

	fmt.Printf("Enter value for time: ")
	fmt.Scanf("%f", &t)

	fmt.Println("The displacement is:", displacement(t))
}

func displacementFuncPartial(a, v, s float64) func(float64) float64 {
	displacement := func(t float64) float64 {
		return (0.5)*(a*math.Pow(t, 2)) + (v * t) + s
	}

	return displacement
}
