package main

import (
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

const exitCode = "X"

func main() {
	ints := make([]int, 0, 3)

	var str string
	for {
		fmt.Print("Enter an integer: ")
		if _, err := fmt.Scan(&str); err != nil {
			fmt.Println(err.Error())
			os.Exit(1)
		}

		if strings.ToUpper(str) == exitCode {
			fmt.Println("Exiting")
			os.Exit(0)
		}

		integer, err := strconv.Atoi(str)
		if err != nil {
			panic(err)
		}

		ints = append(ints, integer)
		sort.Ints(ints)

		fmt.Println(ints)
	}
}
