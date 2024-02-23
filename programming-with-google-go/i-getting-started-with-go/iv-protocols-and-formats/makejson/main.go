package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"os"
)

func main() {
	person := make(map[string]string)

	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a name: ")
	bytes, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}

	person["name"] = string(bytes)

	fmt.Print("Enter an address: ")
	bytes, _, err = reader.ReadLine()
	if err != nil {
		panic(err)
	}

	person["address"] = string(bytes)

	bytes, err = json.Marshal(person)
	if err != nil {
		fmt.Println("Error:", err)
	}

	os.Stdout.Write(bytes)
}
