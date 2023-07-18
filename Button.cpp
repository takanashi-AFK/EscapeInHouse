#include "Button.h"
#include "Engine/Input.h"
#include "Engine/Image.h"

Button::Button(GameObject* parent):GameObject(parent,"Button"), position_(0, 0, 0), x_(0), y_(0), scaleX_(0), scaleY_(0), posX1_(0),
	posX2_(0),posY1_(0),posY2_(0), mousePos_(0, 0, 0)
{
}

Button::~Button()
{
}

void Button::Initialize(){
	//file name
	std::string fileName[] = { "ButtonA_1.png","ButtonA_2.png" };
	for (int l = 0; l < MAX; l++) {
		hPict_[l] = Image::Load(fileName[l]);
	}


};
void Button::Update(){};

void Button::Draw()
{
	switch (state_)
	{
	case APict:
		Image::SetTransform(hPict_[APict], transform_);
		Image::Draw(hPict_[APict]);
		break;

	case BPict:
		Image::SetTransform(hPict_[BPict], transform_);
		Image::Draw(hPict_[BPict]);
	}



};
void Button::Release(){};

void Button::SetPosition(XMFLOAT3 _position)
{
	transform_.position_ =  _position;
}

void Button::ButtonSize(float _sizeX, float _sizeY, float _scaleX, float _scaleY)
{
	x_ = _sizeX;
	y_ = _sizeY;
	scaleX_ = _scaleX;
	scaleY_ = _scaleY;
	transform_.scale_.x = _scaleX;
	transform_.scale_.y = _scaleY;
}

bool Button::ButtonIsHit(XMFLOAT3 _mousePos)
{
	//posx1右、posx2左、posy1上、posy2下の順番で作成
	posX1_ = transform_.position_.x + (x_ * transform_.scale_.x) / 2; //右の初期化
	posX2_ = transform_.position_.x - (x_ * transform_.scale_.x) / 2; //左の初期化
	posY1_ = transform_.position_.y + (y_ * transform_.scale_.y) / 2; //上の初期化
	posY2_ = transform_.position_.y - (y_ * transform_.scale_.y) / 2; //下の初期化

	if ((_mousePos.x <= posX1_) &&
		(_mousePos.x >= posX2_) &&
		(_mousePos.y <= posY1_) &&
		(_mousePos.y >= posY2_))
	{
		if (state_ < 2) { state_ = 0; }
		state_++;
		return true;
	}
	

	else
	{ 
		return false;
	}
}	//画像切り替え処理をここに

