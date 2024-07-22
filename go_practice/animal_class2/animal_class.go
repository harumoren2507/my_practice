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
	speedKph           float64
	activityMultiplier float64
}

// Bmiを計算するメソッド
func (a *Animal) getBmi() float64 {
	Bmi := a.weightKg / (a.heightM * a.heightM)
	Bmiround := math.Floor(Bmi*100) / 100
	return Bmiround
}

// 一日に必要なカロリーを計算するメソッド
func (a *Animal) getDailyCalories() float64 {
	Calories := 70 * math.Pow(a.weightKg, 0.75) * a.activityMultiplier
	Caloriesround := math.Floor(Calories*100) / 100
	return Caloriesround
}

// 危険かどうか判断するメソッド
func (a *Animal) isDangerous() bool {
	return a.isPredator || a.heightM >= 1.7 || a.speedKph >= 35
}

// NewAnimal関数...新しいAnimal構造体のインスタンスを作成し、そのポインタを返す関数
func NewAnimal(name string, weightKg float64, heightM float64, isPredator bool, speedKph float64, activityMultiplier float64) *Animal {
	return &Animal{
		name:               name, //右側は各引数を指定している
		weightKg:           weightKg,
		heightM:            heightM,
		isPredator:         isPredator,
		speedKph:           speedKph,
		activityMultiplier: activityMultiplier,
	}
}

func main() {
	rabbit := NewAnimal("rabbit", 10, 0.3, false, 20, 1.2)
	fmt.Println(rabbit.getBmi())
	fmt.Println(rabbit.isDangerous())

	snake := NewAnimal("snake", 30, 1, true, 30, 1.2)
	fmt.Println(snake.isDangerous())
	fmt.Println(snake.getDailyCalories())

	elephant := NewAnimal("elephant", 300, 3, false, 5, 1.2)
	fmt.Println(elephant.getBmi())
	fmt.Println(elephant.getDailyCalories())

	gazelle := NewAnimal("gazelle", 50, 1.5, false, 100, 1.2)
	fmt.Println(gazelle.getDailyCalories())
	fmt.Println(gazelle.isDangerous())
}
