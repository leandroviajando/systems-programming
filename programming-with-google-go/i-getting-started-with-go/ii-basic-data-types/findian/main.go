package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	fmt.Printf("Enter string: ")

	reader := bufio.NewReader(os.Stdin)
	bytes, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}

	str := string(bytes)
	str = strings.TrimSpace(str)
	str = strings.ToLower(str)

	if strings.HasPrefix(str, "i") && strings.Contains(str, "a") && strings.HasSuffix(str, "n") {
		fmt.Printf("Found!")
	} else {
		fmt.Printf("Not Found")
	}
}
