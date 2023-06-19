#pragma once
#include "Engine/GameObject.h"
class Button:public GameObject
{
private:
	std::string name_;
	XMFLOAT3 position_;						//�\���ʒu
	XMFLOAT3 imageSize_;					//�������̃T�C�Y
	XMFLOAT3 imageScale_;					//�摜�̊g�嗦�ł��B
	float x_,y_, scale_;					//�摜�̃T�C�Y�i�s�N�Z���j�Ƒ傫�����w��
	float posX1_, posX2_, posY1_, posY2_;	//�摜�̍��W�������܂�

public:
	Button(GameObject* parent);

	~Button();
	
	/// <summary>
	/// �{�^���̖��O�A�g���q�����
	/// </summary>
	/// <param name="_name">[string  �摜��]</param>
	/// <param name="_extension">[string  �g���q]</param>
	void Bname(std::string _name, std::string _extension);

	/// <summary>
	///�{�^���̃|�W�V��������͂��Ă��������B
	/// </summary>
	/// <param name="_position">[XMFLOAT3�^ (x, y, z)]</param>
	void BSetPosition(XMFLOAT3 _position);

	
	/// <summary>
	/// �{�^���̉摜�T�C�Y��scale����͂��Ă��������B
	/// �X�P�[����ς��Ă��Ȃ��ꍇ�̓X�P�[��X,�X�P�[��Y��1�Ɠ��͂��Ă��������B
	/// </summary>
	/// <param name="_sizeX_">[float �c�̃T�C�Y]</param>
	/// <param name="_sizeY">[float���̃T�C�Y<]/param>
	/// <param name="_scaleX_">[�X�P�[��X]</param>
	/// <param name="_scaleY_">[�X�P�[��Y]</param>
	void ButtonSize(float _sizeX, float _sizeY, float _scaleX, float _scaleY);

	//
	//���͒l�F�}�E�X�̈ʒu

	/// <summary>
	/// �{�^���̈ʒu�ƃ}�E�X�̈ʒu�������ł����true���Ԃ���܂��B
	/// </summary>
	/// <param name="_mouse">[XMFLOAT3�^�@�}�E�X�̍��WX,Y,Z]</param>
	/// <returns></returns>
	bool ButtonIsHit(XMFLOAT3 _mouse);
};

