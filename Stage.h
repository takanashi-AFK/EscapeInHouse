#pragma once
#include "Engine/GameObject.h"

struct Rect4
{
	XMFLOAT3 TL, TR, BL, BR;
};

class Stage : public GameObject
{
private:
	int hModel_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Stage(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	/// <summary>
	/// ���f����4�p���擾����֐�
	/// </summary>
	/// <param name="_center">���f���̒������W�BGetPosition()</param>
	/// <param name="_widthSide">���f���̉��̕ӂ̒���(x)</param>
	/// <param name="_heightSide">���f���̏c�̕ӂ̒���(z)</param>
	/// <returns></returns>
	Rect4 GetRect(XMFLOAT3 _center, float _widthSide, float _heightSide);


	/// <summary>
	/// ���f��������Player�������Ă��邩�m�F����֐�
	/// </summary>
	/// <param name="_r">���f����4�_ �����Ă���GetRect()�ɂȂ�ł��傤</param>
	/// <returns>�����Ă��邩���Ȃ���(bool)</returns>
	bool IsInRect(XMFLOAT3 _pos,Rect4 _r);

};

