#include "Tank.h"
#include "Ground.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"

Tank::Tank(GameObject* parent)
	:GameObject(parent, "Tank"), hModel_(-1), speed_(0.1), front_ ({0,0,1,0}) 
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
		//‰ñ“]s—ñ‚ð‹‚ß‚é
		XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
		//ƒxƒNƒgƒ‹‚Ì‰ñ“]Œ‹‰Ê‚ð‹‚ß‚é
		XMVECTOR rotVec = XMVector3TransformCoord(front_, rotY);

		XMVECTOR m;
		m = speed_ * rotVec;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_)); //XMVECTOR‚É‡‚í‚¹‚é
		pos = pos + m; //pos = pos + speed * front_
		XMStoreFloat3(&(transform_.position_), pos);
	}
	if (Input::IsKey(DIK_S))
	{
		//‰ñ“]s—ñ‚ð‹‚ß‚é
		XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
		//ƒxƒNƒgƒ‹‚Ì‰ñ“]Œ‹‰Ê‚ð‹‚ß‚é
		XMVECTOR rotVec = XMVector3TransformCoord(front_, rotY);

		XMVECTOR m;
		m = speed_ * rotVec;
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
	

	/*Debug::Log("angle = ");
	Debug::Log(transform_.rotate_.y, true);*/

	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHandle();

	RayCastData data;
	data.start = transform_.position_;
	data.start.y = 0;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);

	if (data.hit == true)
	{
		transform_.position_.y = - data.dist;
	}
}

void Tank::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Tank::Release()
{
}
