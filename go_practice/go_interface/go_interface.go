package main

import (
	"fmt"
)

type controller interface {
	speedUp() int
	speedDown() int
}

type vehicle struct {
	speed       int
	enginePower int
}

type bycycle struct {
	speed      int
	humanPower int
}

func (v *vehicle) speedUp() int {
	v.speed += 10 * v.enginePower
	return v.speed
}

func (v *vehicle) speedDown() int {
	v.speed -= 5 * v.enginePower
	return v.speed
}

func (b *bycycle) speedUp() int {
	b.speed += 5 * b.humanPower
	return b.speed
}
func (b *bycycle) speedDown() int {
	b.speed -= 3 * b.humanPower
	return b.speed
}

func speedUpDown(c controller) {
	fmt.Printf("current speed %v\n", c.speedUp())
	fmt.Printf("current speed %v\n", c.speedDown())
}

func main() {
	v := &vehicle{0, 5}
	b := &bycycle{0, 5}
	speedUpDown(v)
	speedUpDown(b)
}
