#pragma once
#include "Engine/GameObject.h"
class SkyBox:public GameObject
{
	static SkyBox* instance;
	int hModel_;
public:
	/// <summary>
	/// インスタンスを取得
	/// </summary>
	/// <returns>SkyBoxインスタンス</returns>
	static SkyBox& getInstance();
	
	/// <summary>
	/// デストラクタ
	/// </summary>
	~SkyBox() { delete instance; }

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
private:
	/// <summary>
	/// コンストラクタ(private)
	/// </summary>
	SkyBox(GameObject* parent) : GameObject(parent,"SkyBox") {}

	/// <summary>
	/// コピー演算子(private)
	/// </summary>
	/// <param name="">参照ポインタ</param>
	SkyBox(const SkyBox&) = delete;

	/// <summary>
	/// 代入演算子(private)
	/// </summary>
	/// <param name="">参照ポインタ</param>
	/// <returnsdelete></returns>
	SkyBox& operator=(const SkyBox&) = delete;
};