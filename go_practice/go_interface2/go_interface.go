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

func PrintAnimalSound(a Animal) {//Animalインターフェース型が引数。つまり、この関数はAnimalインターフェースを満たす任意の型を受け取ることができる。
	fmt.Println(a.Speak())
} 

func main() {
	dog := &Dog{}
	cat := &Cat{}

	PrintAnimalSound(dog)
	PrintAnimalSound(cat)
}

/*
インターフェースの条件とは


ソッドの実装:

インターフェースに定義されたメソッドのシグネチャ（メソッド名、引数の型、返り値の型）をすべて実装する必要があります。
型の一致:

実装されるメソッドは、インターフェースで定義されたシグネチャと完全に一致している必要があります。
明示的な宣言は不要:

Goでは、型がインターフェースを実装するために特別な宣言をする必要はありません。必要なメソッドをすべて実装していれば、自動的にそのインターフェースを実装しているとみなされます



:?
