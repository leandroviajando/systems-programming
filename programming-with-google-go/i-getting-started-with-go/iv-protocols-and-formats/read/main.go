package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

type Person struct {
	firstName, lastName string
}

func main() {
	var tmpFileName string
	fmt.Print("Enter file name: ")
	fmt.Scanln(&tmpFileName)

	file, err := os.Open(tmpFileName)
	if err != nil {
		panic(err)
	}
	defer file.Close()

	var people []Person

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line := string(scanner.Text())

		people = append(people, Person{
			firstName: strings.Split(line, " ")[0],
			lastName:  strings.Split(line, " ")[1],
		})
	}
	if err := scanner.Err(); err != nil {
		panic(err)
	}

	for _, person := range people {
		fmt.Println()
		fmt.Println("First name:", person.firstName)
		fmt.Println("Last  name:", person.lastName)
	}

}
