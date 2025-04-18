#include "framework.h"
#include "Player.h"
#include "../GDIEngineLib/RenderManager.h"
#include "../GDIEngineLib/InputManager.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::Update()
{
	if (InputManager::Get().IsKeyPressed(VK_SPACE))
	{
		OutputDebugStringA("Space Key Pressed\n");
	}
}

void Player::Render()
{
	RenderManager::Get().DrawImage();
}
