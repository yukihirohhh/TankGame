#pragma once
#include "Engine/GameObject.h"
class PlayScene :
    public GameObject
{
public:
	PlayScene(GameObject* parent);

	//�f�X�g���N�^
	~PlayScene();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

