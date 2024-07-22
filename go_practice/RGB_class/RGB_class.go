package main

import "fmt"

type RGB struct {
	red   int
	green int
	blue  int
}

func NewRGB(red, green, blue int) *RGB {
	return &RGB{red: red, green: green, blue: blue}
}

func (r *RGB) GetHexCode() string {
	return fmt.Sprintf("#%02x%02x%02x", r.red, r.green, r.blue)
}

//func (r *RGB) getBits() string {
//
//}

func main() {
	RGB1 := NewRGB(0, 153, 255)
	fmt.Println(RGB1.GetHexCode())
}

/*
RGBクラス
medium
開発中のアプリケーションで色を実装することになりました。色は一般的に RGB（Red-Green-Blue）カラーモデルを使って定義されます。RGB の各色は、0 から 255 までの数値で表されます。以下の構造に沿った、色の設計図を作成し、テストケースを出力してください。

int red: 0 から 255 までの数値
int green: 0 から 255 までの数値
int blue: 0 から 255 までの数値
String getHexCode(): カラーコードを 16 進数（文字列）で返します。文字列の先頭には # をつけてください。
String getBits(): カラーコードを 2 進数で返します。取得した 16 進数を 2 進数へ変換してください。
String getColorShade(): 赤、青、緑の中でどの色が濃いのかを文字列で返します。全ての色の強さが同じ場合、grayscale と返してください。もし複数の色が同じ最大値を持っていた場合（例：R:230, G:230, B:50）、最初に現れる最大値の色を返します。


sample


package main

import (
	"fmt"
)

// RGB struct to represent a color in RGB format
type RGB struct {
	red   int
	green int
	blue  int
}

// NewRGB is a constructor for the RGB struct
func NewRGB(red, green, blue int) *RGB {
	return &RGB{red: red, green: green, blue: blue}
}

// GetHexCode returns the color code in hexadecimal format
func (c *RGB) GetHexCode() string {
	return fmt.Sprintf("#%02x%02x%02x", c.red, c.green, c.blue)
}

// GetBits returns the color code in binary format
func (c *RGB) GetBits() string {
	rBits := fmt.Sprintf("%08b", c.red)
	gBits := fmt.Sprintf("%08b", c.green)
	bBits := fmt.Sprintf("%08b", c.blue)
	binaryString := rBits + gBits + bBits

	// Remove leading zeros
	trimmedBinaryString := binaryString
	for i := 0; i < len(binaryString); i++ {
		if binaryString[i] != '0' {
			trimmedBinaryString = binaryString[i:]
			break
		}
	}
	return trimmedBinaryString
}

// GetColorShade returns the shade of the color
func (c *RGB) GetColorShade() string {
	if c.red == c.green && c.green == c.blue {
		return "grayscale"
	}
	if c.red >= c.green && c.red >= c.blue {
		return "red"
	}
	if c.green >= c.red && c.green >= c.blue {
		return "green"
	}
	return "blue"
}

// Test cases to verify the implementation
func main() {
	color1 := NewRGB(0, 153, 255)
	fmt.Println(color1.GetHexCode())         // #0099ff
	fmt.Println(color1.GetBits())            // 1001100111111111
	fmt.Println(color1.GetColorShade())      // blue

	color2 := NewRGB(255, 255, 204)
	fmt.Println(color2.GetHexCode())         // #ffffcc
	fmt.Println(color2.GetBits())            // 111111111111111111001100
	fmt.Println(color2.GetColorShade())      // red

	color3 := NewRGB(0, 87, 0)
	fmt.Println(color3.GetHexCode())         // #005700
	fmt.Println(color3.GetBits())            // 101011100000000
	fmt.Println(color3.GetColorShade())      // green

	gray := NewRGB(123, 123, 123)
	fmt.Println(gray.GetHexCode())           // #7b7b7b
	fmt.Println(gray.GetBits())              // 11110110111101101111011
	fmt.Println(gray.GetColorShade())        // grayscale
}


*/
