package main 

import (
	"fmt"
)

type Animal interface {
	Speak() string
}

type Dog struct{}

func (d *Dog) Speak() string {
	return "Woof!"
}


type Cat struct{}

func (c *Cat)Speak() string {
	return "Meow!"
}

func PrintAnimalSound(a Animal) {
	fmt.Println(a.Speak())
} 

func main() {
	dog := &Dog{}
	cat := &Cat{}

	PrintAnimalSound(dog)
	PrintAnimalSound(cat)
}

