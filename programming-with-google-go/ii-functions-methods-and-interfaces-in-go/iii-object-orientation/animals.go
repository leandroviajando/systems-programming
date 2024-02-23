package main

import "fmt"

type Animal struct {
	food, locomotion, noise string
}

var animals = map[string]Animal{
	"cow":   {food: "grass", locomotion: "walk", noise: "moo"},
	"bird":  {food: "worms", locomotion: "fly", noise: "peep"},
	"snake": {food: "mice", locomotion: "slither", noise: "hiss"},
}

func (a Animal) Eat() {
	fmt.Println(a.food)
}

func (a Animal) Move() {
	fmt.Println(a.locomotion)
}

func (a Animal) Speak() {
	fmt.Println(a.noise)
}

func main() {
	for {
		fmt.Print("Enter animal name and activity: ")

		var animalName, activity string
		fmt.Scanf("%s %s", &animalName, &activity)

		animal, found := animals[animalName]
		if !found {
			fmt.Println("No animal with such name")
			continue
		}

		switch activity {
		case "eat":
			animal.Eat()
		case "move":
			animal.Move()
		case "speak":
			animal.Speak()
		default:
			fmt.Println("No such activity")
		}
	}
}
