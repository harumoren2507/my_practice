package product

import (
	"unicode/utf8"
	"github.com/code-kakitai/go-pkg/ulid"
)


type Product struct {
	id	string
	ownerID	string
	name	string
	description	string
	price	int64
	stock	int
}

/*
オーナーは以上の情報を入力して商品を出品する。
*/

func newProduct(:
	id	string,
	ownerID	string,
	name	string,
	description	string,
	price	int64,
	stock	int,
) (*Product error) {
	//ownerIDのバリデーション
	if !ulid.IsValid(ownerID) {
		return nil, errDomain.NewError("オーナーIDが不正です。")
	}
	//名前のバリデーション
	if utf8.RuneCountInString(name) < nameLengthMin || utf8.RuneCountInString(name) > nameLengtMax {
		return nil, errdomain.NewError("商品説明の価が不正です。")
	}
	//価格のバリデーション
	if price < 1{
		return nil, errDomain.NewError("価格の価が不正です。")
	}
	//在庫数のバリデーション
	//在庫はないけど、商品は登録したい等あるため、0は許容する
	if stock < 0 {
		return nil, errDomain.NewError("在庫数の値が不正です。")
	}
	return &Product{
		id:	id,
		ownerID:	ownerID,
		name:	name,
		description:	description,
		price:	price,
		stock:	stock,
	}
}


