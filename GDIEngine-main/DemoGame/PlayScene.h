#pragma once
#include "../GDIEngineLib/Scene.h"

class PlayScene :
    public Scene
{
	PlayScene() = default;
	~PlayScene() = default;

	void Enter() override;
	void Exit() override;
};

