#pragma once
#include "Singleton.h"

class InputManager : public Singleton<InputManager>
{
public:
	InputManager() = default;
	~InputManager() = default;

	HWND m_hWnd; // ������ �ڵ�
	POINT m_mouseClient;	// ���콺 ��ǥ
	SHORT m_prevState[256] = { 0 };
	SHORT m_currState[256] = { 0 };
public:
	void Startup(HWND hWnd);
	void Shutdown() {};

	void Update();

	bool IsKeyDown(int vKey);
	bool IsKeyPressed(int vKey);
	bool IsKeyReleased(int vKey);
};