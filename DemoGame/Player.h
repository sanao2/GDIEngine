#pragma once
#include "../GDIEngineLib/Object.h"

class Player :
    public Object
{
public:
	Player();
	~Player() override;
	void Update() override;
	void Render() override;
};

