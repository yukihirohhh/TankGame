#include "Tank.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"

Tank::Tank(GameObject* parent)
	:GameObject(parent, "Tank"), hModel_(-1), speed_(0.1), front_{ (0,0,1,0) }
{

}

Tank::~Tank()
{
}

void Tank::Initialize()
{
	hModel_ = Model::Load("TankBody.fbx");
	assert(hModel_ >= 0);
}

void Tank::Update()
{
	if (Input::IsKey(DIK_W))
	{
		//回転行列を求める
		XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
		//ベクトルの回転結果を求める
		XMVECTOR rotVec = XMVector3TransformCoord(front_, rotY);

		XMVECTOR m;
		m = speed_ * front_;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_)); //XMVECTORに合わせる
		pos = pos + m; //pos = pos + speed * front_
		XMStoreFloat3(&(transform_.position_), pos);
	}
	if (Input::IsKey(DIK_S))
	{
		XMVECTOR m;
		m = speed_ * front_;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
		pos = pos - m;
		XMStoreFloat3(&(transform_.position_), pos);
	}
	if (Input::IsKey(DIK_A))
	{
		transform_.rotate_.y -= 1;
	}
	if (Input::IsKey(DIK_D)) 
	{
		transform_.rotate_.y += 1;
	}
	

	Debug::Log("angle = ");
	Debug::Log(transform_.rotate_.y, true);
}

void Tank::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Tank::Release()
{
}
