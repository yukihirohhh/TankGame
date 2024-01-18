#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel_(-1)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.2f);
	AddCollider(collision);

	hModel_ = Model::Load("Bullet.fbx");
	assert(hModel_ >= 0);
}

void Bullet::Update()
{
	

	transform_.position_.x = transform_.position_.x + moveDir_.x * bulletSpeed_;
	transform_.position_.y = transform_.position_.y + moveDir_.y * bulletSpeed_;
	transform_.position_.z = transform_.position_.z + moveDir_.z * bulletSpeed_;
	moveDir_.y -= 0.024;
	if (transform_.position_.y <= -10)
		KillMe();
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
	
}

void Bullet::Release()
{
}

void Bullet::OnCollision(GameObject* pTarget)
{
}
