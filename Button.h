#pragma once
#include "Engine/GameObject.h"
class Button:public GameObject
{
protected:
	XMFLOAT3 position_;
	float x_,y_, scaleX_,scaleY_;
	float posX1_, posX2_, posY1_, posY2_;

public:
	Button(GameObject* parent);

	~Button();


	/// <summary>
	///�{�^���̃|�W�V��������͂��Ă��������B
	/// </summary>
	/// <param name="_position">[XMFLOAT3�^ (x, y, z)]</param>
	void SetPosition(XMFLOAT3 _position);

	/// <summary>
	/// �{�^���̉摜�T�C�Y��scale����͂��Ă��������B
	/// �X�P�[����ς��Ă��Ȃ��ꍇ�̓X�P�[��X,�X�P�[��Y��1�Ɠ��͂��Ă��������B
	/// </summary>
	/// <param name="_sizeX_">[float �c�̃T�C�Y]</param>
	/// <param name="_sizeY">[float���̃T�C�Y]</param>
	/// <param name="_scaleX_">[�X�P�[��X]</param>
	/// <param name="_scaleY_">[�X�P�[��Y]</param>
	void ButtonSize(float _sizeX, float _sizeY, float _scaleX, float _scaleY);

	/// <summary>
	/// �{�^���̈ʒu�ƃ}�E�X�̈ʒu�������ł����true���Ԃ���܂��B
	/// </summary>
	/// <param name="_mouse">[XMFLOAT3�^�@�}�E�X�̍��WX,Y,Z]</param>
	/// <returns></returns>
	bool ButtonIsHit(XMFLOAT3 _mouse);
};