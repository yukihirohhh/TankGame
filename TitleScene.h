#pragma once
#include "Engine/GameObject.h"

class TitleScene :
    public GameObject
{
	int hPict_;
public:
	//�R���X�g���N�^
	TitleScene(GameObject* parent);

	//�f�X�g���N�^
	~TitleScene();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

