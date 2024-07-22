package main

import (
	"fmt"
	"math"
)

type Animal struct {
	name               string
	weightKg           float64
	heightM            float64
	isPredator         bool
	speedkph           float64
	activityMultiplier float64
}

func NewAnimal(name string, weightKg float64, heightM float64, isPredator bool, speedkph float64, activityMulitiplier float64) *Animal {
	return &Animal{
		name:               name,
		weightKg:           weightKg,
		heightM:            heightM,
		isPredator:         isPredator,
		speedkph:           speedkph,
		activityMultiplier: 1.2,
	}
}

func (a *Animal) getBmi() float64 {
	Bmi := a.weightKg / (a.heightM * a.heightM)
	Bmiround := math.Floor(Bmi*100) / 100
	return Bmiround
}

func (a *Animal) getDailyCalories() float64 {
	Calories := 70 * math.Pow(a.weightKg, 0.75) * a.activityMultiplier
	CaloriesRound := math.Floor(Calories*100) / 100
	return CaloriesRound
}

func (a *Animal) isDangerous() bool {
	return a.isPredator || a.heightM >= 1.7 || a.speedkph >= 35
}

func main() {
	rabbit := NewAnimal("rabbit", 10, 0.3, false, 20, 1.2)
	fmt.Println(rabbit.getBmi())
	fmt.Println(rabbit.isDangerous())

	snake := NewAnimal("snake", 30, 1, true, 30, 1.2)
	fmt.Println(snake.isDangerous())
	fmt.Println(snake.getDailyCalories())

	elephant := NewAnimal("elephant", 300, 3, false, 100, 1.2)
	fmt.Println(elephant.getBmi())
	fmt.Println(elephant.getDailyCalories())

	gazelle := NewAnimal("gazelle", 50, 1.5, false, 100, 1.2)
	fmt.Println(gazelle.getDailyCalories())
	fmt.Println(gazelle.isDangerous())

}

/*
Go言語では、構造体のポインタを直接初期化するための特殊な構文は存在しません。構造体を初期化するには、構造体リテラルを使うか、コンストラクタ関数を使う必要があります。

*/
