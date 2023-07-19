#pragma once
#include "Engine/GameObject.h"
class SkyBox:public GameObject
{
	static SkyBox* instance;
	int hModel_;
public:
	/// <summary>
	/// �C���X�^���X���擾
	/// </summary>
	/// <returns>SkyBox�C���X�^���X</returns>
	static SkyBox& getInstance();
	
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~SkyBox() { delete instance; }

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
private:
	/// <summary>
	/// �R���X�g���N�^(private)
	/// </summary>
	SkyBox(GameObject* parent) : GameObject(parent,"SkyBox") {}

	/// <summary>
	/// �R�s�[���Z�q(private)
	/// </summary>
	/// <param name="">�Q�ƃ|�C���^</param>
	SkyBox(const SkyBox&) = delete;

	/// <summary>
	/// ������Z�q(private)
	/// </summary>
	/// <param name="">�Q�ƃ|�C���^</param>
	/// <returnsdelete></returns>
	SkyBox& operator=(const SkyBox&) = delete;
};