#pragma once
#include "Engine/GameObject.h"
class Button : public GameObject
{
private:
	XMFLOAT3 position_;
	float x_,y_, scaleX_,scaleY_;
	float posX1_, posX2_, posY1_, posY2_;

	XMFLOAT3 mousePos_;		//この変数にマウスの座標を代入します。
			//マウスの位置を"試験的"に表示させています。

	enum STATES {				//出現させる絵を変えるために使用します
		APict = 0,
		BPict,

		MAX
	};
	int hPict_[STATES::MAX];
	int state_;			//ステータスを変化させるときに使用します

	

public:

	Button(GameObject* parent);

	~Button();

	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Release()override;

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
	bool ButtonIsHit(XMFLOAT3 _mousePos);
};