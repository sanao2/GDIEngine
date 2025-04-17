#pragma once
#include "../GDIEngineLib/Scene.h"

class MenuScene :
    public Scene
{
public:
	MenuScene() = default;
	~MenuScene() = default;

	void Enter() override;
	void Exit() override;
};

