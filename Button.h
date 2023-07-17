#pragma once
#include "Engine/GameObject.h"
class Button : public GameObject
{
private:
	XMFLOAT3 position_;
	float x_,y_, scaleX_,scaleY_;
	float posX1_, posX2_, posY1_, posY2_;

	XMFLOAT3 mousePos_;		//���̕ϐ��Ƀ}�E�X�̍��W�������܂��B
			//�}�E�X�̈ʒu��"�����I"�ɕ\�������Ă��܂��B

	enum STATES {				//�o��������G��ς��邽�߂Ɏg�p���܂�
		APict = 0,
		BPict,

		MAX
	};
	int hPict_[STATES::MAX];
	int state_;			//�X�e�[�^�X��ω�������Ƃ��Ɏg�p���܂�

	

public:

	Button(GameObject* parent);

	~Button();

	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Release()override;

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
	bool ButtonIsHit(XMFLOAT3 _mousePos);
};