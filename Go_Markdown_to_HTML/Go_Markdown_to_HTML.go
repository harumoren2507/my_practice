package main

import (
	"fmt"
	"io/ioutil"
	"os"

	"github.com/russross/blackfriday"
)

func markdownToHTML(inputFile, outputFile string) error {
	inputBytes, err := ioutil.ReadFile(inputFile)
	if err != nil {
		return err
	}

	htmlBytes := blackfriday.Run(inputBytes)

	err = ioutil.WriteFile(outputFile, htmlBytes, 0644)
	if err != nil {
		return err
	}

	return nil
}

func main() {
	if len(os.Args) != 4 || os.Args[1] != "markdown" {
		fmt.Println("Usage: go run main.go markdown inputfile outputfile")
		return
	}

	inputFile := os.Args[2]
	outputFile := os.Args[3]

	err := markdownToHTML(inputFile, outputFile)
	if err != nil {
		fmt.Println("Error:", err)
		return
	}

	fmt.Println("Markdown to HTML conversion completed!")
}
