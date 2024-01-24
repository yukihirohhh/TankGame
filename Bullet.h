#pragma once
#include "Engine/GameObject.h"
#include "PlayScene.h"

class Bullet :
    public GameObject
{
	int hModel_;
	float bulletSpeed_;//�e�ۂ̑���
	XMFLOAT3 moveDir_; //�����̃x�N�g��
	PlayScene* playscene_;
public:
	//�R���X�g���N�^
	Bullet(GameObject* parent);

	//�f�X�g���N�^
	~Bullet();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	void SetMoveDir(XMFLOAT3 _move) { moveDir_ = _move; }
	void SetSpeed(float _speed) { bulletSpeed_ = _speed; }
	void OnCollision(GameObject* pTarget) override;
};

