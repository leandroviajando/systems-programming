package main

import "fmt"

type Animal interface {
	Eat()
	Move()
	Speak()
}

type animal struct {
	name, species, food, locomotion, noise string
}

func newCow(name string) animal {
	return animal{name: name, species: "cow", food: "grass", locomotion: "walk", noise: "moo"}
}

func newBird(name string) animal {
	return animal{name: name, species: "bird", food: "worms", locomotion: "fly", noise: "peep"}
}

func newSnake(name string) animal {
	return animal{name: name, species: "snake", food: "mice", locomotion: "slither", noise: "hiss"}
}

func (a animal) Eat() {
	fmt.Println(a.food)
}

func (a animal) Move() {
	fmt.Println(a.locomotion)
}

func (a animal) Speak() {
	fmt.Println(a.noise)
}

func main() {
	animals := make(map[string]Animal)

	for {
		fmt.Print("> ")

		var command, name, arg string
		fmt.Scanf("%s %s %s", &command, &name, &arg)

		switch command {
		case "newanimal":
			switch arg {
			case "cow":
				animals[name] = newCow(name)
			case "bird":
				animals[name] = newBird(name)
			case "snake":
				animals[name] = newSnake(name)
			default:
				fmt.Println("No such action")
			}
		case "query":
			animal, found := animals[name]
			if !found {
				fmt.Println("No animal with such name")
				break
			}

			switch arg {
			case "eat":
				animal.Eat()
			case "move":
				animal.Move()
			case "speak":
				animal.Speak()
			default:
				fmt.Println("No such action")
			}
		default:
			fmt.Println("No such command")
		}
	}
}
