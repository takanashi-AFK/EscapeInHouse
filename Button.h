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
	///ボタンのポジションを入力してください。
	/// </summary>
	/// <param name="_position">[XMFLOAT3型 (x, y, z)]</param>
	void SetPosition(XMFLOAT3 _position);

	/// <summary>
	/// ボタンの画像サイズとscaleを入力してください。
	/// スケールを変えていない場合はスケールX,スケールYに1と入力してください。
	/// </summary>
	/// <param name="_sizeX_">[float 縦のサイズ]</param>
	/// <param name="_sizeY">[float横のサイズ]</param>
	/// <param name="_scaleX_">[スケールX]</param>
	/// <param name="_scaleY_">[スケールY]</param>
	void ButtonSize(float _sizeX, float _sizeY, float _scaleX, float _scaleY);

	/// <summary>
	/// ボタンの位置とマウスの位置が同じであるとtrueが返されます。
	/// </summary>
	/// <param name="_mouse">[XMFLOAT3型　マウスの座標X,Y,Z]</param>
	/// <returns></returns>
	bool ButtonIsHit(XMFLOAT3 _mouse);
};