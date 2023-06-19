#include "Button.h"

Button::Button(GameObject* parent)
{
}

Button::~Button()
{
	Release();
}

void Button::Bname(std::string _name, std::string _extension)
{
	name_ = _name + _extension;
}

void Button::BSetPosition(XMFLOAT3 _position)
{
	position_ =  _position;
}

void Button::ButtonSize(float _sizeX, float _sizeY, float _scaleX, float _scaleY)
{
	x_ = _sizeX;
	y_ = _sizeY;
	imageScale_.x = _scaleX;
	imageScale_.y = _scaleY;
}

bool Button::ButtonIsHit(XMFLOAT3 mouse_)
{
	//posx1�E�Aposx2���Aposy1��Aposy2���̏��Ԃō쐬

	posX1_ = position_.x + (x_ * scale_) / 2; //�E�̏�����
	posX2_ = position_.x - (x_ * scale_) / 2; //���̏�����
	posY1_ = position_.y + (y_ * scale_) / 2; //��̏�����
	posY2_ = position_.y - (y_ * scale_) / 2; //���̏�����

	if ((mouse_.x <= posX1_) &&
		(mouse_.x >= posX2_) &&
		(mouse_.y <= posY1_) &&
		(mouse_.y >= posY2_)) 
		return true;

	else{ return false; }
}

//���W�v�Z�̊֐�
//float Coordinate_Calculation() {};