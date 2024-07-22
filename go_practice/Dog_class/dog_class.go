package main

import (
	"fmt"
)

type Dog struct {
	name string
	size int
	age  int
}

func newDog(name string, size int, age int) *Dog {
	return &Dog{
		name: name,
		size: size,
		age:  age,
	}
}

func (a *Dog) bark() string {
	if a.size >= 50 {
		return "Wooof! Woof!"
	} else if a.size >= 20 {
		return "Ruff! Ruff!"
	} else {
		return "Yip! Yip!"
	}
}

func (a *Dog) calcHumanAge() int {
	HumanAge := 12 + ((*a).age-1)*7
	return HumanAge
}

func main() {
	goldenRetriver := newDog("goldenRetriver", 60, 10)
	fmt.Println(goldenRetriver.bark())
	fmt.Println(goldenRetriver.calcHumanAge())

	siberianHusky := newDog("Siberian Husky", 55, 6)
	fmt.Println(siberianHusky.bark())
	fmt.Println(siberianHusky.calcHumanAge())

	poodle := newDog("poodle", 10, 1)
	fmt.Println(poodle.bark())
	fmt.Println(poodle.calcHumanAge())

	shibaInu := newDog("shibaInu", 35, 4)
	fmt.Println(shibaInu.bark())
	fmt.Println(shibaInu.calcHumanAge())
}
