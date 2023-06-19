#pragma once
#include "Engine/GameObject.h"
class Button:public GameObject
{
private:
	std::string name_;
	XMFLOAT3 position_;						//表示位置
	XMFLOAT3 imageSize_;					//がぞうのサイズ
	XMFLOAT3 imageScale_;					//画像の拡大率です。
	float x_,y_, scale_;					//画像のサイズ（ピクセル）と大きさを指定
	float posX1_, posX2_, posY1_, posY2_;	//画像の座標を示します

public:
	Button(GameObject* parent);

	~Button();
	
	/// <summary>
	/// ボタンの名前、拡張子を入力
	/// </summary>
	/// <param name="_name">[string  画像名]</param>
	/// <param name="_extension">[string  拡張子]</param>
	void Bname(std::string _name, std::string _extension);

	/// <summary>
	///ボタンのポジションを入力してください。
	/// </summary>
	/// <param name="_position">[XMFLOAT3型 (x, y, z)]</param>
	void BSetPosition(XMFLOAT3 _position);

	
	/// <summary>
	/// ボタンの画像サイズとscaleを入力してください。
	/// スケールを変えていない場合はスケールX,スケールYに1と入力してください。
	/// </summary>
	/// <param name="_sizeX_">[float 縦のサイズ]</param>
	/// <param name="_sizeY">[float横のサイズ<]/param>
	/// <param name="_scaleX_">[スケールX]</param>
	/// <param name="_scaleY_">[スケールY]</param>
	void ButtonSize(float _sizeX, float _sizeY, float _scaleX, float _scaleY);

	//
	//入力値：マウスの位置

	/// <summary>
	/// ボタンの位置とマウスの位置が同じであるとtrueが返されます。
	/// </summary>
	/// <param name="_mouse">[XMFLOAT3型　マウスの座標X,Y,Z]</param>
	/// <returns></returns>
	bool ButtonIsHit(XMFLOAT3 _mouse);
};

