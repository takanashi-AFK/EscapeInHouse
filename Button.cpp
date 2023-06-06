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
	//posx1�E�Aposx2���Aposy1��Aposy2���̏��Ԃō쐬

	posX1 = position.x + (x * scale) / 2; //�E�̏�����
	posX2 = position.x - (x * scale) / 2; //���̏�����
	posY1 = position.y + (y * scale) / 2; //��̏�����
	posY2 = position.y - (y * scale) / 2; //���̏�����

	if ((mouse_.x <= posX1) &&
		(mouse_.x >= posX2) &&
		(mouse_.y <= posY1) &&
		(mouse_.y >= posY2)) 
		return true;

	else{ return false; }
}

//���W�v�Z�̊֐�
float Coordinate_Calculation() {};