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
	//コンストラクタ
	HUD(GameObject* parent);

	int hHUD_;
	int hNumbers_;
	//int hKinoko_;
	Transform tHud_;
	vector<Transform> tNumbers_;

	~HUD();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

