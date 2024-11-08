package test

import (
	"log"
	"os"
)

type MessageServiceInterFace interface {
	PostMessage(string, string) error
}

type MessageRepository struct{}

func (r *MessageRepository) Post(sender string, message string) error {
	log.Printf("Sender: %s, Message: %s", sender, message)
	return nil
}

type MessageService struct {
	repository *MessageRepository
}

func (svc *MessageService)PostMessage(sender string, message string) error {
	return svc.repository.Post(sender, message)
}

func NewService(repo *MessageRepository) *MessageService {
	return &MessageService{
		repository: repo,
	}
}

func main() {
	var srv MessageServiceInterFace
	if os.Getenv("test") != "" {
		srv := 
	}
}
