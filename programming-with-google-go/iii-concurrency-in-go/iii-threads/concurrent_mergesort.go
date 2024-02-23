package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

const numChannels = 4

func main() {
	reader := bufio.NewReader(os.Stdin)

	var inputs []string
	var n int

	for n < numChannels {
		fmt.Print("Enter a space-separated list of integers to sort (min numChannels): ")

		bytes, _, _ := reader.ReadLine()

		inputs = strings.Split(string(bytes), " ")

		n = len(inputs)
	}

	nums := make([]int, n)
	for idx, str := range inputs {
		num, err := strconv.Atoi(str)
		if err != nil {
			panic(err)
		}

		nums[idx] = num
	}
	fmt.Println("Integers:", nums)

	var res []int
	ch := make(chan []int)

	steps := int(math.Ceil(float64(n) / float64(numChannels)))
	for i := 0; i < n; i += steps {
		go sortNums(nums[i:int(math.Min(float64(i+steps), float64(n)))], ch)
	}

	for i := 0; i < numChannels; i++ {
		res = merge(res, <-ch)
	}

	fmt.Println("Sorted integers:", res)
}

func sortNums(nums []int, ch chan []int) {
	sort.Ints(nums)

	fmt.Println("Sorted sub-array:", nums)

	ch <- nums
}

func merge(left, right []int) []int {
	length := len(left) + len(right)
	slice := make([]int, length)

	i, j := 0, 0
	for k := 0; k < length; k++ {
		if i > len(left)-1 && j <= len(right)-1 {
			slice[k] = right[j]
			j++
		} else if j > len(right)-1 && i <= len(left)-1 {
			slice[k] = left[i]
			i++
		} else if left[i] < right[j] {
			slice[k] = left[i]
			i++
		} else {
			slice[k] = right[j]
			j++
		}
	}

	return slice
}
