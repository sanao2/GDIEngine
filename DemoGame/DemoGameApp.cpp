#include "framework.h"
#include "DemoGameApp.h"
#include "MenuScene.h"
#include "PlayScene.h"

#include "../GDIEngineLib/SceneManager.h"

void DemoGameApp::Initialize()
{
	__super::Initialize(); //  WinGameApp::Initialize();

	SceneManager::Get().CreateScene<MenuScene>(); // �� ����
	SceneManager::Get().CreateScene<PlayScene>(); // �� ����
	SceneManager::Get().ChangeScene(1); // �� ����
}

void DemoGameApp::Shutdown()
{
	__super::Shutdown(); //  WinGameApp::Shutdown();
}

void DemoGameApp::MessageProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	__super::MessageProc(hwnd, uMsg, wParam, lParam); // WM_DESTROY �⺻ó��

	// DemoGameApp������ ó���ϰ���� ����
	switch (uMsg)
	{
	case WM_CREATE:
		break;
	}
}
