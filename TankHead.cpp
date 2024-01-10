#include "TankHead.h"
#include "Ground.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

TankHead::TankHead(GameObject* parent)
	:GameObject(parent, "TankHead"), hModel_(-1), speed_(0.1), front_({ 0,0,1,0 })
{
}

TankHead::~TankHead()
{
}

void TankHead::Initialize()
{
	hModel_ = Model::Load("TankHead.fbx");
	assert(hModel_ >= 0);
}

void TankHead::Update()
{
	if (Input::IsKey(DIK_LEFT))
	{
		transform_.rotate_.y -= 1;
	}
	if (Input::IsKey(DIK_RIGHT))
	{
		transform_.rotate_.y += 1;
	}
}

void TankHead::Draw()
{
	//transform_‚Í©•ª@(TankHead)‚Ìƒƒ“ƒo•Ï”
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void TankHead::Release()
{
}
