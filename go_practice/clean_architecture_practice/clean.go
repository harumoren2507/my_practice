package main

import (
	"log"
	"os"
)

// MessageRepository は、メッセージの永続化を担当します。
// これは、データアクセス層の最下層に位置します。
type MessageRepository struct{}

func (r *MessageRepository) Post(sender, message string) error {
	log.Printf("Sender: %s, Message: %s", sender, message)
	return nil
}

// MessageServiceIF は、メッセージ処理のビジネスロジックを定義するインターフェースです。
// これにより、異なる実装（本番用、モック用など）を簡単に切り替えることができます。
type MessageServiceIF interface {
	PostMessage(string, string) error
}

// MessageService は、実際のビジネスロジックを実装します。
// ここで依存性注入が行われます：MessageRepository への依存性が注入されます。
type MessageService struct {
	repository *MessageRepository // 依存性として注入されます
}

func (svc *MessageService) PostMessage(sender, message string) error {
	return svc.repository.Post(sender, message)
}

// NewService は、MessageService のインスタンスを作成します。
// ここで依存性注入が行われています：repository が外部から提供されます。
func NewService(repo *MessageRepository) *MessageService {
	return &MessageService{
		repository: repo,
	}
}

// MessageServiceMock は、テスト用のモックサービスです。
// これも MessageServiceIF を実装しているため、本番コードの代わりに使用できます。
type MessageServiceMock struct{}

func (svc *MessageServiceMock) PostMessage(sender, message string) error {
	log.Print("Write to Console (Mock)")
	return nil
}

func NewMockService() *MessageServiceMock {
	return &MessageServiceMock{}
}

// MessageController は、HTTP リクエストの処理やルーティングを担当します。
// ここでも依存性注入が使用されます：MessageServiceIF への依存性が注入されます。
type MessageController struct {
	Service MessageServiceIF // 依存性として注入されます   抽象として依存するようにする。
}

func (ctrl *MessageController) PostMessage(sender, message string) error {
	return ctrl.Service.PostMessage(sender, message)
}

// NewController は、MessageController のインスタンスを作成します。
// ここで依存性注入が行われています：service が外部から提供されます。
func NewController(service MessageServiceIF) *MessageController {
	return &MessageController{
		Service: service,
	}
}

func main() {
	// ここで、環境に応じて適切なサービスを選択します。
	// これにより、テスト環境と本番環境で異なる実装を使用できます。
	var srv MessageServiceIF
	if os.Getenv("DEBUG") != "" {
		srv = NewMockService() //詳細な実装を抽象(インターフェース)に依存させる
	} else {
		repo := &MessageRepository{}
		srv = NewService(repo) //詳細な実装を抽象(インターフェース)に依存させる
	}

	// Controller の作成時に、選択されたサービスを注入します。
	ctrl := NewController(srv)

	// 実際の使用例
	err := ctrl.PostMessage("TestSender", "Hello, World!")
	if err != nil {
		log.Printf("Error posting message: %v", err)
	}
}

/*
解説

MessageController と MessageService の関係:

従来の設計では、MessageController が直接 MessageServiceやMessageServiceMockに依存することが多いです。

このコードでは、MessageController は MessageServiceIF インターフェースに依存しています。

これにより、MessageController は具体的な実装（MessageService や MessageServiceMock）に依存せず、抽象（MessageServiceIF）に依存するようになります。


*/
