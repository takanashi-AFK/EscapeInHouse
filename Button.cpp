#include "Button.h"

Button::Button(GameObject* parent):position_(0,0,0),x_(0),y_(0),scaleX_(0),scaleY_(0),posX1_(0),
	posX2_(0),posY1_(0),posY2_(0)
{
}

Button::~Button()
{
}


void Button::SetPosition(XMFLOAT3 _position)
{
	position_ =  _position;
}

void Button::ButtonSize(float _sizeX, float _sizeY, float _scaleX, float _scaleY)
{
	x_ = _sizeX;
	y_ = _sizeY;
	scaleX_ = _scaleX;
	scaleY_ = _scaleY;
}

bool Button::ButtonIsHit(XMFLOAT3 mouse_)
{
	//posx1右、posx2左、posy1上、posy2下の順番で作成

	posX1_ = position_.x + (x_ * scaleX_) / 2; //右の初期化
	posX2_ = position_.x - (x_ * scaleX_) / 2; //左の初期化
	posY1_ = position_.y + (y_ * scaleY_) / 2; //上の初期化
	posY2_ = position_.y - (y_ * scaleY_) / 2; //下の初期化

	if ((mouse_.x <= posX1_) &&
		(mouse_.x >= posX2_) &&
		(mouse_.y <= posY1_) &&
		(mouse_.y >= posY2_)) 
		return true;

	else{ return false; }
}