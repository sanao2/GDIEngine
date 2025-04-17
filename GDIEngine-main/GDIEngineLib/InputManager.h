#pragma once
#include "Singleton.h"

class InputManager : public Singleton<InputManager> 
{
	friend class Singleton<InputManager>; // �� Ŭ������ ������ ���� ���
private:
	InputManager() = default;			// �ٸ� ������ ���� ������ ȣ���� ����
	~InputManager() = default;

	HWND m_hWnd; // ������ �ڵ�
	POINT m_mouseClient;	// ���콺 ��ǥ
	SHORT m_prevState[256] = { 0 };
	SHORT m_currState[256] = { 0 };
public:
	void Init(HWND hWnd);

	void Update();

	bool IsKeyDown(int vKey);
	bool IsKeyPressed(int vKey);
	bool IsKeyReleased(int vKey);
};