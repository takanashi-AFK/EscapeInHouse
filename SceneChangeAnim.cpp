#include "SceneChangeAnim.h"
#include "Engine/Image.h"
#define _USE_MATH_DEFINES
#include<math.h>
#include <iostream>
#include "Engine/Camera.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"

//�R���X�g���N�^
SceneChangeAnim::SceneChangeAnim(GameObject* parent)
	:GameObject(parent, "SceneChangeAnim"), hPict_(-1), fromVec(0, 0, 0), toVec(0, 0, 0), sinx(0.4)
{
	fade_ = false;
	move_ = true;
	
	//�����̗�1/2�ɂ��� ��΂ɂ����Ɗȗ����ł��邯�ǂ܂�
	mv = { 1.0f / 8.0f , 1.0f / 4.5f };
}

//�f�X�g���N�^
SceneChangeAnim::~SceneChangeAnim()
{
}

//������
void SceneChangeAnim::Initialize()
{
	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("light82sqrt2re.png");
	assert(hPict_ >= 0);
	//transform_.scale_ = XMFLOAT3(0.25f, 0.25f, 1.0f);
	transform_.position_.x = mv.x / 2.0f;
	//transform_.position_.y = mv.y / 2.0f;
	transform_.rotate_.z = 45.0f;
	transform_.scale_ = XMFLOAT3(1.0f, 1.0f, 1.0f);
}

//�X�V
void SceneChangeAnim::Update()
{
	if (animStats) {
		if (move_) {

			//�g�嗦�Ƃ߂�
			if (sinx > M_PI / 2) {
				sinx = M_PI / 2;
				move_ = false;
			}
			//�g�嗦������
			if (fade_) {
				//true ���܂�
				transform_.scale_.y = std::sin(sinx);
				//Debug::Log("scale:");
				//Debug::Log(transform_.scale_.y,true);

			}
			else {
				//false ������
				transform_.scale_.y = 1.0f - std::sin(sinx);
				//Debug::Log("scale:");
				//Debug::Log(transform_.scale_.y,true);
			}

			//�i�s�x�ӂ���
			sinx += 0.0625f;
		}
	}
	//Debug KAITEN FX �H�׃f�u
	/*
	if (1) {
		if (Input::IsKey(DIK_I)) {
			transform_.rotate_.x += 1.0f;
			Debug::Log(transform_.rotate_.x);
		}
		if (Input::IsKey(DIK_K)) {
			transform_.rotate_.x -= 1.0f;
			Debug::Log(transform_.rotate_.x);
		}
		if (Input::IsKey(DIK_J)) {
			transform_.rotate_.y += 1.0f;
			Debug::Log(transform_.rotate_.y);
		}
		if (Input::IsKey(DIK_L)) {
			transform_.rotate_.y -= 1.0f;
			Debug::Log(transform_.rotate_.y);
		}
		if (Input::IsKey(DIK_U)) {
			transform_.rotate_.z += 1.0f;
			Debug::Log(transform_.rotate_.z);
		}
		if (Input::IsKey(DIK_O)) {
			transform_.rotate_.z -= 1.0f;
			Debug::Log(transform_.rotate_.z);
		}

		if (Input::IsKeyDown(DIK_D)) {
			transform_.position_.x += mv.x;
			Debug::Log("x:");
			Debug::Log(transform_.position_.x,true);
		}
		if (Input::IsKeyDown(DIK_A)) {
			transform_.position_.x -= mv.x;
			Debug::Log("x:");
			Debug::Log(transform_.position_.x, true);
		}
		if (Input::IsKeyDown(DIK_W)) {
			transform_.position_.y += mv.y;
			Debug::Log("y:");
			Debug::Log(transform_.position_.y, true);
		}
		if (Input::IsKeyDown(DIK_S)) {
			transform_.position_.y -= mv.y;
			Debug::Log("y:");
			Debug::Log(transform_.position_.y, true);
		}
		if (Input::IsKey(DIK_Q)) {
			transform_.scale_.y += 0.01f;
			Debug::Log("sy:");
			Debug::Log(transform_.scale_.y, true);
		}
		if (Input::IsKey(DIK_E)) {
			transform_.scale_.y -= 0.01f;
			Debug::Log("sy:");
			Debug::Log(transform_.scale_.y, true);
		}

	}
	*/
	//debug camera �����Ŏg���\�������邩��c��
	/*
	if (1) {
		if (Input::IsKeyDown(DIK_1)) {
			xmf3_p.x++;
			Camera::SetPosition(xmf3_p);
		}
		if (Input::IsKeyDown(DIK_2)) {
			xmf3_p.x--;
			Camera::SetPosition(xmf3_p);
		}
		if (Input::IsKeyDown(DIK_3)) {
			xmf3_p.y++;
			Camera::SetPosition(xmf3_p);
		}
		if (Input::IsKeyDown(DIK_4)) {
			xmf3_p.y--;
			Camera::SetPosition(xmf3_p);
		}
		if (Input::IsKeyDown(DIK_5)) {
			xmf3_p.z++;
			Camera::SetPosition(xmf3_p);
		}
		if (Input::IsKeyDown(DIK_6)) {
			xmf3_p.z--;
			Camera::SetPosition(xmf3_p);
		}

		if (Input::IsKeyDown(DIK_7)) {
			xmf3_t.x++;
			Camera::SetTarget(xmf3_t);
		}
		if (Input::IsKeyDown(DIK_8)) {
			xmf3_t.x--;
			Camera::SetTarget(xmf3_t);
		}
		if (Input::IsKeyDown(DIK_9)) {
			xmf3_t.y++;
			Camera::SetTarget(xmf3_t);
		}
		if (Input::IsKeyDown(DIK_0)) {
			xmf3_t.y--;
			Camera::SetTarget(xmf3_t);
		}
		if (Input::IsKeyDown(DIK_MINUS)) {
			xmf3_t.z++;
			Camera::SetTarget(xmf3_t);
		}
		if (Input::IsKeyDown(DIK_CIRCUMFLEX)) {
			xmf3_t.z--;
			Camera::SetTarget(xmf3_t);
		}
	}
	*/
}

//�`��
void SceneChangeAnim::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void SceneChangeAnim::Release()
{
}

std::string SceneChangeAnim::getInfo() {
	//return " vecYSub: " + std::to_string(vecYSub) + " transPosY: " + std::to_string(transform_.position_.y) +
	//	" fromVecY: " + std::to_string(fromVec.y) + " toVecY: " + std::to_string(toVec.y);
	return " x: " + std::to_string(transform_.rotate_.z) + " y: " + std::to_string(transform_.rotate_.y) +
		" z: " + std::to_string(transform_.rotate_.z);
}

void SceneChangeAnim::ModifyRect(int x, int y, bool _fade)
{
	transform_.position_.x += mv.x * (-8+x );
	transform_.position_.y += mv.y * (5 - y -1);
	fade_ = _fade;
	if (_fade) {
		transform_.scale_.y = 0.0f;
	}
}
