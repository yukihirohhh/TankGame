#pragma once
#include <vector>
#include "Engine/GameObject.h"
using namespace std;
using std::string;

class HUD :
    public GameObject
{
	string EnemyNumString();
public:
	//�R���X�g���N�^
	HUD(GameObject* parent);

	int hHUD_;
	int hNumbers_;
	//int hKinoko_;
	Transform tHud_;
	vector<Transform> tNumbers_;

	~HUD();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

