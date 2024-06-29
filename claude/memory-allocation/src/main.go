package main

import (
	"C"
	"fmt"
)

type Vector struct {
	data []int
}

func NewVector() *Vector {
	return &Vector{data: make([]int, 0, 2)}
}

func (v *Vector) Push(value int) {
	v.data = append(v.data, value)
}

func (v *Vector) Get(index int) int {
	return v.data[index]
}

func (v *Vector) Size() int {
	return len(v.data)
}

func main() {
	vec := NewVector()
	vec.Push(1)
	vec.Push(2)
	vec.Push(3)
	for i := 0; i < vec.Size(); i++ {
		fmt.Println(vec.Get(i))
	}
}
