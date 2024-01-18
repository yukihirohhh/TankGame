#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Ground.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"),hModel_(-1)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.2f);
	AddCollider(collision);

	hModel_ = Model::Load("Enemy.fbx");
	assert(hModel_ >= 0);
	Model::SetAnimFrame(hModel_,0,60,2);

	transform_.position_.x = (float)(rand() % 30);
	transform_.position_.z = (float)(rand() % 30);

}

void Enemy::Update()
{
	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHandle();

	RayCastData data;
	data.start = transform_.position_;
	data.start.y = 0;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);

	if (data.hit == true)
	{
		transform_.position_.y = -data.dist + 0.5f;
	}
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	KillMe();
}
