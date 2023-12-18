#include "Tank.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"

Tank::Tank(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
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
