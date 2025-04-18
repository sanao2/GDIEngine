#pragma once
#include "../GDIEngineLib/Scene.h"
class PlayScene :
    public Scene
{
public:
	PlayScene() = default;
	~PlayScene() = default;

	void Enter() override;
	void Exit() override;
	void Update() override;
};

