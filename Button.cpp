#include "Button.h"

Button::Button(GameObject* parent)
{
}

void Button::Bname(std::string _name, std::string _extension)
{
	name_ = _name + _extension ;
}

void Button::BSetPosition(XMFLOAT3 _position)
{
	position_ =  _position;
}

void Button::ButtonSize(float _sizeX, float _sizeY, float _scaleX, float _scaleY)
{
	Image = sizeX_;
	y = sizeY_;
	scale = scale_;
}

bool Button::ButtonIsHit(XMFLOAT3 mouse_)
{
	//posx1右、posx2左、posy1上、posy2下の順番で作成

	posX1 = position.x + (x * scale) / 2; //右の初期化
	posX2 = position.x - (x * scale) / 2; //左の初期化
	posY1 = position.y + (y * scale) / 2; //上の初期化
	posY2 = position.y - (y * scale) / 2; //下の初期化

	if ((mouse_.x <= posX1) &&
		(mouse_.x >= posX2) &&
		(mouse_.y <= posY1) &&
		(mouse_.y >= posY2)) 
		return true;

	else{ return false; }
}

//座標計算の関数
float Coordinate_Calculation() {};